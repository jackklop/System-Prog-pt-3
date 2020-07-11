#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>



int main(){

  char info[1024]; // need to send msg to client
  struct sockaddr_in serverAddr;
  struct sockaddr_storage serverStorage;
  socklen_t addr_size;

  
  // Internet domain, Stream socket, Default protocol
  int serverSocket = socket(PF_INET, SOCK_STREAM, 0);
  
   serverAddr.sin_family = AF_INET;
   serverAddr.sin_port = htons(1234);
   serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

  // bind addr to socket
  bind(serverSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

  // max 20 connections, can change
  if(listen(serverSocket,20)==0)
    printf("Listening...\n");
  else
    printf("Listening Error\n");

  // Accepts new calls
  addr_size = sizeof(serverStorage);
  int newSocket = accept(serverSocket, (struct sockaddr *) &serverStorage, &addr_size);

  // send msg to client
  char str[] = "Whatsss Good";
  write (newSocket, str, sizeof(str));

  //close
  close(newSocket);
  close(serverSocket);
  return 0;
}