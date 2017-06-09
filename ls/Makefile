CC  = gcc
CXX = g++

INCLUDES =

CFLAGS   = -g -Wall $(INCLUDES)
CXXFLAGS = -g -Wall $(INCLUDES)

LDFLAGS = -g
LDLIBS = -lcrypt

auth:

auth.o:

.PHONY: valgrind
valgrind: auth
	valgrind --leak-check=yes ./auth

.PHONY: clean
clean:
	rm -f *.o *~ a.out core sniff_tcp auth

.PHONY: all
all: clean default
