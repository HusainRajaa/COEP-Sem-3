typedef struct node{
    int data;
    struct node *next;
}node;

typedef node* list;

void init(list *head);
void insert_end(list *head, int d);
void insert_beg(list *head,int d);
void delete_beg(list *head);
void delete_end (list *head);
void traverse(list head);






