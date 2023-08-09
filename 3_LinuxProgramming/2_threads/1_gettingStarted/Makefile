run: build
	./main

build:
	gcc -c main.c
	gcc -pthread -o main main.o

clean:
	rm -r *.o main
	echo DONE