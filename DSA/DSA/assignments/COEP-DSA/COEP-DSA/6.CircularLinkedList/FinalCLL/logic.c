#include <stdio.h>
#include <stdlib.h>
#include "CLL.h"

void init_CLL(clist *l) {
    *l = NULL;
}

int isEmpty(clist *l) {
    return (*l == NULL);
}

void insert_beg(clist *l, int d) {
    node *nn = (node *)malloc(sizeof(node));
    nn->d = d;
    if (isEmpty(l)) {
        *l = nn;
        nn->next = nn;
    } else {
        node *temp = *l;
        while (temp->next != *l) {
            temp = temp->next;
        }
        nn->next = *l;
        temp->next = nn;
        *l = nn;
    }
}

void insert_end(clist *l, int d) {
    node *nn = (node *)malloc(sizeof(node));
    nn->d = d;
    if (isEmpty(l)) {
        *l = nn;
        nn->next = nn;
    } else {
        node *temp = *l;
        while (temp->next != *l) {
            temp = temp->next;
        }
        temp->next = nn;
        nn->next = *l;
    }
}

void insert_pos(clist *l, int d, int pos) {
    if (pos == 1) {
        insert_beg(l, d);
    } else {
        node *nn = (node *)malloc(sizeof(node));
        nn->d = d;
        node *temp = *l;
        int i = 1;
        while (i < pos - 1 && temp->next != *l) {
            temp = temp->next;
            i++;
        }
        if (i == pos - 1) {
            nn->next = temp->next;
            temp->next = nn;
        } else {
            printf("Position is out of range\n");
            free(nn);
        }
    }
}

void remove_beg(clist *l) {
    if (isEmpty(l)) {
        printf("List is empty\n");
        return;
    }
    node *temp = *l;
    if ((*l)->next == *l) {
        *l = NULL;
    } else {
        node *last = *l;
        while (last->next != *l) {
            last = last->next;
        }
        *l = temp->next;
        last->next = *l;
    }
    free(temp);
}

void remove_end(clist *l) {
    if (isEmpty(l)) {
        printf("List is empty\n");
        return;
    }
    node *temp = *l;
    if ((*l)->next == *l) {
        *l = NULL;
    } else {
        node *prev = NULL;
        while (temp->next != *l) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = *l;
    }
    free(temp);
}

void remove_pos(clist *l, int pos) {
    if (isEmpty(l)) {
        printf("List is empty\n");
        return;
    }
    if (pos == 1) {
        remove_beg(l);
        return;
    } else {
        node *temp = *l;
        node *prev = NULL;
        int i = 1;
        while (i < pos && temp->next != *l) {
            prev = temp;
            temp = temp->next;
            i++;
        }
        if (i == pos) {
            prev->next = temp->next;
            free(temp);
        } else {
            printf("Position is out of range\n");
        }
    }
}

void sort(clist *l) {
    if (isEmpty(l)) {
        printf("List is empty\n");
        return;
    }
    node *p = *l, *q = NULL;
    int temp;
    int sorted = 0;
    while (!sorted) {
        sorted = 1;
        p = *l;
        do {
            q = p->next;
            if (q != *l && p->d > q->d) {
                temp = p->d;
                p->d = q->d;
                q->d = temp;
                sorted = 0;
            }
            p = p->next;
        } while (p->next != *l);
    }
}

void display(clist *l) {
    if (isEmpty(l)) {
        printf("List is empty\n");
        return;
    }
    node *p = *l;
    do {
        printf("%d -> ", p->d);
        p = p->next;
    } while (p != *l);
    printf("(back to start)\n");
}