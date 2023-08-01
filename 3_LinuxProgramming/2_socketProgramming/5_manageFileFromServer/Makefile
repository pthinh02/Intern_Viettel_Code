server: server.c
	gcc -c server.c
	gcc -o server server.o
	./server

client:	client.c
	gcc -c client.c
	gcc -o client client.c
	./client

clean:
	rm -f *.0 server client
	echo DONE

.PHONY: client server clean