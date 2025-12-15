typedef struct node{
    int data;
    struct node *next, *prev;
}node;

typedef struct list{
    node  *front, *rear;
}list;

void init(list*);
int isempty(list);
void insertright(list*, int);
void printlistLR(list );
void printlistRL(list );
int length(list );
void reverse(list *l);
void SortedInsert(list *,int);
void removelist(list*, int);
void freelist(list*);
void sort(list*);
int search(list l, int);
list listunion(const list, list);
void removeDuplicates(list *l);
list intersection(list l1, list l2);