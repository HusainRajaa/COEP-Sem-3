typedef struct node{
    int data;
    struct node *next;
}node;

typedef node *SLL;

void init_SLL(SLL *head);
void append(SLL *head);
void traverse_SLL(SLL *head);
void insert_beg(SLL *head);
void insert_end(SLL *head);
void insert_pos(SLL *head, int pos);
int length(SLL *head);
void remove_beg(SLL *head);
void remove_end(SLL *head);
void remove_pos(SLL *head, int pos);