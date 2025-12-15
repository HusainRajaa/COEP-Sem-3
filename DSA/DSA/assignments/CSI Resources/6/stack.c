#include "stack.h"
#include <limits.h>
#include <stdlib.h>

void initStack(stack *s, int size) {
	s -> size = size;
	s -> arr = (int *)malloc(sizeof(int) * s -> size);
	s -> top = -1;
	return;
}

int isStackEmpty(stack s) {
	if(s.top == -1)
		return 1;
	else
		return 0;
}

int isStackFull(stack s) {
	if(s.top == s.size - 1)
		return 1;
	else
		return 0;
}

void push(stack *s, int data) {
	if(isStackFull(*s))
		return;
	s -> top += 1;
	s -> arr[s -> top] = data;
	return;
}

int pop(stack *s) {
	int x = INT_MIN;
	if(!isStackEmpty(*s)) {
		x = s -> arr[s -> top];
		s -> top -= 1;
	}
	return x;
}
