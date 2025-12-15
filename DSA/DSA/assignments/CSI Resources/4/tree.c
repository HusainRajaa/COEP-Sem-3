#include "tree.h"


node* initAVL(){return NULL;}

int isGreater(char* month1, char* month2){
    for(int k =0; k<10; k++){
        if(month1[k] > month2[k]) return 1;
        else if(month1[k] < month2[k]) return 0;
        else continue;
    }
}

int isLesser(char* month1, char* month2){
    for(int k =0; k<10; k++){
        if(month1[k] < month2[k]) return 1;
        else if(month1[k] > month2[k]) return 0;
        else continue;
    }
}

node* newNode(char* month){
    node* nn = (node*) malloc(sizeof(node));
    nn->parent = nn->left = nn->right = NULL;
    nn->month = (char*)malloc(10);
    nn->month = month;
    nn->bf = 0;
    return nn;
}

node* LL(node* imbalNode, node** root){
    node* pivot = imbalNode->left;
    node* br = pivot->right;
    
    pivot->parent = imbalNode->parent;
    imbalNode->parent = pivot;

    pivot->right = imbalNode;
    imbalNode->left = br;

    if(pivot->parent){
        if(isLesser(pivot->month, pivot->parent->month)) pivot->parent->left = pivot;
        else pivot->parent->right = pivot;
    }else{
        *root = pivot; //that means pivot is now the root
    }
    return pivot;
}

node* RR(node* imbalNode, node** root){
    node* pivot = imbalNode->right;
    node* b1 = pivot->left;

    pivot->parent = imbalNode->parent;
    imbalNode->parent = pivot;

    imbalNode->right = b1;
    pivot->left = imbalNode;

    if(pivot->parent){
        if(pivot->month > pivot->parent->month) pivot->parent->right = pivot;
        else pivot->parent->left = pivot;
    }
    else{
        *root = pivot;
    }
    return pivot;
}

int max(int a, int b){
    return (a>b) ? a:b;
}

int height(node* n){
    if(!n) return 0;
    return 1+ max(height(n->right), height(n->left));
}

int bf(node* n){
    if(!n) return 0;
    return height(n->left) - height(n->right);
}

void updateBf(node* n){
    if(!n) return;

    n->bf = bf(n);
    updateBf(n->parent);
}

node* getImbalNode(node* n){
    if(!n) return NULL;

    if(abs(n->bf)>1) return n;
    else getImbalNode(n->parent);
}

node* insertNode(node** root, char* month){
    
    node* nn = newNode(month);
    node* curr = *root;
    node* prev = NULL;

    if(!curr){
        *root = nn;
        return *root;
    }

    while(curr){
        prev = curr;
        if(isLesser(month, curr->month)) curr = curr->left;
        else curr = curr->right;
    }
    
    if(isLesser(month, prev->month)){
        prev->left = nn;
        nn->parent = prev;
    }
    else{
        prev->right = nn;
        nn->parent = prev;
    }

    updateBf(nn);
    node* imbalNode = getImbalNode(nn);
    if(!imbalNode) return nn;

    if(imbalNode->bf > 1 && isLesser(month, imbalNode->left->month)) LL(imbalNode, root);
    else if(imbalNode->bf < -1 && isGreater(month, imbalNode->right->month)) RR(imbalNode, root);
    else if(imbalNode->bf > 1 && isGreater(month, imbalNode->left->month)){
        RR(imbalNode->left, root);
        LL(imbalNode, root);
    }
    else{
        LL(imbalNode->right, root);
        RR(imbalNode, root);
    }
    updateBf(imbalNode);
}

void traverse(node* root){
    if(!root) return ;

    printf("month: %s  bf: %d\n", root->month, root->bf);
    traverse(root->left);
    traverse(root->right);
}

node* minNode(node* root){
    while(root->left){
        root = root->left;
    }
    return root;
}

node* removeNode(node* root, char* key){

    node* curr = root;
    node* prev = NULL;

    while(curr && (strcmp(curr->month, key)!=0)){
        prev = curr;
        if(isLesser(key, curr->month)) curr = curr->left;
        else curr = curr->right;
    }

    if(!curr){
        printf("DNE IN TREE");
        return root;
    }

    //max one child
    if(!curr->left || !curr->right){
        node* newCurr;

        if(!curr->left) newCurr = curr->right;
        else newCurr = curr->left;

        if(!prev) return newCurr; //node to be deleted is the root
        
        if(curr == prev->left) prev->left = newCurr;
        else prev->right = newCurr;
        free(curr);
        
    }
    //two children
    else{
        node* p = NULL;
        node* temp;

        //lowest node in right subtree
        temp = curr->right;
        while(temp->left){
            p  = temp;
            temp = temp->left;
        }

        if(p) p->left = temp->right; //if currNode has right node
        else curr->right = temp->right;

        curr->month = temp->month;
        free(temp);
    }




    return root;
}

//void inorder stack

// void inorder(node* root){
//     stack* s = newStack(100);
//     int done = false;
//     node* curr = root;

//     while(!done){
//         if(!curr) push(s, curr);
//         curr = curr->left;

//         else{
//             if(Empty(s)){
//                 curr = pop(s);
//                 printf("%d ", curr->data);
//                 curr = curr->right;
//             }
//             else done =1;
//         }

//     }
// }





