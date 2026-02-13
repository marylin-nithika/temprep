#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* root;

struct node* createnode(int data){
    struct node *newnode;
    newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

struct node* insertion(struct node* root, int data){

    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    if(root == NULL){
        newnode = createnode(data);
        return newnode;
    }
    else if(data<root->data){
        root->left =  insertion(root->left,data);
    }
    else{
        root->right = insertion(root->right,data);
    }
    return root;
}

void inorder(struct node* root){
    if(root == NULL) return;
    else{
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}

void preorder(struct node* root){
    if(root == NULL) return;
    else{
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root){
    if(root == NULL)return;
    else{
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
    }
}

struct node* search(struct node* root, int key){
    if(root == NULL)return NULL;
    if(root->data == key) return root;
    if(root->data < key ){
         return search(root->left, key);
    }
    else{
         return search(root->right, key);
    }
}

void freenode(struct node* root){
    if(root == NULL) return;
    freenode(root->left);
    freenode(root->right);
    free(root);
}

int main(){

    int ch;
    root = NULL;

    do{
        printf("------------------BST OPERATIONS-----------------------\n");
        printf("1.insertion\n2.inorder\n3.preorder\n4.postorder\n5.search\n6.exit\n");
        printf("----------------------------------------\n");
        printf("enter your choice\n");
        scanf("%d",&ch);
        switch(ch){
            case 1 :
            int x;
            printf("Data : ");
            scanf("%d",&x);
            root = insertion(root,x);
            printf("%d has been inserted\n",x);
            break;

            case 2 :
            if(root == NULL){
                printf("The tree is empty ");
            }
            else{
                inorder(root);
            }
            break;

            case 3 :
            if(root == NULL){
                printf("The tree is empty ");
            }
            else{
                preorder(root);
            }
            break;

            case 4 :
            if(root == NULL){
                printf("The tree is empty ");
            }
            else{
                postorder(root);
            }
            break;

            case 5 :
            int key;
            printf("Enter the element to be searched : ");
            scanf("%d",&key);
            if(search(root,key)==NULL){
                printt("element is not found\n");
            }
            else{
                printf("element is found\n");
            }
            break;

            case 6 :
            freenode(root);
            printf("exited successfully\n");
            break;

            default :
            printf("Invalid choice\n");
        }
    }while(ch!=6);
    
}