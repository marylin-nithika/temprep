#include <stdio.h>

void odd();
void even();

int n = 1;

void odd(){
    if(n<=10){
        printf("%d ",n+1);
        even();
    }
    return;
}

void even(){
    if(n<=10){
        printf("%d ",n-1);
        odd();
    }
    return;
}

void main(){
    odd();
}
