
#include "Bst.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void initBST(struct node** node){
    *node = NULL;
    return;
}

struct node* newNode(int mis,char* Name){
    struct node* temp = malloc(sizeof(struct node));
    temp->name= strdup(Name);
    temp->mis = mis;
    temp->left = NULL;
    temp->right = NULL;
    temp->parent = NULL;
    return temp;
}



struct node* insertNode(struct node* root, int mis, char* Name){
    if(root == NULL)
        return newNode(mis,Name);

    if(mis < root->mis){
        struct node* l = insertNode(root->left, mis,Name);
        root->left = l;
        l->parent = root;
    }
    else if(mis > root->mis){
        struct node* r = insertNode(root->right, mis,Name);
        root->right = r;
        r->parent = root;
    }

    return root;
}

struct node* remove_Node(struct node* root, int mis){
    if(root == NULL)
        return root;

    if(mis < root->mis)
        root->left = remove_Node(root->left, mis);
    else if(mis > root->mis)
        root->right = remove_Node(root->right, mis);
    else{
        if(root->left == NULL){
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = Max_Left(root->left);

        root->mis = temp->mis;

        root->left = remove_Node(root->left, temp->mis);
    }
    return root;
}

bool search_BST(struct node* root, int key){
    if(root == NULL)
        return false;

    struct node* curr;
     curr= root;
    while(curr){
        if(curr->mis == key)
            return true;
        if(curr->mis > key)
            curr = curr->left;
        else
            curr = curr->right;
    }
    return false;
}


void postorder(struct node* root){
    if(root == NULL)
        return;
    struct stack* s1 = createstack(MAX_SIZE);
    struct stack* s2 = createstack(MAX_SIZE);

    push(s1, root);
    struct node* node;

    while(!isEmpty(s1)){
        node = pop(s1);
        push(s2, node);

        if(node->left)
            push(s1, node->left);
        if(node->right)
            push(s1,node->right);
    }
    while(!isEmpty(s2))
    {
        node = pop(s2);
        printf("%d %s ", node->mis, node->name);
    }
}





void Display_Level(struct node* root, int level){
    if(root == NULL)
        return;
    if(level == 1)
    {   printf("%d ", root->mis);
        printf("%s",root->name);}
    else if(level > 1){
        Display_Level(root->left,level - 1);
        Display_Level(root->right, level - 1);
    }
}


void destroyTree(struct node* root){
    if (root == NULL) return;

    destroyTree(root->left);
    destroyTree(root->right);

    printf("\n Deleting node: %i", root->mis);
    free(root);
}




struct stack* createstack(int size){
    struct stack* Stack = malloc(sizeof(struct stack));
    Stack->size = size;
    Stack->top = -1;
    Stack->array = (struct stack*)malloc(Stack->size * sizeof(struct node));
    return Stack;
}


struct node* Max_Left(struct node* root){
    struct node* current = root;

    while(current != NULL && current->right != NULL)
        current = current->right;

    return current;
}

int isFull(struct stack* stack){
    return stack->top == stack->size - 1;
}


int isEmpty(struct stack* stack){
    return stack->top == -1;
}


void push(struct stack* stack, struct stack* node){
    if(isFull(stack))
        return;
    stack->array[++stack->top] = node;
}


struct node* pop(struct stack* stack){
    if(isEmpty(stack))
        return NULL;
    return stack->array[stack->top--];
}



