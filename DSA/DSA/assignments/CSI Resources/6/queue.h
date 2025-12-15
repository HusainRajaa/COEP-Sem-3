typedef struct queue {
	int *a;
	int front, rear, size;
} queue;

void initQueue(queue *q, int size);
int isQueueEmpty(queue q);
int isQueueFull(queue q);
void enqueue(queue *q, int n);
int dequeue(queue *q);
