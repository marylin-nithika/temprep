#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head;

struct node* createNode(){

    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data for newnode\n");
    scanf("%d",&newnode->data);

    newnode->next = NULL;

    return newnode;
}

//insertatfront
void createSLL(int n){
    for(int i=0; i<n; i++){
        struct node *newnode;
        newnode = createNode();

        if(head == NULL){
            head = newnode;
        }
        else{
            newnode->next = head;
            head = newnode;
        }
    }
    printf("nodes have been created\n");
}

void display(){
    int count=0;
    struct node* temp;
    temp = head;

    while(temp!=NULL){
        count++;
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
    printf("No of nodes present are %d\n",count);
}

void InsertAtEnd(){
    struct node* newnode;
    newnode = createNode();

    if(head == NULL){
        head = newnode;
    }
    else{
        struct node *temp;
        temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
    printf("node has been inserted.\n");
}

void DeletefromEnd(){
    if(head == NULL){
        printf("List is empty");
        return;
    }
    else if(head->next == NULL){
        free(head);
        head = NULL;
    }
    else{
        struct node *temp;
        temp = head;
        while(temp->next->next!=NULL){
            temp = temp->next;
        }
        temp->next = NULL;
        free(temp->next);
    }
    prinf("node has been deleted.\n");
}

void DeleteFromFront(){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    else if(head->next == NULL){
        free(head);
        head = NULL;
    }
    else{
        struct node *temp;
        temp = head;
        head = head->next;
        free(temp);
    }
}


int main(){
    int ch, m;
    do{
        printf("-----------SLL operations--------------\n");
        printf("1.createSLL(front insertion)\n2.Display and count\n3.InsertAtend\n4.DeletefromEnd\n5.DeletefromFront\n6.exit\n");
        printf("Enter your choice :\n");
        scanf("%d",&ch);
        switch(ch){
            case 1 :
            printf("enter the number of nodes\n");
            scanf("%d",&m);
            createSLL(m);
            break;

            case 2 : 
            display();
            break;

            case 3 :
            insertAtend();
            break;

            case 4 :
            DeletefromEnd();
            break;

            case 5 :
            DeleteFromFront();
            break;

            case 6 :
            break;

            default : 
            printf("invalid choice. enter valid choice\n");
            break;
        }
    }while(ch!=6);

    return 0;
}