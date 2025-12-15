#define N 6

typedef struct queue {
	int q[N];
	int count, front, rear;
}queue; 

void qinit(queue *q);
void enqueue(queue *q, int d);
void dequeue(queue *q);
int isqempty(queue *q);
int isqfull(queue *q);
void printq(queue q);

