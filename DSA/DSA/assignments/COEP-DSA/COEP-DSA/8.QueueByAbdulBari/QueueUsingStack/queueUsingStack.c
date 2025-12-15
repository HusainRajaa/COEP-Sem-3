#include <stdio.h>
#include <stdlib.h>

// Node structure for the stack
typedef struct Node {
    int data;               // Data of the node
    struct Node* next;      // Pointer to the next node
} Node;

// Stack structure
typedef struct Stack {
    Node* top;              // Pointer to the top of the stack
    int size;               // Size of the stack
} Stack;

// Queue structure (uses two stacks)
typedef struct Queue {
    Stack* s1;              // Primary stack
    Stack* s2;              // Auxiliary stack
} Queue;

// Function prototypes
Stack* createStack();
void pushStack(Stack* s, int data);
int popStack(Stack* s);
int isEmptyStack(Stack* s);
Queue* createQueue();
void enqueue(Queue* q, int data);
int dequeue(Queue* q);
int front(Queue* q);
int isEmptyQueue(Queue* q);

// Stack functions

// Create and initialize a new stack
Stack* createStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));  // Allocate memory for the stack
    s->top = NULL;                            // Initialize top pointer to NULL
    s->size = 0;                              // Initialize size to 0
    return s;                                 // Return the created stack
}

// Push an element onto the stack
void pushStack(Stack* s, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));  // Create a new node
    newNode->data = data;                         // Set data
    newNode->next = s->top;                       // Point the new node to the current top
    s->top = newNode;                             // Update the top pointer to the new node
    s->size++;                                    // Increment stack size
}

// Pop the top element from the stack
int popStack(Stack* s) {
    if (s->top == NULL) {                         // If the stack is empty
        printf("Stack is empty\n");
        return -1;                                // Return -1 to indicate error
    }
    Node* temp = s->top;                          // Store the top node temporarily
    int data = temp->data;                        // Extract the data from the top node
    s->top = s->top->next;                        // Move the top pointer to the next node
    free(temp);                                   // Free memory of the popped node
    s->size--;                                    // Decrement stack size
    return data;                                  // Return the popped data
}

// Check if the stack is empty
int isEmptyStack(Stack* s) {
    return s->size == 0;                          // Return 1 if size is 0, else return 0
}

// Queue functions

// Create and initialize a new queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));     // Allocate memory for the queue
    q->s1 = createStack();                        // Initialize s1
    q->s2 = createStack();                        // Initialize s2
    return q;                                     // Return the created queue
}

// Enqueue an element into the queue
void enqueue(Queue* q, int data) {
    pushStack(q->s1, data);                       // Push data onto stack s1
}

// Dequeue an element from the queue
int dequeue(Queue* q) {
    if (isEmptyStack(q->s2)) {                    // If s2 is empty
        while (!isEmptyStack(q->s1)) {            // Transfer all elements from s1 to s2
            pushStack(q->s2, popStack(q->s1));    // Move top of s1 to s2
        }
    }
    if (isEmptyStack(q->s2)) {                    // If s2 is still empty, queue is empty
        printf("Queue is empty\n");
        return -1;                                // Return -1 to indicate error
    }
    return popStack(q->s2);                       // Pop and return the top of s2 (front of queue)
}

// Get the front element of the queue without removing it
int front(Queue* q) {
    if (isEmptyStack(q->s2)) {                    // If s2 is empty
        while (!isEmptyStack(q->s1)) {            // Transfer all elements from s1 to s2
            pushStack(q->s2, popStack(q->s1));    // Move top of s1 to s2
        }
    }
    if (isEmptyStack(q->s2)) {                    // If s2 is still empty, queue is empty
        printf("Queue is empty\n");
        return -1;                                // Return -1 to indicate error
    }
    return q->s2->top->data;                      // Return the top of s2 (front of queue)
}

// Check if the queue is empty
int isEmptyQueue(Queue* q) {
    return isEmptyStack(q->s1) && isEmptyStack(q->s2);  // Return 1 if both s1 and s2 are empty
}

// Main function to demonstrate the queue
int main() {
    Queue* q = createQueue();                     // Create a new queue

    enqueue(q, 10);                               // Enqueue 10
    enqueue(q, 20);                               // Enqueue 20
    enqueue(q, 30);                               // Enqueue 30

    printf("Front element: %d\n", front(q));      // Output the front element (10)
    printf("Dequeued element: %d\n", dequeue(q)); // Dequeue and output the front element (10)
    printf("Front element: %d\n", front(q));      // Output the new front element (20)
    printf("Dequeued element: %d\n", dequeue(q)); // Dequeue and output the front element (20)
    printf("Queue is empty: %d\n", isEmptyQueue(q)); // Check if queue is empty (0)
    printf("Dequeued element: %d\n", dequeue(q)); // Dequeue and output the front element (30)
    printf("Queue is empty: %d\n", isEmptyQueue(q)); // Check if queue is empty (1)

    return 0;
}
