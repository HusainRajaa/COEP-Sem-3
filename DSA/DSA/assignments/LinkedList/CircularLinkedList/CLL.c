#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int d;
    struct node *next;
} node;

typedef node *clist;

void init(clist *l){
    *l = NULL;
}

void insert_end(clist *l, int d){
    node *p = *l;
    node *nn = (node *)malloc(sizeof(node));
    if(nn){
        nn -> d = d;
        nn -> next = NULL;
    }
    else{
        return;
    }
    if(*l == NULL){
        *l = nn;
        nn -> next = *l;
    }
    else{
        while(p -> next != *l){
            p = p -> next;
        }
        p -> next = nn;
        nn -> next = *l;
    }
    return;
}

void insert_beg(clist *l, int d){
    node *p = *l;
    node *nn = (node *)malloc(sizeof(node));
    if(nn){
        nn -> d = d;
        nn -> next = NULL;
    }
    else{
        return;
    }
    if(*l == NULL){
        *l = nn;
        nn -> next = *l;
    }
    else{
        while (p->next != *l) {
            p = p->next;
        }
        p->next = nn;
        nn -> next = *l;  
        *l = nn;
    }
}

void delete_beg(clist *l){
    node *p, *q;
    if(*l == NULL){
        return;
    }
    p = *l;
    if(p -> next == *l){  
        free(p);
        *l = NULL;  
        return;
    }
    q = p;
    while(q -> next != *l){
        q = q -> next;
    }
    *l = p -> next;
    q -> next = *l;
    free(p);
}

void delete_end(clist *l){
    node *p, *q;
    if(*l == NULL){
        return;
    }
    p = *l;
    if (p->next == *l) {  
        free(p);
        *l = NULL;  
        return;
    }
    q = NULL;
    while(p -> next != *l){
        q = p;
        p = p -> next;
    }
    q -> next = *l;
    free(p);
}

void display(clist l){
    if(l == NULL){
        printf("List is empty\n");
        return;
    }
    node *p = l;
    do{
        printf("%d -> ", p -> d);
        p = p -> next;
    }while(p != l);
    printf("(back to head)\n");  // Indicate that the list is circular
}

// Insert a node in sorted manner in a circular linked list
void insert_sorted(clist *l, int data){
    node *p;
    node *nn = (node*)malloc(sizeof(node));
    if(nn){
        nn -> d = data;
        nn -> next = NULL;
    }
    else{
        return;
    }
    p = *l;
    if(*l == NULL){
        *l = nn;
        nn -> next = *l;
    }
    else if(p -> d > data){
        while(p -> next != *l){
            p = p -> next;
        }
        p -> next = nn;
        nn -> next = *l;
        *l = nn;
    }
    else{
        while(p -> next != *l && p -> next -> d < data){
            p = p -> next;
        }
        nn -> next = p -> next;
        p -> next = nn;
    }
}
int main(){
    clist l;
    init(&l);
    insert_sorted(&l, 9);
    insert_sorted(&l, 1);
    insert_sorted(&l, 5);
    insert_sorted(&l, 2);
    insert_sorted(&l, 7);
    insert_sorted(&l, 3);
    insert_sorted(&l, 8);
    insert_sorted(&l, 4);
    insert_sorted(&l, 6);
    insert_sorted(&l, 5);

    display(l);
    // insert_end(&l, 10);
    // insert_end(&l, 20);
    // insert_end(&l, 30);
    // display(l);

    // insert_beg(&l, 5);
    // display(l);

    // delete_beg(&l);
    // display(l);

    // delete_end(&l);
    // display(l);

    return 0;
}