typedef struct node{
    int data;
    struct node *prev, *next;
}node;

typedef struct ASCII{
    node *front;
    node *rear;
}ASCII;

void init_ASCII(ASCII *l);
int isEmpty(ASCII l);
void ASCII_of(ASCII *l);
void traverse(ASCII *l);
void Destroy(ASCII *l);