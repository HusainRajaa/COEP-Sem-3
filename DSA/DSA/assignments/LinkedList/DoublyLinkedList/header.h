#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} node;

typedef struct DLL {
    node *front;
    node *rear;
} DLL;


void init_DLL(DLL *l);
int isempty(DLL l);
void insert_beg(DLL *l, int d);
void insert_end(DLL *l, int d);
void insert_pos(DLL *l, int d, int pos);
void remove_beg(DLL *l);
void remove_end(DLL *l);
void remove_pos(DLL *l, int pos);
void sort(DLL *l);
void displayLR(DLL l);
void displayRL(DLL l);
int is_palindrome(DLL l);
void remove_duplicates(DLL *l);