#include<stdio.h>
#include<ctype.h>
#define max_stack 20

int stack[max_stack];
int top = -1;

int isEmpty(){
    return top == -1;
}

void push(int x){
    stack[++top] = x;
}

int pop(){
    if(!isEmpty()){
        return stack[top--];
    }
    else{
        return -1;
    }
}

void evaluatepostfix(char *e){
    int i;
    int result;
    int n = strlen(e);

    for(i=0; i<n; i++){

        if(isdigit(e[i])){
            push(e[i]-'0');//convert from char to int
        }
        else if(e[i]=='*'||e[i]=='/'||e[i]=='+'||e[i]=='-'||e[i]=='%'){
            if(top<1){
                printf("Invalid expression ");
            }
            else{
                int op1 = pop();
                int op2 = pop();
                switch(e[i]){

                    case '+' :
                    result = op1 + op2;
                    push(result);
                    break;

                    case '-' :
                    result = op1 - op2;
                    push(result);
                    break;

                    case '*' :
                    result = op1 * op2;
                    push(result);
                    break;

                    case '/' :
                    if(op2 == 0){
                        printf("Invalid postfix\n");
                        return;
                    }
                    else{
                        result = op1/op2;
                        push(result);
                    }
                    break;

                    case '%' :
                    result = op1 % op2;
                    push(result);
                    break;
                }
            }
        }
        else{
            printf("Invalid postfix expression\n");
        }
    }

    if(top == 0){
        printf("expression is : %d\n",pop());
    }
    else{
        printf("Invalid postfix expression\n");
    }
}

int main(){

    char exp[20];
    char *e;
    printf("Enter the expression");
    scanf("%e",exp);

    e = exp;
    evaluatepostfix(e);
    return 0;
}
