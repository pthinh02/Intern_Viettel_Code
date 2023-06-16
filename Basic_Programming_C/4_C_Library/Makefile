run: build
	./main

build: main.c ./src/foo.c
	gcc -c -I inc main.c -o main.o
	gcc -c -I inc ./src/foo.c -o src/foo.o
	gcc -o main main.o ./src/foo.o

clean: 
	rm -f main */*.o
	@echo CLEAN DONE