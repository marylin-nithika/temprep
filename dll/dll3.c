#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node* head;

struct node* createNode(){
    int x;
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data to be inserted : \n");
    scanf("%d",&x);
    newnode->data = x;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

void insertnode(int n){
    head = NULL;
    for(int i=0; i<n; i++){
        struct node* newnode;
        newnode = createNode();
        if(head == NULL){
            head = newnode;
        }
        else{
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
    }
    printf("nodes have been created\n");
}

void display(){
    printf("\n");
    printf("The following nodes are : \n");

    struct node* temp;
    temp = head;
    
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void InsertAtEnd(){

    struct node* newnode;
    newnode = createNode();

    if(head == NULL){
        head = newnode;
    }
    else{
        struct node* temp;
        temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
    printf("node has been inserted at the end");
}

void DeleteFromFront(){
    if(head == NULL){
        printf("The list is empty\n");
    }
    else if(head->next == NULL){
        free(head);
        head = NULL;
        printf("node has been deleted\n");
    }
    else{
        struct node* temp;
        temp = head;
        head = temp->next;
        free(temp);
        printf("node has been deleted\n");
    }
}

void DeletefromEnd(){
    if(head == NULL){
        printf("The list is empty\n");
    }
    else if(head->next == NULL){
        free(head);
        head = NULL;
        printf("Node has been deleted\n");
    }
    else{
        struct node* temp;
        temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        struct node* temp2;
        temp2 = temp->prev;

        temp->prev = NULL;
        temp2->next = NULL;
        free(temp);
        printf("node has been deleted.\n");
    }
}

int main(){
    struct node *newnode;
    int n;
    int ch;
    do{
        printf("---------------------DLL OPERATIONS--------------------\n");
        printf("1. insertnode.\n2. InsertAtEnd\n3.DeleteFromFront\n4.DeleteFromEnd\n5.Display\n6.Exit");
        printf("--------------------------------------------------------\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1 :
            printf("Enter the number of nodes : ");
            scanf("%d",&n);
            insertnode(n);
            break;

            case 2 :
            InsertAtEnd();
            break;

            case 3 :
            DeleteFromFront();
            break;

            case 4 :
            //DeleteFromEnd();
            break;

            case 5 :
            Display();
            break;

            case 6 :
            printf("Exited successfully");
            break;

            default :
            printf("Invalid choice. Enter a valid choice\n");
            break;
        }
    }while(ch!=6);
    return 0;
}