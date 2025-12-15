#include"stack.h"
#include <stdio.h>
#include <stdlib.h>


// Initialize the stack
void initStack(Stack* s) {
    s->top = NULL;
    return;
}

// Push a tree node onto the stack
void push(Stack* s, struct Node* node) {
    StackNode* newStackNode = (StackNode*)malloc(sizeof(StackNode));
    newStackNode->data = node;
    newStackNode->next = s->top;
    s->top = newStackNode;
    return;
}

// Check if the stack is empty
int isEmpty(Stack* s) {
    return s->top == NULL;
}

// Pop a node from the stack
struct Node* pop(Stack* s) {
    if (isEmpty(s)) {
        return NULL;
    }
    StackNode* temp = s->top;
    struct Node* node = temp->data;
    s->top = s->top->next;
    free(temp);
    return node;
}


