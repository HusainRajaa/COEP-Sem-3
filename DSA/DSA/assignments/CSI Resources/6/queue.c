#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "queue.h"

void initQueue(queue *q, int size) {
  q -> a = (int *)malloc(sizeof(int) * size);
  q -> size = size;
  q -> front = q -> rear = -1;
  return;
}

int isQueueFull(queue q) {
  if((q.front == q.rear + 1) || (q.front == 0 && q.rear == q.size - 1))
    return 1;
  return 0;
}

int isQueueEmpty(queue q) {
  if(q.front == -1)
    return 1;
  return 0;
}

void enqueue(queue *q, int n) {
  if(isQueueFull(*q))
    return;
  if(q -> front == -1)
    q -> front += 1;
  q -> rear = (q -> rear + 1) % q -> size;
  q -> a[q -> rear] = n;
  return;
}

int dequeue(queue *q) {
  int x = INT_MIN;
  if(isQueueEmpty(*q))
    return x;
  x = q -> a[q -> front];
  if(q -> front == q -> rear) {
      q -> front = q -> rear = -1;
      return x;
  }
  q -> front = (q -> front + 1) % q -> size;
  return x;
}
