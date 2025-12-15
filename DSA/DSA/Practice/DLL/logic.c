#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void init(list *l)
{
    l->front = NULL;
    l->rear = NULL;
}

int isempty(list l)
{
    if (l.front == NULL)
        return 1;
    return 0;
}

void insertright(list *l, int d)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->next = NULL;
    newnode->prev = NULL;
    newnode->data = d;
    if (!isempty(*l))
    {
        node *temp = l->rear;
        // while (temp->next)
        //     temp = temp->next;
        temp->next = newnode;
        newnode->prev = temp;
        l->rear = newnode;
    }
    else
    {
        l->front = newnode;
        l->rear = newnode;
    }
}

void printlistLR(list l)
{
    node *p;
    printf("Fwd: [ ");
    p = l.front;
    if (!p)
    {
        printf("]\n");
        return;
    }
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("]\n");
}

void printlistRL(list l)
{
    node *p;
    printf("BWD: [ ");
    p = l.rear;
    printf("%d ", p->data);
    if (!p)
    {
        printf("]\n");
        return;
    }
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->prev;
    }
    printf("]\n");
}

int length(list l)
{
    int count = 0;
    node *p = l.rear;
    while (p)
    {
        count++;
        p = p->prev;
    }
    return count;
}

void reverse(list *l)
{
    node *p1, *p2;
    int temp;
    p1 = l->front;
    p2 = l->rear;

    while (p1 != p2 && p2 != p1->prev)
    {
        temp = p1->data;
        p1->data = p2->data;
        p2->data = temp;
        p1 = p1->next;
        p2 = p2->prev;
    }
}

void SortedInsert(list *l, int x) {
    node *t = (node *)malloc(sizeof(node));
    node *temp;
    temp = l -> front;
    t->data = x;
    t->prev = NULL;
    t->next = NULL;

    // If the list is empty
    if (l -> front == NULL) {
        l -> front = l -> rear = t; // Both front and rear point to the new node
    }
    else {
        // Traverse to find the appropriate position
        while (temp && temp->data < x) {
            temp = temp->next;
        }

        // Inserting at the beginning of the list
        if (temp == l -> front) {
            t->next = l -> front;
            l -> front -> prev = t;
            l -> front = t;
        } 
        // Inserting at the end of the list
        else if (temp == NULL) {
            l -> rear -> next = t;
            t->prev = l -> rear;
            l -> rear = t;
        }
        // Inserting in the middle of the list
        else {
            t->prev = temp->prev;
            t->next = temp;
            temp->prev->next = t;
            temp->prev = t;
        }
    }
}
void removelist(list *l, int d)
{
    if (isempty(*l))
        return;
    node *p = l->front;
    while (p->data != d && p->next)
        p = p->next;
    if (p->data == d)
    {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        free(p);
    }
}

void freelist(list *l)
{
    node *p = l->front;
    node *q;
    while (p)
    {
        q = p;
        p = p->next;
        free(q);
    }
    l->front = NULL;
    l->rear = NULL;
}

void sort(list *l)
{
    node *p1 = l->front;
    node *temp = NULL;
    int x;
    if (!p1)
        return;
    node *p2 = p1->next;
    while (p2)
    {
        temp = p1;
        x = p2->data;
        while (temp && temp->data > x)
        {
            temp->next->data = temp->data;
            temp = temp->prev;
        }
        if (!temp)
            l->front->data = x;

        else
            temp->next->data = x;
        p2 = p2->next;
        p1 = p1->next;
    }
}

int search(list l, int d)
{
    node *p = l.front;
    while (p)
    {
        if (p->data == d)
            return 1;
        p = p->next;
    }
    return 0;
}

list listunion(const list l1, list l2)
{
    list l3;
    init(&l3);
    node *ptr1 = l1.front;
    while (ptr1)
    {
        insertright(&l3, ptr1->data);
        ptr1 = ptr1->next;
    }

    node *ptr2 = l2.front;
    while (ptr2)
    {
        if (!search(l3, ptr2->data))
        {
            insertright(&l3, ptr2->data);
        }
        ptr2 = ptr2->next;
    }

    return l3;
}

list intersection(list l1, list l2)
{
    list l3;
    init(&l3);
    int x;
    node *p = l1.front;
    while (p)
    {
        x = p->data;
        if (search(l2, x))
        {
            insertright(&l3, x);
        }
        p = p->next;
    }
    return l3;
}

void removeDuplicates(list *l) {
    if (isempty(*l)) return;

    node *current = l->front;
    node *temp, *duplicate;

    // Outer loop to pick each element one by one
    while (current && current->next) {
        temp = current->next;

        // Inner loop to check for duplicates
        while (temp) {
            // If a duplicate is found
            if (current->data == temp->data) {
                duplicate = temp;
                
                // Adjust the links
                if (duplicate->prev)
                    duplicate->prev->next = duplicate->next;
                if (duplicate->next)
                    duplicate->next->prev = duplicate->prev;

                // Update the rear pointer if the duplicate is the last element
                if (duplicate == l->rear)
                    l->rear = duplicate->prev;

                // Free the duplicate node
                node *nextTemp = duplicate->next;
                free(duplicate);
                temp = nextTemp;  // Move to the next node
            } else {
                temp = temp->next;
            }
        }
        current = current->next;
    }
}
