# Makefile

# default rule: build a.out
a.out: test.o memory.o
	gcc test.o memory.o -o a.out

# compile test.c
test.o: test.c memory.h
	gcc -c test.c

# compile memory.c
memory.o: memory.c memory.h
	gcc -c memory.c

# clean rule
clean:
	rm -f *.o a.out
