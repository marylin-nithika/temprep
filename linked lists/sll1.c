#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node* createnode(){
    int x;
    printf("Enter the data");
    scanf("%d",&x);

    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
}

void insert(int n){

    int i=0;
    for(i=0; i<n; i++){
        struct node *newnode;
        newnode = createnode();

        if(head == NULL){
            head = newnode;
        }
        else{
            newnode->next = head;
            head = newnode;
        }
    }
    printf("nodes have been inserted");
}

void insertatfront(){

    struct node* newnode;
    newnode = createnode();

    if(head == NULL){
        head = newnode;
    }
    else{
        newnode->next = head;
        head = newnode;
    }
}

void insertatlast(){
    struct node* newnode;
    newnode = createnode();

    if(head == NULL){
        head = newnode;
    }
    else if(head->next == NULL){
        head->next = newnode;
    }
    else{
        struct node* temp;
        temp = head;

        while(temp->next!=NULL){
            temp = temp->next;
        }

        temp->next = newnode;
    }
}

void insertAtSpecific(int pos){
    struct node* newnode;
    newnode = createnode();

    struct node* temp;
    temp = head;

    if(pos<1){
        printf("invalid position");
    }
    else if(pos == 1){
        head = newnode;
    }
    else{
        for(int i = 1; i<pos-1; i++){
            temp = temp->next;
        }

        newnode->next = temp->next;
        temp->next = newnode;
    }

}

void deletefromfront(){
    struct node* temp;
    temp = head;

    if(head == NULL){
        printf("list is empty");
    }
    else{
        temp = head;
        head = head->next;
        free(temp);
    }
}

deletrfromend(){
    struct node* temp;

    if(head == NULL){
        printf("list is empty");
    }
    else if(head->next == NULL){
        free(head);
    }
    else{
        temp = head;
        while(temp->next->next!=NULL){
            temp = temp->next;
        }

        free(temp->next);
        temp->next = NULL;
    }
}

void deleteatspecific(int pos){
    struct node* temp;
    temp = temp->next;
    if(pos<1){
        printf("invalid space");
    }
    else{
        for(int i=1; i<pos-1; i++){
            temp = temp->next;
        }

        
    }

}



int main(){
    int ch, m;
    do{
        printf("-----------SLL operations--------------\n");
        printf("1.createSLL(front insertion)\n2.Display and count\n3.InsertAtend\n3.5insertatspecofoc\n4.DeletefromEnd\n5.DeletefromFront\n6.exit\n");
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