// Struct representing a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Struct to implement stack using a singly linked list
typedef struct Stack {
    Node* top;
}Stack;

void init(Stack* s);
void push(Stack* s, int d);
//int isEmpty(Stack *s);
void pop(Stack* s);
int peek(Stack *s);
void display(Stack s);
