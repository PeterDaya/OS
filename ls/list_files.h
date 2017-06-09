#ifndef __LIST_FILES_H__
#define __LIST_FILES_H__
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>

void quit(char *msg) {
	perror(msg);
	exit(1);
}

void list_files(const char *path) {
	struct dirent *temp;
	DIR *dir;

	if ((dir = opendir(path)) == NULL)
		quit("opendir() returned NULL");

	while (1) {
		if ((temp = readdir(dir)) == NULL)
			break;

		errno = 0;

		if (strcmp(temp->d_name, ".") == 0 || strcmp(temp->d_name, "..") == 0)
			continue;

		if (strcmp(path, ".") 
	}
}


#endif
