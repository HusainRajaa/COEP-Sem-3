#include "tree.h"


int main(){

    node* root = initAVL();

    insertNode(&root, "dec");
    insertNode(&root, "jan");
    insertNode(&root, "apr");
    insertNode(&root, "mar");
    insertNode(&root, "july");
    insertNode(&root, "august");

    traverse(root);

    removeNode(root, "dec");

    printf("\n\n");
    traverse(root);

    return 0;

}