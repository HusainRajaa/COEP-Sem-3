#include <stdio.h>
#include<stdlib.h>
int count;
struct node{
    int data;
    struct node *next;
}*head;

void createSLL(){
    struct node *newnode , *temp ;
    int choice ;  
    choice = 1;
    head = 0;
    while(choice){
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data : ");
        scanf("%d" , &newnode->data);
        newnode->next = 0;
        if(head == 0){
            head = temp = newnode ;
        }
        else{
            temp->next = newnode ;
            temp = newnode;
        }
        printf("Do you want to continue (0 , 1)? ");
        scanf("%d",&choice);
    }
}

void displaySLL(){
    struct node *temp;
    temp = head;
    count = 0;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
        count++;
    }
    printf("\n");
}

// Recursive Display Function
void display(struct node *p){
    while(p != NULL){
        printf("%d ",p->data);
        display(p->next);
    }
}

int Count(struct node *p){
    int c = 0;
    while(p != 0){
        c++;
        p = p -> next;
    }
    return c;
}

int Rcount(struct node *p){
    if( p == 0){
        return 0;
    }
    else{
        return Rcount(p -> next) + 1;
    }
}

int RecCount(struct node *p){
    int x = 0;
    if(p){
        x = RecCount(p -> next);
        return x + 1;
    }
    else{
        return x;
    }
}

int Add(struct node *p){
    int sum = 0;
    while(p){
        sum += p -> data;
        p = p -> next;
    }
    return sum;
}

int RAdd(struct node *p){
    if(p){
        return (p -> data) + RAdd(p -> next);
    }
    else{
        return 0;
    }
}

int main(){
    createSLL();
    displaySLL();
    display(head);
    return 0;
}
