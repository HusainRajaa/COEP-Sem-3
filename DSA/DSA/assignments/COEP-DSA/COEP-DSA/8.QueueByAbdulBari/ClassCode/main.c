#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main() {
	queue q;
	qinit(&q);
	enqueue(&q,1);
	enqueue(&q,2);
	enqueue(&q,3);
	enqueue(&q,4);
	enqueue(&q,5);
	dequeue(&q);
	enqueue(&q,7);
	printq(q);
	return 0;
}



