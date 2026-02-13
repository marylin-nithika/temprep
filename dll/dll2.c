//insert into an empty list
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node* insertnode(int n){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

int main(){
    struct node *head;
    struct node *newnode;
    int n=3;
    int x;
    for(int i=0; i<n; i++){
        printf("enter data to be inserted : ");
        scanf("%d",&x);
        newnode = insertnode(x);
        if(head == NULL){
            head = newnode;
        }
        else{
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
        printf("node for %d has been created\n",x);
    }

    //displaying the nodes;
    printf("\n");
    printf("The following nodes are : \n");

    struct node* temp;
    temp = head;
    
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}