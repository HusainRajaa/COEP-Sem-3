#include "func.h"

int main(){
    int* bst = init_bst();
    bst = insert_bst(bst, 5);
    bst = insert_bst(bst, 6);
    bst = insert_bst(bst, 4);
    bst = insert_bst(bst, 3);
    bst = insert_bst(bst, 1);
    bst = insert_bst(bst, 8);
    bst = insert_bst(bst, 2);
    bst = insert_bst(bst, -1);
    bst = insert_bst(bst, 7);
    
    
    // for(int i =0; i<MAX; i++){
    //     printf("%d " , bst[i]);
    // }
    recursive_traverse(bst);
    int numNodes = num_nodes(bst);
    int completeTree = isComplete(bst, 0, numNodes);
    
    if(completeTree) printf("\nTree is complete");
    else printf("\nTree is not complete");

    return 0;
}

