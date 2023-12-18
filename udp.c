#include<stdio.h>
#include<netinet/in.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netdb.h>
#include<arpa/inet.h>
int main()
{
struct sockaddr_in sock;
int fd,i,sa,j;
char str1[20];
int in;
fd = socket(PF_INET,SOCK_DGRAM,0);
sock.sin_family = AF_INET;
sock.sin_addr.s_addr = inet_addr("127.0.0.1");
sock.sin_port = htons(3000);
sa = sizeof(sock);
bind(fd,(struct sockaddr*)&sock,sizeof(sock));
while(1)
{
printf("\n\n\tWaiting for the data.....");
recvfrom(fd,str1,sizeof(str1),0,(struct sockaddr*)&sock,&sa);
if(strcmp(str1,"###") == 0)
{
printf("\n\n\tConnection closed.....\n");
break;
}
printf("\n\n\tData is : %s",str1);
in = atoi(str1);
j=1;
for(i=1;i<=in;i++)
{
j = j*i;
}
printf("\n\n\tFactorial of the received data is : %d",j);
}
close(fd);
return 0;
}
Udp_Client.c
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<netdb.h>
int fd;
int main()
{
struct sockaddr_in sock;
char data[20];
fd = socket(PF_INET,SOCK_DGRAM,0);
sock.sin_family = AF_INET;
sock.sin_addr.s_addr = inet_addr("127.0.0.1");
sock.sin_port = htons(3000);
while(1)
{
if(strcmp(data,"###") == 0)
{
printf("\n\tConnection closed....\n");
break;
}
printf("\n\tEnter the data to be transmit :");
 scanf("%s",data);
printf("\n");
 sendto(fd,data,sizeof(data),0,(struct sockaddr*)&sock,sizeof(sock));
printf("\n\tdata is : %s\n",data);
}
close(fd);
}

