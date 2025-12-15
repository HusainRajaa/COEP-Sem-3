#include <stdio.h>
#include <stdlib.h>

// Node structure for the queue
typedef struct Node {
    int data;               // Data of the node
    struct Node* next;      // Pointer to the next node
} Node;

// Queue structure
typedef struct Queue {
    Node* front;            // Pointer to the front of the queue
    Node* rear;             // Pointer to the rear of the queue
    int size;               // Size of the queue
} Queue;

// Stack structure (uses two queues)
typedef struct Stack {
    Queue* q1;              // Primary queue
    Queue* q2;              // Auxiliary queue
} Stack;

// Function prototypes
Queue* createQueue();
void enqueue(Queue* q, int data);
int dequeue(Queue* q);
int isEmptyQueue(Queue* q);
Stack* createStack();
void push(Stack* stack, int data);
int pop(Stack* stack);
int top(Stack* stack);
int isEmptyStack(Stack* stack);

// Queue functions

// Create and initialize a new queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));  // Allocate memory for the queue
    q->front = q->rear = NULL;                // Initialize front and rear pointers to NULL
    q->size = 0;                              // Initialize size to 0
    return q;                                 // Return the created queue
}

// Add an element to the queue
void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));  // Create a new node
    newNode->data = data;                         // Set data
    newNode->next = NULL;                         // Set next pointer to NULL
    if (q->rear == NULL) {                        // If the queue is empty
        q->front = q->rear = newNode;             // Set both front and rear to the new node
    } else {
        q->rear->next = newNode;                  // Add new node at the end of the queue
        q->rear = newNode;                        // Update the rear pointer
    }
    q->size++;                                    // Increment queue size
}

// Remove an element from the queue
int dequeue(Queue* q) {
    if (q->front == NULL) {                       // If the queue is empty
        printf("Queue is empty\n");
        return -1;                                // Return -1 to indicate error
    }
    Node* temp = q->front;                        // Store the front node temporarily
    int data = temp->data;                        // Extract the data from the front node
    q->front = q->front->next;                    // Move front pointer to the next node
    if (q->front == NULL) {                       // If the queue becomes empty
        q->rear = NULL;                           // Set the rear pointer to NULL
    }
    free(temp);                                   // Free memory of the dequeued node
    q->size--;                                    // Decrement queue size
    return data;                                  // Return the dequeued data
}

// Check if the queue is empty
int isEmptyQueue(Queue* q) {
    return q->size == 0;                          // Return 1 if size is 0, else return 0
}

// Stack functions

// Create and initialize a new stack
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack)); // Allocate memory for the stack
    stack->q1 = createQueue();                    // Initialize q1
    stack->q2 = createQueue();                    // Initialize q2
    return stack;                                 // Return the created stack
}

// Push an element onto the stack
void push(Stack* stack, int data) {
    enqueue(stack->q1, data);                     // Add data to q1
}

// Pop the top element from the stack
int pop(Stack* stack) {
    if (isEmptyQueue(stack->q1)) {                // If q1 is empty, the stack is empty
        printf("Stack is empty\n");
        return -1;                                // Return -1 to indicate error
    }

    // Transfer all elements except the last from q1 to q2
    while (stack->q1->size > 1) {
        enqueue(stack->q2, dequeue(stack->q1));   // Move front element of q1 to q2
    }

    int top = dequeue(stack->q1);                 // Dequeue the last element (top of stack)

    // Swap q1 and q2
    Queue* temp = stack->q1;                      // Temporary variable for swapping
    stack->q1 = stack->q2;                        // q2 becomes the primary queue
    stack->q2 = temp;                             // q1 becomes the auxiliary queue

    return top;                                   // Return the popped element
}

// Get the top element of the stack without removing it
int top(Stack* stack) {
    if (isEmptyQueue(stack->q1)) {                // If q1 is empty, the stack is empty
        printf("Stack is empty\n");
        return -1;                                // Return -1 to indicate error
    }

    // Transfer all elements except the last from q1 to q2
    while (stack->q1->size > 1) {
        enqueue(stack->q2, dequeue(stack->q1));   // Move front element of q1 to q2
    }

    int top = dequeue(stack->q1);                 // Dequeue the last element (top of stack)
    enqueue(stack->q2, top);                      // Add it back to q2 to maintain state

    // Swap q1 and q2
    Queue* temp = stack->q1;                      // Temporary variable for swapping
    stack->q1 = stack->q2;                        // q2 becomes the primary queue
    stack->q2 = temp;                             // q1 becomes the auxiliary queue

    return top;                                   // Return the top element
}

// Check if the stack is empty
int isEmptyStack(Stack* stack) {
    return isEmptyQueue(stack->q1);               // Return 1 if q1 is empty, else return 0
}

// Main function to demonstrate the stack
int main() {
    Stack* stack = createStack();                 // Create a new stack

    push(stack, 10);                              // Push 10 onto the stack
    push(stack, 20);                              // Push 20 onto the stack
    push(stack, 30);                              // Push 30 onto the stack

    printf("Top element: %d\n", top(stack));      // Output the top element (30)
    printf("Popped element: %d\n", pop(stack));   // Pop and output the top element (30)
    printf("Top element: %d\n", top(stack));      // Output the new top element (20)
    printf("Popped element: %d\n", pop(stack));   // Pop and output the top element (20)
    printf("Stack is empty: %d\n", isEmptyStack(stack)); // Check if stack is empty (0)
    printf("Popped element: %d\n", pop(stack));   // Pop and output the top element (10)
    printf("Stack is empty: %d\n", isEmptyStack(stack)); // Check if stack is empty (1)

    return 0;
}

// Stack functions

// Create and initialize a new stack
Stack* createStack() {

//     QueueNode* rear;
// } Queue;

// // Function to initialize a queue
// void initQueue(Queue* q) {
//     q->front = q->rear = NULL;
// }

// // Function to check if a queue is empty
// int isEmpty(Queue* q) {
//     return q->front == NULL;
// }

// // Function to enqueue an element
// void enqueue(Queue* q, int x) {
//     QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
//     temp->data = x;
//     temp->next = NULL;
//     if (q->rear == NULL) {
//         q->front = q->rear = temp;
//         return;
//     }
//     q->rear->next = temp;
//     q->rear = temp;
// }

// // Function to dequeue an element
// int dequeue(Queue* q) {
//     if (isEmpty(q))
//         return -1;
//     QueueNode* temp = q->front;
//     int data = temp->data;
//     q->front = q->front->next;

//     if (q->front == NULL)
//         q->rear = NULL;

//     free(temp);
//     return data;
// }

// // Function to get the front element of the queue
// int front(Queue* q) {
//     if (isEmpty(q))
//         return -1;
//     return q->front->data;
// }

// // Stack structure using two queues
// typedef struct Stack {
//     Queue q1;
//     Queue q2;
// } Stack;

// // Function to initialize a stack
// void initStack(Stack* s) {
//     initQueue(&s->q1);
//     initQueue(&s->q2);
// }

// // Push function for the stack
// void push(Stack* s, int x) {
//     enqueue(&s->q2, x);

//     while (!isEmpty(&s->q1)) {
//         enqueue(&s->q2, dequeue(&s->q1));
//     }

//     // Swap q1 and q2
//     Queue temp = s->q1;
//     s->q1 = s->q2;
//     s->q2 = temp;
// }

// // Pop function for the stack
// void pop(Stack* s) {
//     if (isEmpty(&s->q1))
//         return;
//     dequeue(&s->q1);
// }

// // Top function for the stack
// int top(Stack* s) {
//     if (isEmpty(&s->q1))
//         return -1;
//     return front(&s->q1);
// }

// // Size function for the stack
// int size(Stack* s) {
//     QueueNode* temp = s->q1.front;
//     int count = 0;
//     while (temp) {
//         count++;
//         temp = temp->next;
//     }
//     return count;
// }

// // Driver code
// int main() {
//     Stack s;
//     initStack(&s);

//     push(&s, 1);
//     push(&s, 2);
//     push(&s, 3);

//     printf("current size: %d\n", size(&s));
//     printf("%d\n", top(&s));
//     pop(&s);
//     printf("%d\n", top(&s));
//     pop(&s);
//     printf("%d\n", top(&s));

//     printf("current size: %d\n", size(&s));

//     return 0;
// }
