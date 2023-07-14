run: build
	./main
	@echo build done

build: main.c include.c
	gcc -c main.c include.c
	gcc -o main main.o include.o

clean:
	rm -f *.o main
	echo clean done