#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <string.h>
#include <limits.h>
#include <shadow.h>

#define _GNU_SOURCE
#define _XOPEN_SOURCE

static void quit(char *err) {
	perror(err);
	exit(1);
}

int main(int argc, char **argv) {
	struct passwd *pwd;
	struct spwd *shadow;
	char *user, *pass;
	long max;

	max = sysconf(_SC_LOGIN_NAME_MAX);
	if (max < 0)
		max = 256;

	user = malloc(max);
	if (user == NULL)
		quit("malloc() returned NULL");

	printf("Username: ");
	fgets(user, max, stdin);

	user[strlen(user) - 1] = '\0';

	if ((pwd = getpwnam(user)) == NULL || 
	(shadow = getspnam(user)) == NULL)
		quit("Password methods returned NULL");

	pass = getpass("Password: ");

	if (shadow != NULL)
		pwd->pw_passwd = shadow->sp_pwdp;
	
	char *encrypt;
	if ((encrypt = crypt(pass, pwd->pw_passwd)) == NULL)
		quit("crypt() returned NULL");

	char *temp = pass;

	while (*temp != '\0')
		*temp++ = '\0';
	
	if (strcmp(encrypt, pwd->pw_passwd) == 0)
		printf("User was succesfully authenticated: UID=%ld\n", (long)pwd->pw_uid);

	else {
		printf("An incorrect password was entered\n");
		quit("Incorrect password");
	}
	
	free(user);
	return 0;
}
