#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct stack{
    int top;
    int size;
    int *a;
}stack;

void init(stack *s, int size){
    s -> a = (int *)malloc(sizeof(int) * size);
    s -> size = size;
    s -> top = -1;
    return;
}

int isFull(stack s){
    if(s.top == s.size - 1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(stack s){
    if(s.top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void pop(stack *s, int d){
    if(isEmpty(*s)){
        return;
    }
    s -> top--;
}

void push(stack *s, int d){
    if(isFull(*s)){
        return;
    }
    s -> top++;
    s -> a[s -> top] = d;
    return;
}

void peek(stack *s){
    
}