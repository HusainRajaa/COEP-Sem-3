#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

typedef struct avlNode{
    struct avlNode *parent, *left, *right;
    char* month;
    int bf;
}node;

node* initAVL();
int isGreater(char* month1, char* month2);
int isLesser(char* month1, char* month2);
node* newNode(char* month);
node* RR(node* imbalNode, node** root);
int max(int a, int b);
int height(node* n);
int bf(node* n);
void updateBf(node* n);
node* getImbalNode(node* n);
node* insertNode(node** root, char* month);
void traverse(node* root);
node* minNode(node* root);
node* removeNode(node* root, char* key);







