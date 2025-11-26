# Makefile

# default rule
a.out: main.o memory.o
	gcc main.o memory.o

# compile source files into object files
main.o: main.c memory.h
	gcc -c main.c

memory.o: memory.c memory.h
	gcc -c memory.c

# clean up build files
clean:
	rm -f *.o a.out
