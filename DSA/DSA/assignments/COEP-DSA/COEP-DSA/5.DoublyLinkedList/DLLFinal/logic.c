#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void init_DLL(DLL *l){
    l->head = NULL;
    l->tail = NULL;
    return;
}

int isempty(DLL l) {
    return (l.head == NULL);
}

void insert_right(DLL *l, int d){
    node *newnode = (node *)malloc(sizeof(node));
    if(newnode){
        newnode->data = d;
        newnode -> next = NULL;
        newnode -> prev = NULL;
    }else return;
    if(l -> head == NULL){
        l-> head = newnode;
        l -> tail = newnode;
        return;
    }else{
        node *temp = l -> head;
        while(temp -> next){
            temp = temp -> next;
        }
        temp -> next = newnode;
        newnode -> prev = temp;
        l -> tail = newnode;
        return;
    }
}
void insert_left(DLL *l, int d){
    node *newnode = (node *)malloc(sizeof(node));
    if(newnode){
        newnode->data = d;
        newnode -> next = NULL;
        newnode -> prev = NULL;
    }else return;
    if(l -> head == NULL){
        l -> head = newnode;
        l -> tail = newnode;
        return;
    }else{
        node *temp = l -> head;
        l -> head = newnode;
        newnode -> next = temp;
        temp -> prev = newnode;
        return;
    }
}

void insert_pos(DLL *l, int d, int pos){
    if(pos > length(l) || pos < 1){
        printf("Invalid position\n");
        return;
    }else{
        node *newnode = (node *)malloc(sizeof(node));
        if(newnode){
            newnode->data = d;
            newnode -> next = NULL;
            newnode -> prev = NULL;
        }else return;
        if(pos == 1){
            insert_left(l, d);
            return;
        }else{
            int i = 1;
            node *temp = l -> head;
            while(i < pos - 1){
                temp = temp -> next;
                i++;
            }
            newnode -> next = temp -> next;
            temp -> next -> prev = newnode;
            temp -> next = newnode;
            return;
        }
    }
}

void displayLR(DLL *l){
    node *temp = l->head;
    printf("Fwd: [ ");
    if(!temp){
        printf("]\n");
        return;
    }
    while(temp){
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("]\n");
    return;
}

void displayRL(DLL *l){
    node *temp = l -> tail;
    printf("Bwd: [ ");
    if(!temp){
        printf("]\n");
        return;
    }
    while(temp){
        printf("%d ", temp -> data);
        temp = temp -> prev;
    }
    printf("]\n");
    return;
}

int length(DLL *l){
    int count = 0;
    node *temp = l -> head;
    while(temp){
        count++;
        temp = temp -> next;
    }
    return count;
}

void remove_beg(DLL * l){
    if (isempty(*l)) {       //empty list
        printf("List is already empty\n\n");
        return;
    } else if (l->head == l->tail) {        //only one element
        free(l->head);
        l->head = NULL;
        l->tail = NULL;
        return;
    } else {        //more than one elements
        node *p = l->head;
        l->head = l->head->next;
        l->head->prev = NULL;
        free(p);
    }
    return;
}

void remove_end(DLL * l){
    if (isempty(*l)) {       //empty list
        printf("List is already empty\n\n");
        return;
    } else if (l -> head == l -> tail) {        //only one element
        free(l -> head);
        l -> head = NULL;
        l -> tail = NULL;
        return;
    } else {
        node * p = l -> tail;
        l -> tail = l -> tail -> prev;
        l -> tail -> next = NULL;
        free(p);
    }
}

void remove_pos(DLL *l, int index) {
    if (isempty(*l)) {               // Empty list
        printf("List is already empty\n\n");
        return;
    }
    int len = length(l); 
    if (index < 0 || index >= len) {  // Invalid index
        printf("Invalid index\n\n");
        return;
    }
    if (index == 0) {               // Remove the first node
        remove_beg(l);
        return;
    }
    node *p = l->head;                      
    for (int i = 0; i < index; i++) {
        p = p->next;
    }
    if (p == l->tail) {                  // Removing the last node
        remove_end(l);
    } else {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        free(p);
    }
}


void reverse(DLL *l){
    
}

void SortedInsert(DLL *l, int x) {
    node *t = (node *)malloc(sizeof(node));
    node *temp;
    temp = l -> head;
    t->data = x;
    t->prev = NULL;
    t->next = NULL;

    // If the list is empty
    if (l -> head == NULL) {
        l -> head = l -> tail = t; // Both front and rear point to the new node
    }
    else {
        // Traverse to find the appropriate position
        while (temp && temp->data < x) {
            temp = temp->next;
        }

        // Inserting at the beginning of the list
        if (temp == l -> head) {
            t->next = l -> head;
            l -> head -> prev = t;
            l -> head = t;
        } 
        // Inserting at the end of the list
        else if (temp == NULL) {
            l -> tail -> next = t;
            t->prev = l -> tail;
            l -> tail = t;
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


void removelist(DLL *l, int d)
{
    if (isempty(*l))
        return;
    node *p = l->head;
    while (p->data != d && p->next)
        p = p->next;
    if (p->data == d)
    {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        free(p);
    }
}

void freelist(DLL *l)
{
    node *p = l->head;
    node *q;
    while (p)
    {
        q = p;
        p = p->next;
        free(q);
    }
    l->head = NULL;
    l->tail = NULL;
}


void swap_nodes(DLL *l, node *n1, node *n2) {
    // If the nodes are the same, no need to swap
    if (n1 == n2) return;

    // Save the next and previous nodes for n1 and n2
    node *n1_prev = n1->prev, *n1_next = n1->next;
    node *n2_prev = n2->prev, *n2_next = n2->next;

    // If n1 and n2 are adjacent nodes
    if (n1_next == n2) {
        // Swap the nodes, making sure to adjust their adjacent node's pointers
        n1->prev = n2;
        n1->next = n2_next;
        if (n2_next) n2_next->prev = n1;

        n2->prev = n1_prev;
        n2->next = n1;
        if (n1_prev) n1_prev->next = n2;

        if (n1 == l->head) l->head = n2;
        if (n2 == l->tail) l->tail = n1;
    } 
    // If n1 and n2 are not adjacent
    else {
        // Adjust the prev and next pointers of the nodes around n1 and n2
        if (n1_prev) n1_prev->next = n2;
        if (n1_next) n1_next->prev = n2;
        if (n2_prev) n2_prev->next = n1;
        if (n2_next) n2_next->prev = n1;

        // Swap the prev and next pointers of the nodes themselves
        n1->prev = n2_prev;
        n1->next = n2_next;
        n2->prev = n1_prev;
        n2->next = n1_next;

        // If we are swapping the head or tail
        if (n1 == l->head) l->head = n2;
        else if (n2 == l->head) l->head = n1;

        if (n1 == l->tail) l->tail = n2;
        else if (n2 == l->tail) l->tail = n1;
    }
}


void sort(DLL *l) {
    if (l->head == NULL || l->head->next == NULL) {
        return; // List is empty or has only one element, no sorting needed
    }

    node *p1, *p2;
    int swapped;
    
    // Loop to make multiple passes over the list (bubble sort approach)
    do {
        swapped = 0;  // Flag to track if a swap has happened in this pass
        for (p1 = l->head; p1 != NULL && p1->next != NULL; p1 = p1->next) {
            p2 = p1->next;
            if (p1->data > p2->data) {
                // Swap nodes
                swap_nodes(l, p1, p2);
                swapped = 1;  // Mark that a swap happened
            }
        }
    } while (swapped);  // Keep going until no swaps happen in a full pass
}



int search(DLL l, int d)
{
    node *p = l.head;
    while (p)
    {
        if (p->data == d)
            return 1;
        p = p->next;
    }
    return 0;
}

DLL listunion(const DLL l1, DLL l2)
{
    DLL l3;
    init_DLL(&l3);
    node *ptr1 = l1.head;
    while (ptr1)
    {
        insert_right(&l3, ptr1->data);
        ptr1 = ptr1->next;
    }

    node *ptr2 = l2.head;
    while (ptr2)
    {
        if (!search(l3, ptr2->data))
        {
            insert_right(&l3, ptr2->data);
        }
        ptr2 = ptr2->next;
    }

    return l3;
}

DLL intersection(DLL l1, DLL l2)
{
    DLL l3;
    init_DLL(&l3);
    int x;
    node *p = l1.head;
    while (p)
    {
        x = p -> data;
        if (search(l2, x))
        {
            insert_right(&l3, x);
        }
        p = p->next;
    }
    return l3;
}


// void removeDuplicates(DLL *l) {
//     if (isempty(*l)) return;

//     node *current = l->head;
//     node *temp, *duplicate;

//     // Outer loop to pick each element one by one
//     while (current && current->next) {
//         temp = current->next;

//         // Inner loop to check for duplicates
//         while (temp) {
//             // If a duplicate is found
//             if (current->data == temp->data) {
//                 duplicate = temp;
                
//                 // Adjust the links
//                 if (duplicate->prev)
//                     duplicate->prev->next = duplicate->next;
//                 if (duplicate->next)
//                     duplicate->next->prev = duplicate->prev;

//                 // Update the rear pointer if the duplicate is the last element
//                 if (duplicate == l->tail)
//                     l->tail = duplicate->prev;

//                 // Free the duplicate node
//                 node *nextTemp = duplicate->next;
//                 free(duplicate);
//                 temp = nextTemp;  // Move to the next node
//             } else {
//                 temp = temp->next;
//             }
//         }
//         current = current->next;
//     }
// }

void removeDuplicates(DLL *l) {
    node *p = l->head;
    while (p != NULL) {
        node *q = p->next;
        while (q != NULL) {
            if (p->data == q->data) {
                node *temp = q;
                q = q->next;
                if (temp == l->tail) {
                    remove_end(l);
                } else {
                    temp->prev->next = temp->next;
                    if (temp->next != NULL) {
                        temp->next->prev = temp->prev;
                    }
                    free(temp);
                }
            } else {
                q = q->next;
            }
        }
        p = p->next;
    }
}

void is_palindrome(DLL * l){
    int len = length(l);
    if (isempty(*l)) {               // Empty list
        printf("List is empty\n\n");
        return;
    }
    else if (len == 1){               //only 1 element in list
        printf("List is a palindrome\n\n");
        return;
    }
    node *p = l->head;
    node *q = l->tail;

    while (p != q && p->next != q) {
        if (p->data != q->data) {
            printf("List is not a palindrome\n\n");
            return;
        }
        p = p->next;
        q = q->prev;
    }
    printf("List is a palindrome\n\n");
    return;
}
