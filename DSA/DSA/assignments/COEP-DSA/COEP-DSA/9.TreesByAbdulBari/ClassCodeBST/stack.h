// Define the structure for a stack node
typedef struct StackNode {
    struct Node* data;  // Pointer to tree node
    struct StackNode* next;
} StackNode;

// Define the structure for the stack
typedef struct Stack {
    StackNode* top;
} Stack;

void initStack(Stack* s);
void push(Stack* s, struct Node* node);
int isEmpty(Stack* s);
struct Node* pop(Stack* s);


