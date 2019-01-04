#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
 
int main() { 
  
    int Sock = 0, n = 0;
    char dataReceived[9999];
    struct sockaddr_in ipOfServer;
    memset(dataReceived, '0' ,sizeof(dataReceived));
  
  
    if( (Sock = socket(AF_INET, SOCK_STREAM, 0) )< 0 ){
        printf("No socket\n");
        return 1;
    }
 
    ipOfServer.sin_family = AF_INET;
    ipOfServer.sin_port = htons(2017);
    ipOfServer.sin_addr.s_addr = inet_addr("192.168.159.135");
 
    if(connect(Sock , (struct sockaddr *)&ipOfServer,sizeof(ipOfServer))<0){
        printf("Connection failed. \n");
        return 1;
    }
 
    while((n = read(Sock, dataReceived, sizeof(dataReceived)-1)) >0){
        dataReceived[n] = 0;
              if(fputs(dataReceived, stdout) == EOF){
                       printf("\n");
                       printf("Output error");
                 }
           }
 
  
    if( n < 0)
    {
      printf("\n");  
      printf("Input error \n");
    }
 
    return 0;
}
