CC  = gcc
CXX = g++

INCLUDES =

CFLAGS   = -g -Wall $(INCLUDES)
CXXFLAGS = -g -Wall $(INCLUDES)

LDFLAGS = -g
LDLIBS = -lcrypt

list_files:

list_files.o: list_files.h

.PHONY: valgrind
valgrind: list_files
	valgrind --leak-check=yes ./list_files

.PHONY: clean
clean:
	rm -f *.o *~ a.out core list_files

.PHONY: all
all: clean default
