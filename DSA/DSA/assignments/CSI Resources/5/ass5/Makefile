app: main.o heap.o
	gcc -o app main.o heap.o
main.o: main.c heap.c heap.o
	gcc -c main.c -o main.o
heap.o: heap.c heap.h
	gcc -c heap.c -o heap.o
clean:
	rm *.o



