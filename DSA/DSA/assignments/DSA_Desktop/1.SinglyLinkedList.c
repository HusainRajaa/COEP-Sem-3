#include<stdio.h>
#include<stdlib.h>
int count;
struct node{
    int data;
    struct node *next;
}*head;

void insertAtBeginning(){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter Data You Want To Insert At Beginning : ");
    scanf("%d",&newnode->data);
    newnode->next = head;
    head = newnode;
}
void insertAtEnd(){
    struct node *newnode,*temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data You Want To Insert At End : ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
}
void insertAfterGivenPosition(){
    struct node *newnode,*temp;
    int pos , i = 1;
    printf("Enter the position after which you want to enter data : ");
    scanf("%d",&pos);
    if(pos > count || pos < 0){
        printf("Invalid Position : ");
    }
    else{
        temp = head;
        newnode = (struct node *)malloc(sizeof(struct node));
        while(i < pos){
            temp = temp->next;
            i++;
        }
        printf("Enter Data : ");
        scanf("%d",&newnode->data);
        newnode->next = temp->next;
        temp->next = newnode;
    }
}
void insertAtGivenPosition(){
    int pos , i = 1;
    printf("Enter the position at which you want to enter data : ");
    scanf("%d",&pos);
    if(pos > count+1 || pos < 1){
        printf("Invalid Position : ");
    }
    else if(pos == 1){
        insertAtBeginning();
    }
    else if(pos == count+1){
        insertAtEnd();
    }
    else{
        struct node *newnode,*temp;
        temp = head;
        newnode = (struct node *)malloc(sizeof(struct node));
        while(i < pos-1){
            temp = temp->next;
            i++;
        }
        printf("Enter Data : ");
        scanf("%d",&newnode->data);
        newnode->next = temp->next;
        temp->next = newnode;
    }
}
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
void deleteFromBeginning(){
    struct node *temp;
    temp = head;
    head = temp->next;
    free(temp);
}
void deleteFromEnd(){
    struct node *temp , *prevnode;
    temp = head;
    while(temp->next != 0){
        prevnode = temp;
        temp = temp->next;
    }
    if(temp == head){
        head = 0;
        free(temp);
    }
    else{
        prevnode->next = 0;
        free(temp);
    }
}
void deleteFromSpecificPosition(){
    struct node *nextnode , *temp;
    int pos , i = 1 ;
    temp = head;
    printf("Enter the position : ");
    scanf("%d",&pos);
    while(i < pos - 1){
        temp = temp->next;
        i++;
    }
    nextnode = temp->next;
    temp->next = nextnode->next;
    free(nextnode);
}
void main(){
    createSLL();
    displaySLL();
    // Insert at beginning
    insertAtBeginning();
    displaySLL();
    // Insert at end
    insertAtEnd();
    displaySLL();
    // Insert after a given location
    insertAfterGivenPosition();
    displaySLL();
    // Insert at a given position
    insertAtGivenPosition();
    displaySLL();
    // Delete From Beginning
    deleteFromBeginning();
    displaySLL();
    // Delete From End
    deleteFromEnd();
    displaySLL();
    //Delete From Specific Position
    deleteFromSpecificPosition();
    displaySLL();
}