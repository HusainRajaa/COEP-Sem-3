#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct treeNode{
    int data;
    struct treeNode* left;
    struct treeNode* right;
}treeNode;

int* init_bst(){
    int* array = (int*)malloc(MAX*sizeof(int));
    for (int i = 0; i<MAX; i++){array[i] = '\0';}
    return array;
}

int* insert_bst(int bst[], int data){

    //if array is empty
    if(bst[0] == '\0') {
        bst[0] = data;
        return bst;
    }

    int i =0;   
    while(i<MAX){
        //data is less than the current node
        if(data<bst[i]){
            //if node is not empty
            if (bst[i*2+1] != '\0') {
                //go to the left child
                i = i*2 +1;
            }
            else{
                bst[i*2 + 1] = data;
                return bst;
            }
        
        }
        //data is greater than the current node
        else if(data>bst[i]){
            //if node is not empty
            if(bst[i*2+2]!='\0'){
                //go to the right child
                i = i*2 + 2;
            }
            //if node is empty
            else{
                bst[i*2 + 2] = data;
                return bst;
            }
        }
        
    }

}

void inorder(int bst[], int index)
{
    if (index >= MAX) return;

    inorder(bst, index * 2 + 1);
    if(bst[index]!='\0') printf("%d ", bst[index]);
    inorder(bst, index * 2 + 2);
}
void preorder(int bst[], int index)
{
    if (index >= MAX) return;

    if(bst[index]!='\0') printf("%d ", bst[index]);
    preorder(bst, index * 2 + 1);
    preorder(bst, index * 2 + 2);
}
void postorder(int bst[], int index)
{
    if (index >= MAX) return;

    postorder(bst, index * 2 + 1);
    postorder(bst, index * 2 + 2);
    if(bst[index]!='\0') printf("%d ", bst[index]);
}

void recursive_traverse(int bst[]){
    printf("\nPreorder: ");
    preorder(bst, 0);

    printf("\nInorder: ");
    inorder(bst, 0);

    printf("\nPostorder: ");
    postorder(bst, 0);
}
 
int num_nodes(int bst[]){
    int count = 0;
    for (int i = 0; i<MAX; i++){
        if(bst[i] == '\0') continue;
        else count++;
    }
    return count;
}

int isComplete(int* bst, int index, int numNodes){
    if(bst[0] == '\0') return 1;
    if(index>=numNodes) return 0;

    return (isComplete(&bst[2*index + 1], 2*index + 1, numNodes) && isComplete(&bst[2*index + 2], 2*index + 2, numNodes));
}