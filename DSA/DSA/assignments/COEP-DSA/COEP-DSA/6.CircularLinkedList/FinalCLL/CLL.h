typedef struct node{
    int d;
    struct node *next;
} node;

typedef node* clist;

void init_CLL(clist *l);
int isEmpty(clist *l);
void insert_beg(clist *l, int d);
void insert_end(clist *l, int d);
void insert_pos(clist *l, int d, int pos);
void remove_beg(clist *l);
void remove_end(clist *l);
void remove_pos(clist *l, int pos);
void sort(clist *l);
void display(clist *l);