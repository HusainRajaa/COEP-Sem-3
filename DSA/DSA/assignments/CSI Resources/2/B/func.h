#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct treeNode{
    struct treeNode* left ,*right;
    int key;
}treeNode;

treeNode* newNode(int data){
    treeNode* nn = (treeNode*)malloc(sizeof(treeNode));
    nn->left = nn->right = NULL;
    nn->key = data;
    return nn;
}

treeNode* constructTree(int post[], int* postIndex, int key, int min, int max){
    if(*postIndex<0) return NULL;
    
    treeNode* root;
    
    root = newNode(key);
    *postIndex = *postIndex -1;

    if(*postIndex >=0){
        root->right = constructTree(post, postIndex, post[*postIndex], key, max);
        root->left = constructTree(post, postIndex, post[*postIndex], min, key);
    }
    
    return root;
}

treeNode* treeFromPostorder(int post[], int size){
    int postIndex = size -1;
    return constructTree(post, &postIndex, post[postIndex], INT_MIN, INT_MAX);
}

void printInorder(treeNode* root){
    if(!root) return;

    printInorder(root->left);
    printf("%d ", root->key);
    printInorder(root->right);

}

