#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define max_size 20

char stack[max_size];
int top = -1;

int isempty(){
    return top == -1; 
}

int isfull(){
    return top == max_size-1;
}

void push(char x){
    return stack[++top] = x;
}

char pop(){
    if(!isempty()){
        return stack[top--];
    }
    else{
        return '\0';
    }
}

int precedence(char x){
    if(x=='^'){
        return 2;
    }
    else if(x=='*'||x=='/'){
        return 2;
    }
    else if(x=='+'||x=='-'){
        return 1;
    }
    else{
        return 0;
    }
}

void convertinfix(char *e){

    int len = strlen(e);

    int stack2[len+1];
    int k =0; 
    int i;
    for(i=0; i<len; i++){

        //print the operands as they arrive. 
        if(isalnum(e[i])){
            stack2[k++] = e[i];
        }

        //push the ( operator into the stack;
        else if(e[i]== '('){
            push(e[i]);
        }

        //pop the operators until u reach '('
        else if(e[i] == ')'){
            while(!isEmpty() && stack[top] != '('){
                stack2[k++] = pop();
            }

            //pop the '(' too
            if(!isempty()){
                stack2[k++] = pop();
            }
            else{
                printf("Invalid expression.");
                return;
            }
        }

        else if(e[i]== '^' || e[i]== '*'||e[i]=='/'||e[i]=='-'||e[i]=='+')
        {
            while(!isempty() && precedence(e[i])<=precedence(stack[top])){
                stack2[k++] = pop();
            }
            push(e[i]);
        }
        else{
            printf("Invalid symbols used.\n");
        }
    }
    while(!isempty()){
        if(stack[top] == '('){
            printf("Invalid postfix expression\n");
            return;
        }
        stack2[k++] = pop();
    }

    stack2[k++] = '\0';
    printf("Postfix expression is : %s\n"); 
}

int main(){
    char exp[20];
    char *e;

    printf("Enter the expression : ");
    scanf("%s",exp);

    e = exp;
    convertInfix(e);

    return 0;
}





