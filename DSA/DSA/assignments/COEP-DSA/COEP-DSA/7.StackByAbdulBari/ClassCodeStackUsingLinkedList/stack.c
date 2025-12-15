#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void init(Stack* s){
	s->top = NULL;
	return;
}
void push(Stack* s, int d){
	Node *nn;
	
	nn = (Node *)malloc(sizeof(Node));
	if(nn){
		nn->data = d;
		nn->next = NULL;
	}
	else
		return;
		
	// Link the new node to the current top node
    	nn->next = s->top;

    	// Update the top to the new node
    	s->top = nn;

	return;
}


void pop(Stack* s){
 
      
        // Assign the current top to a temporary variable
        Node* p = s->top;

        // Update the top to the next node
        s->top = s->top->next;

        // Deallocate the memory of the old top node
        free(p);
    

}
int peek(Stack *s){
 
        return s->top->data;
    
    
}

void display(Stack s){
 	
    	printf("[ ");
    	Node *p = s.top;
    	while(p){
        	printf("%d ",p->data);
        	p=p->next;
    	}
    	printf("]\n");
    return;
}
