#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

/*static int serviceConnect(const char * hostName)
{
	struct hostent *hostEntries;
	struct sockaddr_in serverAddress;
	char serverIP[INET_ADDRSTRLEN+1];

	if( (clientSocket = socket(PF_INET, SOCK_STREAM, 0)) < 0 )
	{
		perror("Unable to create socket");
		return -1;
	}

	/* Extract IP address */
	hostEntries = getaddrinfo(host);
	if(hostEntries == NULL)
	{
		perror("Unable to extract");
		return -1;
	}
}*/

int main(){
  
  struct sockaddr_in serverAddr;
  socklen_t addr_size;



// Internet domain, Stream socket, Default protocol
  int clientSocket = socket(PF_INET, SOCK_STREAM, 0);

  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(1234);
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

  // connect to server
  addr_size = sizeof(serverAddr);
  connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);

  // read msg from info from server
  char buffer[40];
  read(clientSocket, buffer, sizeof(buffer)-1);

  // print info the msg
  printf("Data received: %s\n",buffer);   

  //close
  close(clientSocket);
  return 0;
}