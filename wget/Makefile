CC  = gcc
CXX = g++

INCLUDES =

CFLAGS   = -g -Wall $(INCLUDES)
CXXFLAGS = -g -Wall $(INCLUDES)

LDFLAGS = -g
LDLIBS =

wget:

wget.o:

.PHONY: valgrind
valgrind: wget
	valgrind --leak-check=yes ./wget www.gnu.org www.gnu.org/software/grub/manual/legacy/cat.html

.PHONY: run
run: wget
	./wget www.gnu.org www.gnu.org/software/grub/manual/legacy/cat.html

.PHONY: clean
clean:
	rm -f *.o *~ a.out core list_files wget *.html

.PHONY: all
all: clean default
