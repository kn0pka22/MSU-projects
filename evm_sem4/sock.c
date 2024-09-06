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
char s[100];
char ss[10000];
char e='E';
char*t=&e;
int n;
int r=0;
int rr=0;

// connect to 127.0.0.1 and port 1234
int sock = hx_connect_v4("exam.1434.ru", 63805);
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

// send and recv

send(sock, s, 100, 0 );
recv(sock, s, 88, 0);
printf("%s\n",s);

n=(s[22]-'0')*1000+(s[23]-'0')*100+(s[24]-'0')*10+(s[25]-'0');
printf("%d\n",n);

send(sock, t, 1, 0 );
while (r<6+n){

	rr=recv(sock, ss+r, 6+n, 0);
	printf("received %d bytes: \n",rr);
	r+=rr;
}


printf("%c%c%c%c%c%c\n",ss[0+n],ss[1+n],ss[2+n],ss[3+n],ss[4+n],ss[5+n]);


close(sock);
return 0;
}
