#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void init_DLL(DLL *l) {
    l->front = NULL;
    l->rear = NULL;
}

int isempty(DLL l) {
    return (l.front == NULL);
}

void insert_beg(DLL *l, int d) {
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = d;
    newnode->prev = NULL;
    newnode->next = l->front;

    if (isempty(*l)) {
        l->rear = newnode;
    } else {
        l->front->prev = newnode;
    }
    l->front = newnode;
}

void insert_end(DLL *l, int d) {
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = d;
    newnode->next = NULL;
    newnode->prev = l->rear;

    if (isempty(*l)) {
        l->front = newnode;
    } else {
        l->rear->next = newnode;
    }
    l->rear = newnode;
}

void insert_pos(DLL *l, int d, int pos) {
    if (pos == 0) {
        insert_beg(l, d);
        return;
    }

    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = d;
    
    node *temp = l->front;
    for (int i = 0; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        insert_end(l, d);
        return;
    }

    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next->prev = newnode;
    temp->next = newnode;
}

void remove_beg(DLL *l) {
    if (isempty(*l)) return;

    node *temp = l->front;
    if (l->front == l->rear) {
        l->front = l->rear = NULL;
    } else {
        l->front = l->front->next;
        l->front->prev = NULL;
    }
    free(temp);
}

void remove_end(DLL *l) {
    if (isempty(*l)) return;

    node *temp = l->rear;
    if (l->front == l->rear) {
        l->front = l->rear = NULL;
    } else {
        l->rear = l->rear->prev;
        l->rear->next = NULL;
    }
    free(temp);
}

void remove_pos(DLL *l, int pos) {
    if (pos == 0) {
        remove_beg(l);
        return;
    }

    node *temp = l->front;
    for (int i = 0; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) return;
    
    if (temp->next == NULL) {
        remove_end(l);
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}

void sort(DLL *l) {
    if (isempty(*l)) return;

    int swapped;
    node *temp;
    do {
        swapped = 0;
        temp = l->front;
        while (temp->next != NULL) {
            if (temp->data > temp->next->data) {
                int t = temp->data;
                temp->data = temp->next->data;
                temp->next->data = t;
                swapped = 1;
            }
            temp = temp->next;
        }
    } while (swapped);
}

void displayLR(DLL l) {
    node *temp = l.front;
    printf("Fwd: [ ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("]\n");
}

void displayRL(DLL l) {
    node *temp = l.rear;
    printf("BWD: [ ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("]\n");
}

int is_palindrome(DLL l) {
    node *start = l.front;
    node *end = l.rear;

    while (start != NULL && end != NULL && start != end && start->prev != end) {
        if (start->data != end->data) return 0;
        start = start->next;
        end = end->prev;
    }
    return 1;
}
void remove_duplicates(DLL *l) {
    if (isempty(*l)) return;

    node *current = l->front;
    while (current != NULL) {
        node *runner = current->next;
        while (runner != NULL) {
            if (runner->data == current->data) {
                node *temp = runner;
                runner = runner->next;

                if (temp->next != NULL) temp->next->prev = temp->prev;
                if (temp->prev != NULL) temp->prev->next = temp->next;

                if (temp == l->rear) l->rear = temp->prev;
                free(temp);
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}