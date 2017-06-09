#include "list_files.h"

int main(int argc, char **argv) {
	if (argc == 1)
		list_files(".");

	else {
		argv++;
		for (; *argv; argv++)
			list_files(*argv);
	}
	return 0;
}
