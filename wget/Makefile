CC  = gcc
CXX = g++

INCLUDES =

CFLAGS   = -g -Wall $(INCLUDES)
CXXFLAGS = -g -Wall $(INCLUDES)

LDFLAGS = -g
LDLIBS = -lcrypt

wget:

wget.o:

.PHONY: valgrind
valgrind: list_files
	valgrind --leak-check=yes ./list_files

.PHONY: clean
clean:
	rm -f *.o *~ a.out core list_files

.PHONY: all
all: clean default
