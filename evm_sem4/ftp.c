#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sys/socket.h> // for socket
#include <sys/types.h> 
#include <netinet/in.h> // sockaddr_in 
#include <unistd.h> // for close
#include <arpa/inet.h> // for inet_aton
#include <netdb.h> // for gethostbyname

int send_c (int sock, const char * command);
int send_c (int sock, const char * command) {
  int res;
  send(sock, "Dq1H", strlen("Dq1H"), 0);
  res = send(sock, command, strlen(command), 0);
  if(res < 0) {
    printf ("[ - ] Failed to send massege\n");
    close (sock);
    return -1;
    }
  res = send(sock, "\r\n", 2, 0);
  if(res <0) {
    printf("[ - ] Failed to send massege\n");
    close (sock);
    return -1;
    }
    printf("[+] Send command: %s\n", command);
    return 1;
    }
    
int recv_r (int sock, char *replay, int k);
int recv_r (int sock, char *replay, int k) {
  int res;
  
    res = recv(sock, replay, 10000-1, 0);  
  if(res < 0) {
    printf ("[ - ] Failed to send massege\n");
    close (sock);
    return -1;
    }
    replay[res] = 0;
    
    if (!(replay[0] >= '0') && (replay[0] <= '9')) {
      printf ("[ - ] Bad FTP replay\n");
      close (sock);
      return -2;
      }
      if (!(replay[1] >= '0') && (replay[1] <= '9')) {
        printf ("[ - ] Bad FTP replay\n");
        close (sock);
        return -2;
        }
     if (!(replay[2] >= '0') && (replay[2] <= '9')) {
      printf ("[ - ] Bad FTP replay\n");
      close (sock);
      return -2;
      }
         if((replay[0]-'0' !=2)&&(k==0)) {
      printf("[-] FTP replay with problem: %s\n", replay);
      close (sock);
      return (int)(replay[0]-'0');}
      /*если с 2 не начинается проверкаБ лучше в мейне делат*/
      printf("%s\n", replay);
      return (int)(replay[0]-'0');
      }



int send_ftp_command (int sock, const char * command, char *replay);
int send_ftp_command (int sock, const char * command, char *replay) {
  int res;
  res = send_c(sock, command);
  if (res<0) {
  return res;
  }
      return recv_r(sock, replay, );
      /*if(replay[0]='-' !=2) {
      printf("[-] FTP replay with problem: %n\n", replay);
      close (sock);
      return -2;
      если с 2 не начинается проверкаБ лучше в мейне делат*/
}





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
char *b;  
int res=0, port =0, sock1=0, sock=0; 
char data[5001];
char replay[10000];
FILE* f = fopen("file. txt", "w");
data[5000]= '\0';


  sock = hx_connect_v4("h3llish.1434.ru", 2129);
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
  printf("connect okey\n");
  
  
  if (recv_r(sock, replay)<= 0) return -1;
  
  send_ftp_command(sock, "USER anonymous", replay);
  send_ftp_command(sock, "TYPE I", replay);
  send_ftp_command(sock, "PASV", replay);*/
  b = replay;
  
  
  if (b[45]==',') 
{    //анализ порта
    port+= (((b[43]-'0')*10)+(b[44]-'0'))*256;
  if(b[48]==')') 
  {
    port+= ((b[46]-'0')*10)+(b[47]-'0');
  }
  else {
      port+= (((b[46]-'0')*100)+(b[47]-'0')*10+(b[48]-'0'));
      }
}
      else {
    port+= (((b[43]-'0')*100)+(b[44]-'0')*10+(b[45]-'0'))*256;
    if (b[49] == ')') {
    port += ((b[47]-'0')*10)+ (b[48]-'0');
    }
  else {
    port+= (((b[47]-'0')*100)+(b[48]-'0')*10+(b[49]-'0'));
    }
    }
    
    
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
    
    
    res = send_c(sock, "RETR nyTinw.dat");
  if (res<0){
    return res;
    }
    res = recv(sock1, data, 5000, 0);
  if (res<0)
   {
    printf("[-] Failed to receive data\n");
    close (sock);
    return -1;
    }
  close (sock1);
printf ("%s\n", data);
fprintf(f, "%s", data);
fclose(f);

 if (recv_r(sock, replay)<=0) return -1;
 if (send_ftp_command(sock, "QUIT", replay) !=2) return -1;
  */
  
  close(sock);
  //close(sock1);
  return 0;
}
