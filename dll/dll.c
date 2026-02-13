#include<stdio.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

int main(){
    struct node *head;
    struct node *newnode1;
    newnode1 = (struct node*)malloc(sizeof(struct node));
    
    newnode1->data = 5;
    newnode1->next = NULL;
    newnode1->prev = NULL;

    struct node *newnode2;
    newnode2  = (struct node*)malloc(sizeof(struct node));

    newnode2->data = 6;
    newnode2->prev = newnode1;
    newnode2->next = NULL;

    head = newnode1;

    printf("The nodes are");
    printf("%d",newnode1->data);
    printf("%d", newnode2->data);

}