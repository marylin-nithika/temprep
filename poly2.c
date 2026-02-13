#include<stdio.h>
#include<stdlib.h>

struct node{
    int co;
    int exp;
    struct node* next;
};

struct node* insert(struct node* head, int c, int e)
{

    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode = createnode(c,e);

    //insert at end 
    if(head == NULL){
        
    }

}

int main(){

    struct node* p1 = NULL;
    struct node* p2 = NULL;
    struct node* p3 = NULL;

    printf("For polynomial 1 :\n");
    int n;
    int e;
    int c;

    printf("enter the number of terms : ");
    scanf("%d",&n);

    for(int i=0; i<n; i++){

        printf("Enter the coefficient : ");
        scanf("%d",&c);
        printf("Enter the exponent : ");
        scanf("%d",&e);
        p1 = insert(p1,c,e);
    }

    display(p1);


}