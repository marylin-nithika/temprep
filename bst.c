#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* root;

struct node* createnode(int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

struct node* insertnode(struct node* root, int data){
    if(root == NULL){
        root = createnode(data);
        return root;
    }
    else if(data<root->data){
        root->left = insertnode(root->left,data);
    }
    else{
        root->right = insertnode(root->right, data);
    }
    return root;
}

void inorder(struct node* root){
    if(root == NULL)return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void preorder(struct node* root){
    if(root == NULL)return;
    printf("%d",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node* root){
    if(root == NULL)return;
    postorder(root->left);
    postorder(root->right);
    printf("%d",root->data);
}

struct node* search(struct node* root, int key){
    if(root == NULL){
        return NULL;
    }
    else if(root->data == key){
        return root;
    }
    else{
        if(key<root->data){
            return search(root->left, key);
        }
        else{
            return search(root->right, key);
        }
    }
}

void freenode(struct node* root){
    if(root == NULL) return;
    freenode(root->right);
    freenode(root->left);
    free(root);
}

int main(){

    int choice;
    int n;
    int key;

    root = NULL;

    do{
        printf("-------------------BST OPERATIONS---------------------\n");
        printf("1.create\n2.inorder\n3.preorder\n4.postorder\n5.Search\n6.exit\n");
        printf("------------------------------------------------------\n");
        printf("enter your choice");
        scanf("%d",&choice);
        switch(choice){


            case 1 :

            int data;
            printf("Data : ");
            scanf("%d",&data);
            root = insertnode(root, data);
            printf("data has been inserted\n");
            break;

            case 2 :
            if(root == NULL){
                printf("The tree is empty\n");
            }
            else{
                inorder(root);
                printf("\n");
            }
            break;

            case 3 :
            if(root == NULL){
                printf("The tree is empty\n");
            }
            else{
                preorder(root);
                printf("\n");
            }
            break;

            case 4 :
            if(root == NULL){
                printf("The tree is empty\n");
            }
            else{
                postorder(root);
                printf("\n");
            }
            break;

            case 5 :
            printf("Enter the element to be searched");
            scanf("%d",&key);
            if(search(root,key) == NULL){
                printf("Element not found");
            }
            else{
                printf("Element is found\n");
            }
            break;


            case 6 :
            freenode(root);
            printf("exited the program");
            break;

            default :
            printf("invalid\n");
            break;

        }
    }while(choice!=6);
}