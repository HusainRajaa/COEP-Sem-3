#include "func.h"

int main(){

    int post[] = {1, 7, 5, 50, 40, 10};

    treeNode* root = treeFromPostorder(post, sizeof(post)/sizeof(int));
    printInorder(root);
    
    return 0;
}