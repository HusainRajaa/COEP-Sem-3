typedef struct stack {
	int *arr;
	int size, top;
} stack;

void initStack(stack *s, int size);
int isStackEmpty(stack s);
void push(stack *s, int data);
int pop(stack *s);
