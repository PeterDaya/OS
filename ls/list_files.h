#ifndef __LIST_FILES_H__
#define __LIST_FILES_H__
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>

void quit(char *msg) {
	perror(msg);
	exit(1);
}

/* This program is similar to the command line program, "ls" */
void list_files(const char *path) {
	struct dirent *temp;
	DIR *dir;
	errno = 0;

	if ((dir = opendir(path)) == NULL)
		quit("opendir() returned NULL");
	
	/* We print the path to each filename and directory specified in the
	 * directory of interest. */
	while (1) {
		if ((temp = readdir(dir)) == NULL)
			break;

		if (strcmp(temp->d_name, ".") == 0 || strcmp(temp->d_name, "..") == 0)
			continue;

		if (strcmp(path, ".") != 0) 
			printf("%s/", path);
		
		printf("%s\n", temp->d_name);
	}

	if (errno != 0)
		quit("errno is not 0!");

	if (closedir(dir) < 0)
		quit("closedir()");
}
#endif
