#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sockets.h>
#include <arpa/inet.h>

/* HTTP port is port 80 */

static void quit(char *msg) {
	perror(msg);
	exit(1);
}

int main(int argc, char **argv) {
	int clntSocket;
	char *URL, *IP, *fname, *serverName, GET[1024], rec[1024];
	struct sockaddr_in servaddr;
	struct hostent *he;
	unsigned short port = 80;

	if (argc != 3)
		fprintf(stderr, "Usage: ./wget <serverName> <URL>\n");

	serverName = argv[1];
	URL = argv[2];

	if ((he = gethostbyname(serverName)) == NULL)
		quit("gethostbyname() failed");

	IP = inet_ntoa(*(struct in_addr *)he->h_addr);
	fname = strchr(URL, '\0');
	while (*fname != '/')
		fname--;
	fname++;

	if ((clntSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
		quit("socket() failed");

	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr(IP);
	servaddr.sin_port = htons(port);


	
	
	return 0;
}
