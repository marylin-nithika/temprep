#include<stdio.h>
#define max 50

struct node{
    char name[max];
    char usn[max];
    int marks;
    struct node *next;
};

struct node* head;

struct node* createnode(){

    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the name\n");
    scanf("%s",newnode->name);
    printf("Enter usn :\n");
    scanf("%s",newnode->usn);
    printf("Enter marks : \n");
    scanf("%d",&newnode->marks);

    newnode->next = NULL;
    
    return newnode;
}

void insertnode(int n){

    for(int i =0; i<n; i++){
        struct node* newnode;
        newnode = (struct node*)malloc(sizeof(struct node));

        newnode = createnode();

        if(head == NULL){
            head = newnode;
        }
        else{
            newnode->next = head;
            head = newnode;
        }
    }
    printf("Nodes have been created\n");
}

void insertatend(){

    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node*));

    newnode = createnode();

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
        //newnode->next = NULL;
    }
}

void display(){

    printf("--------------------------------------------\n");
    printf("The nodes are\n");
    if(head == NULL){
        printf("%s\n%s\n%d\n",head->name,head->usn,head->marks);
        return;
    }
    else{
        struct node* temp;
        temp = head;

        while(temp!=NULL){
            printf("%s\n%s\n%d\n",head->name,head->usn,head->marks);
            temp = temp->next;
        }
    }
    printf("----------------------------------------------\n");
}

void deletefromend(){

    if(head == NULL){
        printf("The list is empty\n");
    }
    else if(head->next == NULL){
        free(head);
    }
    else{
        struct node* temp;
        temp = head;
        while(temp->next->next!=NULL);
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void insertatfront(){
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node*));

    newnode = createnode();
    if(head == NULL){
        head = newnode;
    }
    else{
        newnode->next = head;
        head = newnode;
    }
    printf("node has been inserted\n");
}

void deletefromfront(){
    if(head == NULL){
        printf("The list is empty\n");
    }
    else if(head->next == NULL){
        free(head);
    }
    else{
        struct node* temp;
        temp = head;
        head = head->next;
        free(temp);
    }
}


int main() { 
    int choice, n; 
 
    while (1) { 
        printf("\n----- SLL MENU -----\n"); 
        printf("1. Create SLL (Front Insertion)\n"); 
        printf("2. Display & Count\n"); 
        printf("3. Insert at End\n"); 
        printf("4. Delete from End\n"); 
        printf("5. Insert at Front\n"); 
        printf("6. Delete from Front\n"); 
        printf("7. Exit\n"); 
        printf("Enter choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
        case 1: 
            printf("Enter number of students: "); 
            scanf("%d", &n); 
            insertnode(n); 
            break; 
        case 2: 
            display(); 
            break; 
        case 3: 
            insertEnd(); 
            break; 
        case 4: 
            deleteEnd(); 
            break; 
        case 5: 
            insertFront(); 
            break; 
        case 6: 
            deleteFront(); 
            break; 
        case 7: 
            return 0; 
        default: 
            printf("\nInvalid Choice!\n"); 
        } 
    } 
}