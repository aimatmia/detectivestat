GCC = gcc -g

all: snoop.c
	$(GCC) snoop.c -o stat

clean:
	rm *~

run: all
	./stat
