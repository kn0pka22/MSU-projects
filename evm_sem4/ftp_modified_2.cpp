#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <memory.h>
#include <sys/socket.h> // for socket
#include <sys/types.h>
#include <netinet/in.h> // sockaddr_in
#include <unistd.h> // for close
#include <arpa/inet.h> // for inet_aton
#include <netdb.h> // for gethostbyname
#include <fstream>

int get_port(char* buf){
	char* symb=buf;
	int num5=0,num6=0;
	while ((*symb)!='(') {
		symb++;
		//std::cout<<*symb<<std::endl;
	}
	for (int i=0;i<5;++i){
		while ((*symb)!=',') {
			symb++;
			//std::cout<<*symb<<std::endl;
		}
		symb+=1;
	}
	
	symb-=2;
	
	
	int d=1;
	while ((*symb)!=',') {
		num5+=(*symb-'0')*d;
		d*=10;
		symb-=1;
	}
	
	while ((*symb)!=')') {
		symb++;
		//std::cout<<*symb<<std::endl;
	}
	
	symb-=1;
	d=1;
	while ((*symb)!=',') {
		num6+=(*symb-'0')*d;
		symb-=1;
		d*=10;
	}


	int port=num5*256+num6;
	std::cout<<"port: "<<port<<std::endl;
	return port;

}




int hx_connect_v4(const char * ip, int port);
int hx_connect_v4(const char * ip, int port){
	int sock, res;
	struct sockaddr_in addr;
	struct hostent *host = NULL;

	// fill structure for input
	memset(&addr, 0, sizeof(addr));
	host = gethostbyname(ip);
	if (host == NULL) {
	return -3;
	}
	// Write resolved IP address of a server to the address structure
	memcpy(&(addr.sin_addr.s_addr), host->h_addr_list[0], 4);
	addr.sin_port = htons(port);
	addr.sin_family = AF_INET;

	// create socket for TCP connection
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0) {
	return -1;
	}

	// connect socket with the remote address
	res = connect(sock, (struct sockaddr*)&addr, sizeof(addr));
	if ( res < 0 ) {
	close(sock);
	return -2;
	}

	return sock;
}

int send_to_server(int& sock,const char* cmd, char* buf,int bufsize){
	int n=0;
	char cmd_new[1024];
	
	std::cout<<"-------------------------------"<<cmd<<"-------------------------------"<<std::endl;
	
	memset(cmd_new,0,sizeof(cmd_new));
	strcpy(cmd_new,cmd);
	strcat(cmd_new,"\r\n");
	
	n=send(sock, cmd_new, strlen(cmd_new), 0);
	if (abs(n)<strlen(cmd_new)){
		std::cout<<"smth went wrong"<<std::endl;
		return -1;
	}
	
	n=recv(sock, buf, bufsize, 0);
	if (n<=0){
		std::cout<<"smth went wrong"<<std::endl;
		return -2;
	}
	buf[n]='\0';
	std::cout<<"from server: "<<buf<<std::endl;
	
	
	return n;
}



int main(void) {
	// connect to 127.0.0.1 and port 1234
	int sock = hx_connect_v4("exam.1434.ru", 63821);

	if (sock == -1 ) {
	printf("Can't create socket\n");
	return -1;
	} else if (sock == -2 ) {
	printf("Can't connect to requested host\n");
	return -1;
	} else if (sock == -3 ) {
	printf("IP address or Domain name is wrong\n");
	return -1;
	}
	printf("Connection successfull\n");
	
	


	char buf[16384];
	recv(sock, buf, 16384, 0);
	buf[16383]='\0';
	printf("%s\n",buf);




	send_to_server(sock,"USER anonymous", buf,1024);
	send_to_server(sock,"TYPE I", buf,1024);
	send_to_server(sock,"PASV", buf,1024);
	
	

	
	
	//std::cout<<"num5 = "<<num5<<" and num6 = "<<num6<<std::endl;

	int port=get_port(buf);


	int sock_2 = hx_connect_v4("exam.1434.ru", port);
	if (sock_2 == -1 ) {
		printf("Can't create socket\n");
		return -1;
	} 
	else if (sock_2 == -2 ) {
		printf("Can't connect to requested host\n");
		return -1;
	} 
	else if (sock_2 == -3 ) {
		printf("IP address or Domain name is wrong\n");
		return -1;
	}
	printf("Connection successfull\n");


	send_to_server(sock,"RETR E6dmTJ.dat", buf,1024);
	send_to_server(sock,"TYPE I", buf,1024);
	


	int n=0;
	int r=0;
	std::ofstream File("E6dmTJ.txt");
	r=send_to_server(sock,"TYPE I", buf,1);
	while (r>0){
		std::cout<<buf;
		r=recv(sock_2, &buf, 1, 0);
		File << buf;
		n+=r;
	}

	std::cout<<"\nsize of file: "<<n<<std::endl;
	recv(sock, buf, 99, 0);
	std::cout<<"\n"<<buf;

	

  File.close();

	std::cout<<"\nTHE END!!!"<<std::endl;
	close(sock_2);
	close(sock);

	return 0;
}

