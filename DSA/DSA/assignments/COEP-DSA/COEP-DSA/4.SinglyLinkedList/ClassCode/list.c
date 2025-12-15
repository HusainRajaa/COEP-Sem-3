#include <stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "list.h"

void init(list *head) {
    *head = NULL;
    return;
}

/*Insert at end*/
void insert_end(list *head, int d){
    node *p, *newnode;
    newnode = (node*)malloc(sizeof(node));
    if(newnode){
        newnode->data = d;
        newnode->next = NULL;
    }
    else return;
    if(*head == NULL){
        *head = newnode;
        return;
    }
    p = *head;
    while(p -> next) {
       p = p->next;
    }
    p->next = newnode;
    return;
}

/*Insert at beginning*/
void insert_beg(list *head, int d){
    node  *newnode;
    newnode = (node*)malloc(sizeof(node));
    if(newnode){
        newnode->data = d;
        newnode->next = NULL;
    }
    else return;
    newnode->next = *head;
    *head = newnode;
    return;
}
/*Deletes node at beginning*/
void delete_beg(list *head)
{
  node *p = *head;

  // if there are no nodes in Linked List can't delete
  if (*head == NULL)
      return;

  // move head to next node
  *head = (*head)->next;
  free(p);
  return;
}

// Delete last node.
void delete_end (list *head)
{
  node *p = *head;
  node *q;

  // if there are no nodes in Linked List can't delete
  if (*head == NULL)
  	return;

  // if Linked List has only 1 node
  if (p-> next == NULL){
      *head = NULL;
      return;
    }

  // else traverse to the last node
  while (p->next != NULL)
    {
      // store previous link node as we need to change its next val
      q = p;
      p = p->next;
    }
  // Curr assign 2nd last node's next to Null
  q->next = NULL;
  // delete the last node
  free (p);
  // 2nd last now becomes the last node
  return;
}


// Displays linked list contents.
void traverse(list head){
    printf("[");
    node *p;
    p = head;
    while(p){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("]\n");
    return;
}









