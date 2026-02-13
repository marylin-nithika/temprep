#include<stdlib.h>
#include<stdio.h>

struct node{
    int co;
    int exp;
    struct node* next;
};

struct node* createnode(int c, int e){

    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->co = c;
    newnode->exp = e;
    newnode->next = newnode;

    return newnode;
}



struct node* insertnode(struct node* head,int c,int e){
    struct node* newnode;
    newnode = createnode(c,e);

    //inserting at the end;

    if(head == NULL){
        return newnode;
    }
    else{
        struct node *temp;
        temp = head;
        
        while(temp->next != head){
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->next = head;
        return head;
    }
}


void display(struct node* head){

    if(head == NULL){
        printf("list is empty");
        return;
    }
    else{
            struct node* temp;
            temp = head;
        do{
            printf("%dx^%d",temp->co,temp->exp);
            temp = temp->next;
            if(temp!=head) printf(" + ");

        }while(temp!=head);  
    }
    
    printf("\n");
}

struct node* addpoly(struct node* p1, struct node* p2){

    if(!p1)return p2;
    if(!p2)return p1;

    struct node* t1 = p1;
    struct node* t2 = p2;
    struct node* result = NULL;

    do{
        if(t1->exp == t2->exp){
            result = insertnode(result,t1->co+t2->co,t1->exp);
            t1 = t1->next;
            t2 = t2->next;
        }
        else if(t1->exp>t2->exp){
            result = insertnode(result,t1->co,t1->exp);
        }
        else{
            result = insertnode(result, t1->co, t1->exp);
        }
    }while(t1!=p1 && t1!= p2);

    while(t1!=p1){
        result = insertnode(result, t1->co, t1->exp);
        t1 = t1->next;
    }
    while(t2!=p2){
        result = insertnode(result, t2->co, t2->exp);
        t2 = t2->next;
    }
    return result;
}



int main(){

    int c,e;
    int n;

    struct node* p1 = NULL;
    struct node* p2 = NULL;
    struct node* p3 = NULL;

    printf("enter the number of terms for the polynomial :\n");
    scanf("%d",&n);
    printf("for polynomial set 1\n");
    printf("\n");

    for(int i = 0; i<n; i++){
        printf("For term %d\n",i+1);
        printf("enter the coefficient : ");
        scanf("%d",&c);
        printf("enter the exponent : ");
        scanf("%d",&e);

        p1 = insertnode(p1,c,e);
    }

    display(p1);

    for(int i=0; i<n; i++){
        printf("for term %d\n ",i+1);
        printf("enter the coefficient : ");
        scanf("%d",&c);
        printf("enter the exponent : ");
        scanf("%d",&e);

        p2 = insertnode(p2,c,e);
    }

    display(p2);

    printf("/n");
    printf("resultant polynomial : \n");
    p3 = addpoly(p1,p2);
    display(p3);
}
