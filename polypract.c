#include<stdio.h>

struct node{
    int co;
    int exp;
    struct node* next;
};

struct node* insert(struct node* head, int co, int exp){
    struct node* newnode;

    newnode = createnode(co, exp);

    if(head == NULL){
        head = newnode;
    }
    else{
        struct node* temp;
        temp = head;

        while(temp->next!= NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

struct node* createnode(int co, int exp){

    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->next = NULL;
    newnode->co = co;
    newnode->exp = exp;

    return newnode;
}

void display(struct node* head){

    struct node* temp;
    temp = head;

    while(temp!= NULL){
        printf("%d^%d",temp->co, temp->next);
    }
}

struct node* addpoly(struct node* p1, struct node* p2){

    if(!p1) return p2;
    if(!p2) return p1;

    struct node* t1 = p1;
    struct node* t2 = p2;

    struct node* result = NULL;
    do{
        if(t1->exp == t2->exp){
            result = insert(result, t1->co + t2->co, t1->exp);

            t1 = t1->next;
            t2 = t2->next;
        }
        else if(t1->exp > t2->exp){
            result = insert(result, t1->co, t1->exp);
        }
        else{
            result = insert(result, t2->co, t2->exp );
        }
        
    }while(t1!=NULL && t2!=NULL);

    while(t1!=NULL){
        result = insertnode(result,t1->co, t1->next);
        t1 = t1->next;
    }



}



void main(){
    int n;
    int co;
    int exp;

    struct node* p1 = NULL;
    struct node* p2 = NULL;
    struct node* p3 = NULL;


    printf("enter the number of polynomials\n");
    scanf("%d",&n);

    printf("enter the data for each polynomial\n");

    for(int i=0; i<n; i++){
        printf("enter the coefficient");
        scanf("%d",&co);

        printf("enter the exponent");
        scanf("%d",&exp);

        insertnode(p1,co,exp);
    }

    display(p1);

    for(int i=0; i<n; i++){
        printf("enter the coefficient");
        scanf("%d",&co);

        printf("enter the exponent");
        scanf("%d",&exp);

        insertnode(p1,co,exp);
    }

    display(p2);
}