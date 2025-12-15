#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED
#include <stdbool.h>
typedef struct node
{   char* name;
    int mis;
    struct node *left, *right, *parent;
}node;
typedef struct stack
{
    int size;
    int top;
    struct node** array;
}stack;
typedef struct node* bst;
#define MAX_SIZE 100
void initBST(struct node** node);
struct node* newNode(int mis,char* Name);
struct node* remove_Node(struct node* root, int mis);
struct node* insertNode(struct node* root, int mis,char* Name);
void postorder(struct node* root);
void Display_Level(struct node* root, int level);
void destroyTree(struct node* root);
bool search_BST(struct node* root, int key);


//STACK FUNCTIONS FOR POSTORDER

struct stack* createstack(int size);
int isEmpty(struct stack* stack);
void push(struct stack* stack, struct stack* node);
struct node* pop(struct stack* stack);
int isFull(struct stack* stack);
struct node* Max_Left(struct node* root);




#endif
