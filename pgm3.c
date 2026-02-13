#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100

typedef struct{
    int top;
    int data[max];
}Stack;

void initialize(Stack *stack){
    stack->top = -1;
    //return;
}

int isEmpty(Stack *stack){
    return stack->top == -1;
}

int isFull(Stack *stack){
    return stack->top == max - 1;
}

void push(Stack *stack, int x){
    if(isFull(stack)){
        printf("stack overflow\n");
        return;
    }
    else{
        stack->data[++stack->top] = x;
    }
}

int pop(Stack *stack){
    if(isEmpty(stack)){
        printf("stack is empty\n");
        return -1;
    }
    else{
        return stack->data[stack->top--];
    }
}

void peek(Stack *stack){
    if(isEmpty(stack)){
        printf("stack is empty\n");
        return;
    }
    else{
        printf("The topmost element is %d\n", stack->data[stack->top]);
    }
}

void displaystack(Stack *stack){
    int i; 
    if(isEmpty(stack)){
        printf("Stack is empty\n ");
        return;
    }
    else{
        printf("The elements present in the stack are\n");
        for(int i = 0; i<=stack->top; i++){
            printf("%d",stack->data[i]);
        }
    }
}

void checkpalindrome(char *str){
    int i;
    int n = strlen(str);
    Stack stack;
    initialize(&stack);
    int p=1;

    for(i=0; i<n; i++){
        push(&stack, str[i]);
    }
    for(i=0; i<n; i++){
        if(pop(&stack)!= str[i])
        {
            p=0;
            break;
        }
    }

    if(p==1){
        printf("it is palindrome");
    }
    else{
        printf("Not palindrome");
    }

    
}

int main(){
    Stack stack;
    initialize(&stack);

    int ch, value;
    do{
        printf("-------------------STACK OPERATIONS-----------------------\n");
        printf("1.push\2.pop\n3.peek\n4.display\n5.checkpalindrome\n6.exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch){
            case 1 : 
            printf("Enter the element to be pushed\n");
            scanf("%d",&value);
            push(&stack, value);
            break;

            case 2 :
            int data = pop(&stack);
            printf("the popped value is %d\n",data);
            break;

            case 3 :
            peek(&stack);
            break;

            case 4:
            displaystack(&stack);
            break;
            
            case 5 :
            char str[50];
            printf("enter a string to check is palindrome\n");
            scanf("%s", str);
            checkpalindrome(str);
            break;

            case 6:
            printf("exited!\n");
            break;

            default : printf("invalid choice\n");
            break;
        }
    }while(ch!=6);
    return 0;
}

