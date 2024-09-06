#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sys/socket.h> // for socket
#include <sys/types.h> 
#include <netinet/in.h> // sockaddr_in 
#include <unistd.h> // for close
#include <arpa/inet.h> // for inet_aton
#include <netdb.h> // for gethostbyname

int hx_connect_v4(const char * ip, int port);
int hx_connect_v4(const char * ip, int port)
{
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


int main(void) {
  // connect to 127.0.0.1 and port 1234
	int sock = hx_connect_v4("h3llish.1434.ru", 23307);
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
	
	int res;
		
	char buf[500];
	char pin[11];
	char a[6];
	
	 
	res = send(sock, "coffee404\r\n", 11, 0);
	 
	res = recv(sock, buf, 500, 0);
	if(res < 3)
	{
		printf("Error, recv returned: %d\n", res);
		close(sock);
		return -1;	  
	}
	buf[res] = '\0';
	printf("%s\n", buf);
	
	a[0] = buf[2], a[1] = buf[3], a[2] = buf[4], a[3] = buf[5], a[4] = buf[6], a[5] = '\0';
	printf("%s\n\n", a);
	int port = atoi(a);
	
	close(sock);
	int sock1;
	sock1 = hx_connect_v4("h3llish.1434.ru", port);
	if (sock1 == -1 ) {
	    printf("Can't create socket\n");
	    return -1;
	} else if (sock1 == -2 ) {
	    printf("Can't connect to requested host\n");
	    return -1;
	} else if (sock1 == -3 ) {
	    printf("IP address or Domain name is wrong\n");
	    return -1;
	}
	printf("Connection 2 successfull\n");
	int k = 0, m = 0, n = 0;
	for(k=0; k < 10; k++)
	{
		for(m=0; m < 10; m++)
		{
			for(n=0; n < 10; n++)
			{
			  	res = send(sock1, "hello", 5, 0);
			  	res = recv(sock1, buf, 500, 0);
				if(res < 3)
				{
					printf("Error, recv returned: %d\n", res);
					close(sock1);
					return -1;	  
				}
			  	buf[res] = '\0';
				
				a[0] = buf[1], a[1] = buf[2], a[2] = buf[3], a[3] = '\0';
			  	printf("### = %s\n", a);
			  	int q = 0;
			  	int p = 0;
			  	p = atoi(a);
			  	q = p;
			  	p = q % 10 + q / 100 + ((q / 10) % 10);
			  	p = 100 - p;
			  	printf("j = %d\n", p);
			  	pin[0] = 'a', pin[1] = p / 10 + '0', pin[2] = p % 10 + '0', pin[3] = 'p', pin[4] = 'i', pin[5] = 'n';
	
			 	
			  	pin[6] = k + '0';
			  	pin[7] = m + '0';
			  	pin[8] = n + '0';
				
				printf("- %s -\n", pin);
			 		
				res = send(sock1, pin, 9, 0);
				res = recv(sock1, buf, 500, 0);
				if(res < 3)
				{
					printf("Error, recv returned: %d\n", res);
					close(sock1);
					return -1;	  
				}
				buf[res] = '\0';
				printf("-> %s\n\n", buf);
				if(buf[0] == 80)
					break;
			}
			if(buf[0] == 80)
					break;
		}
		if(buf[0] == 80)
					break;
	}
	buf[11] = '\0';
	printf("%s\n", buf);
	close(sock1);
		
		
	
	
 	close(sock);
 	return 0;
}

