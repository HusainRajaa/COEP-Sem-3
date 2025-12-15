#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "queue.h"

void qinit(queue *q){
	q->front= q->rear = q->count = 0;
	return;
}

void enqueue(queue *q, int d){
	q->q[q->rear] = d;
	q->rear = ((q->rear) + 1) % N;
	(q->count)++;
	return;
}


void dequeue(queue *q){
	q->front = ((q->front) + 1) % N;
	(q->count)--;
	return;

}
int isqempty(queue *q){
	return q->count == 0;
}

int isqfull(queue *q){
	return q->count == N;

}

void printq(queue q){
	int x;
	printf("[ ");
	for(x = q.front ; x != q.rear;  x = (x + 1)  % N){
	printf("%d ", q.q[x]);
	}
	printf("] \n");

}

