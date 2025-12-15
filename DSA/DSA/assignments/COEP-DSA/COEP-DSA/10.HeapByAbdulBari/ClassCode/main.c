#include <stdio.h>
#include <stdlib.h>
#include"heap.h"
int main(){
	heap h1;
	init_heap(&h1,10);

	h1.h[0] = 10;
    h1.h[1] = 20;
    h1.h[2] = 15;
    h1.h[3] = 30;
    h1.h[4] = 25;
    h1.rear = 4;

	print_heap(h1);
	build_max_heap(&h1);

	// insert_heap(&h1,5);
	// insert_heap(&h1, 10);
	// insert_heap(&h1, 30);
	// insert_heap(&h1, 20);
	// insert_heap(&h1, 35);
	// insert_heap(&h1, 40);
	// insert_heap(&h1, 15);
	print_heap(h1);
	delete_max(&h1);
	print_heap(h1);
	heap_sort(&h1);
	return 0;
}
