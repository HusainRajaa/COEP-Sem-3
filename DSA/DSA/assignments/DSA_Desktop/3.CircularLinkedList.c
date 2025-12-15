#include<stdio.h>
#include<stdlib.h>
int count;
struct node{
    int data;
    struct node *next;
}*head;
void createCLL(){
    struct node *newnode , *temp ;
    int choice = 1;
    head = 0;
    while(choice){
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data : ");
        scanf("%d" , &newnode->data);
        newnode->next = 0;
        if(head == 0){
            head = temp = newnode ;
            // temp->next = newnode;
        }
        else{
            temp->next = newnode ;
            temp = newnode;
        }
        temp->next = head;      // Additional to SLL
        printf("Do you want to continue (0 , 1)? ");
        scanf("%d",&choice);
    }
}
void displayCLL(){
    struct node *temp;
    if(head == 0){
        printf("List is empty");
    }
    else{
        temp = head;
        count = 0;
        while(temp->next != head){
            printf("%d ",temp->data);
            temp = temp->next;
            count++;
        }
        count++;
        printf("%d\n",temp->data);
        printf("%d\n",count);
        // This Line Below is used to check is it circular or not
        // printf("%d",temp->next->data);      
    }
}
void main(){
    createCLL();
    displayCLL();
}
