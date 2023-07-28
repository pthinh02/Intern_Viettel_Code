server:
	gcc -c server.c
	gcc -o server server.o
	./server

client:
	gcc -c client.c
	gcc -o client client.o
	./client

clean:
	rm -f *.o server client

.PHONY: client server clean