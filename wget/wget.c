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
	char *URL, *IP, *fname, *serverName, *fpath, GET[1024], rec[1024];
	struct sockaddr_in servaddr;
	struct hostent *he;
	unsigned short port = 80;

	if (argc != 3)
		fprintf(stderr, "Usage: ./wget <serverName> <URL>\n");

	serverName = argv[1];
	URL = argv[2];

	if (strstr(URL, ".com"))
		fpath = strstr(URL, ".com") + 4;
	else if (strstr(URL, ".net"))
		fpath = strstr(URL, ".net") + 4;
	else if (strstr(URL, ".org"))
		fpath = strstr(URL, ".org") + 4;
	else if (strstr(URL, ".gov"))
		fpath = strstr(URL, ".gov") + 4;

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

	if (connect(clntSock, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0)
		quit("connect() failed");

	snprintf(GET, sizeof(GET), "GET %s HTTP/1.0\r\nHost: %s:%d\r\n\r\n\r\n", fpath, serverName, port);

	if (send(clntSock, GET, strlen(GET), 0) != strlen(GET))
		quit("GET request failed");

	FILE *html = fopen(fname, "w");
	if (html == NULL)
		quit("fopen() failed");

	FILE *readLine = fdopen(clntSocket, "r"); /* It's easier to read data by lines */
	if (readLine == NULL)
		quit("fdopen() failed");

	fgets(rec, sizeof(rec), readLine);

	if (!strstr(rec, "200")) {
		fprintf(stderr, "%s\n", rec);
		fclose(readLine);
		fclose(html);
		close(clntSocket);
		quit("We did not receive a 200 response");
	}


	
	
	return 0;
}
