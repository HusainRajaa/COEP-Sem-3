#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"


void init_SLL(SLL *head){
    *head = NULL;
    return;
}

void append(SLL *head){
    int randomNumber;
    int min = 1;
    int max = 100;
    randomNumber = (rand() % (max - min + 1)) + min;
    node *temp;
    node *newnode = (node *)malloc(sizeof(node));
    if(newnode){
        newnode -> data = randomNumber;
        newnode -> next = NULL;
    }
    else return;

    if(*head == NULL){
        *head = newnode;
        return;
    }
    temp = *head;
    while(temp -> next){
        temp = temp -> next;
    }
    temp -> next = newnode;
    
    return;
}

void traverse_SLL(SLL *head){
    node *temp;
    temp = *head;
    while(temp){
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
    return;
}

void insert_beg(SLL *head){
    int randomNumber;
    int min = 1;
    int max = 100;
    randomNumber = (rand() % (max - min + 1)) + min;
    node *newnode = (node *)malloc(sizeof(node));
    if(newnode){
        newnode -> data = randomNumber;
        newnode -> next = NULL;
    }
    else return;

    newnode -> next = *head;
    *head = newnode;

    return;
}

void insert_end(SLL *head){
    int randomNumber;
    int min = 1;
    int max = 100;
    randomNumber = (rand() % (max - min + 1)) + min;
    node *temp;
    node *newnode = (node *)malloc(sizeof(node));
    if(newnode){
        newnode -> data = randomNumber;
        newnode -> next = NULL;
    }
    else return;
    temp = *head;
    while(temp -> next){
        temp = temp -> next;
    }
    temp -> next = newnode;
    return;
}

void insert_pos(SLL *head, int pos){
    int randomNumber;
    int min = 1;
    int max = 100;
    randomNumber = (rand() % (max - min + 1)) + min;
    int i = 1;
    node *temp;
    if(pos > length(head) || pos < 0){
        printf("Invalid Position");
        return;
    }
    else{
        temp = *head;
        node *newnode = (node *)malloc(sizeof(node));
        if(newnode){
            newnode -> data = randomNumber;
            newnode -> next = NULL;
        }
        else return;
        while(i < pos - 1){
            temp = temp -> next;
            i++;
        }
        newnode -> next = temp -> next;
        temp -> next = newnode;
    }
}

int length(SLL *head){
    int count = 0;
    node *temp = *head;
    while(temp){
        count++;
        temp = temp -> next;
    }
    return count;
}

void remove_beg(SLL *head){
    node *temp = *head;
    *head = temp -> next;
    free(temp);
    return;
}

void remove_end(SLL *head){
    node *temp, *prevnode;
    temp = *head;
    while(temp -> next){
        prevnode = temp;
        temp = temp -> next;
    }
    if(temp == *head){
        head = 0;
        free(temp);
    }
    else{
        prevnode -> next = 0;
        free(temp);
    }
}

void remove_pos(SLL *head, int pos){
    if (pos > length(head) || pos < 1) { 
        printf("Invalid position\n");
        return;
    }
    node *nextnode, *temp;
    if(pos == 1){
        remove_beg(head);
        return;
    }
    int i = 1;
    temp = *head;
    while(i < pos - 1){
        temp = temp -> next;
        i++;
    }
    nextnode = temp -> next;
    temp -> next = nextnode -> next;
    free(nextnode);
}