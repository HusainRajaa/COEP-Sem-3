#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

typedef node* clist; // clist is now a pointer to a node

void init_CLL(clist* l) {
    *l = NULL;
    return;
}

void insert_beg(clist* l, int n) {
    node* nn = (node*)malloc(sizeof(node));
    if (nn) {
        nn->data = n;
        if (*l == NULL) {
            *l = nn;
            nn->next = nn;
        } else {
            nn->next = *l;
            node* rear = *l;
            while (rear->next != *l) {
                rear = rear->next;
            }
            rear->next = nn;
            *l = nn; // Update front
        }
    }
}

void insert_end(clist* l, int n) {
    node* nn = (node*)malloc(sizeof(node));
    nn->data = n;

    if (*l == NULL) {
        *l = nn;
        nn->next = nn;
    } else {
        node* rear = *l;
        while (rear->next != *l) {
            rear = rear->next;
        }
        rear->next = nn;
        nn->next = *l;
    }
}

int isempty(clist l) {
    return l == NULL;
}

int Length(clist l) {
    if (l == NULL) return 0;
    int count = 0;
    node* p = l;
    do {
        count++;
        p = p->next;
    } while (p != l);
    return count;
}

void insert_pos(clist* l, int pos, int n) {
    if (pos < 0 || pos > Length(*l)) return;

    node* nn = (node*)malloc(sizeof(node));
    nn->data = n;

    if (pos == 0) {
        insert_beg(l, n);
        return;
    } else {
        node* p = *l;
        for (int i = 0; i < pos - 1; i++) {
            p = p->next;
        }

        nn->next = p->next;
        p->next = nn;

        if (p == *l) { // If inserting at the end
            nn->next = *l;
        }
    }
}

void remove_beg(clist* l) {
    if (*l == NULL) return;

    node* p = *l;
    if (p->next == *l) {
        free(p);
        *l = NULL;
    } else {
        node* rear = *l;
        while (rear->next != *l) {
            rear = rear->next;
        }
        rear->next = p->next;
        *l = p->next;
        free(p);
    }
}

void remove_end(clist* l) {
    if (*l == NULL) return;

    node* p = *l;
    if (p->next == *l) {
        free(p);
        *l = NULL;
    } else {
        while (p->next->next != *l) {
            p = p->next;
        }
        free(p->next);
        p->next = *l;
    }
}

void remove_pos(clist* l, int pos) {
    if (*l == NULL) return;

    int len = Length(*l);
    if (pos < 0 || pos >= len) return;

    if (pos == 1) {
        remove_beg(l);
        return;
    }

    node* p = *l;
    for (int i = 1; i < pos - 1; i++) {
        p = p->next;
    }

    node* q = p->next;
    p->next = q->next;

    if (q == *l) { // Update front if needed
        *l = p->next;
    }

    free(q);
}

void sort(clist* l) {
    if (*l == NULL || (*l)->next == *l) return;

    int flag;
    node* p;
    node* end = NULL;

    do {
        flag = 0;
        p = *l;

        while (p->next != end && p->next != *l) {
            if (p->data > p->next->data) {
                int temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;

                flag = 1;
            }
            p = p->next;
        }
        end = p;

    } while (flag && end != *l);
}

void Display(clist l) {
    node* p;
    printf("[ ");
    p = l;
    if (!p) {
        printf("]\n");
        return;
    }
    while(p != l){
        printf("%d ", p->data);
        p = p->next;
    } 
    printf("]\n");
}