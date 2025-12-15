typedef struct node{
    int data;
    struct node *lchild;
    struct node  *rchild;
}node;

typedef struct node* BST;

void init_BST(BST *t);
void insert_bstree(BST *t, int d);
BST createNode(int d);
BST recursive_insert(BST *t, int d);
void preorder(BST t);
void non_recursive_preorder(BST t);
