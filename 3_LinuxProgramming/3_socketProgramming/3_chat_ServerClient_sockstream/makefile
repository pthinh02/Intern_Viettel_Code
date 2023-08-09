client:
	gcc client.c -o client 
	./client

server:
	gcc -c server.c -o server.o
	gcc server.o -o server
	./server

clean:
	rm -f *.o server client
	echo DONE

.PHONY: client server clean