#include"bst.h"
#include"stack.h"
#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

void init_BST(BST *t){
    *t=NULL;
    return;
}

void insert_bstree(BST *t, int d){
    node *nn=(BST)malloc(sizeof(node));
    nn->data=d;
    nn->lchild=nn->rchild=NULL;
    if(*t==NULL){
        *t=nn;
        return;
    }
    node *p=*t,*q=NULL;
    while(p){
        q=p;
        if(p->data > d)
            p=p->lchild;
        else if(p->data < d)
            p=p->rchild;
        else{
            free(nn);
            return;
        }
    }
    if(q->data > d)
        q->lchild=nn;
    else if(q->data < d)
        q->rchild=nn;
    return;

}

BST createNode(int d){
	struct node *nn=(BST)malloc(sizeof(node));
    	nn->data=d;
    	nn->lchild=nn->rchild=NULL;
}

BST recursive_insert(BST *t, int d){
	
    if(*t==NULL){
        return createNode(d);
    }
    node *p=*t;
    if(p->data == d)
    	return p;
    	
    if(p->data > d)
    	p->lchild = recursive_insert(p->lchild, d);
    else if(p->data < d)
    	p->rchild = recursive_insert(p->rchild,d);
    return p;

}
void preorder(BST t){
    if(!t)
        return ;
    printf("%d ",t->data);
    preorder(t->lchild);
    preorder(t->rchild);
    
}

void non_recursive_preorder(BST t){
	
    if (t == NULL) {
        return;
    }
    node *p = t;
    Stack s;
    initStack(&s);
    while (p || !isEmpty(&s)) {
    	if(p){
    		printf("%d->",p->data);
    		push(&s,p);
    		p=p->lchild;
    	}
    	else{
    		p = pop(&s);
    		p = p->rchild;
    	}      
}
}

node* delete_bstree(BST *t, int d) {
    // If the tree is empty, the element is not found.
    if (*t == NULL) {
        printf("Element %d not found!\n", d);
        return *t;
    }
    node *p = *t;
    // Case 1: Traverse the left subtree if the target value is smaller than the current node's data.
    if (d < p->data) {
        p->lchild = delete_bstree(&(p->lchild), d);
    }
    // Case 2: Traverse the right subtree if the target value is greater than the current node's data.
    else if (d > p->data) {
        p->rchild = delete_bstree(&(p->rchild), d);
    }
    // Case 3: Node to be deleted is found.
    else {
        // Sub-case 3a: Node has no children (it's a leaf node).
        if (p->lchild == NULL && p->rchild == NULL) {
            free(p); // Free the memory for the node.
            return NULL; // Return NULL to remove the node.
        }
        // Sub-case 3b: Node has only one child (right child exists).
        if (p->lchild == NULL) {
            node *temp = p->rchild; // Store the right child temporarily.
            free(p); // Free the current node.
            return temp; // Return the right child to connect it to the parent.
        }
        // Sub-case 3c: Node has only one child (left child exists).
        if (p->rchild == NULL) {
            node *temp = p->lchild; // Store the left child temporarily.
            free(p); // Free the current node.
            return temp; // Return the left child to connect it to the parent.
        }
        // Sub-case 3d: Node has two children.
        // Find the in-order successor (smallest node in the right subtree).
        node *successor = p->rchild;
        while (successor->lchild != NULL) {
            successor = successor->lchild; // Keep moving left to find the smallest node.
        }
        // Replace the current node's data with the successor's data.
        p->data = successor->data;
        // Delete the in-order successor (recursive call to delete in the right subtree).
        p->rchild = delete_bstree(&(p->rchild), successor->data);
    }
    return p; // Return the updated subtree root after deletion.
}