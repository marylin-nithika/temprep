#include <stdio.h>


void iseven(int n);
void isodd(int n);

void iseven(int n){
    if(n==0){
        printf("Even\n");
    }
    else{
        isodd(n-1);
    }
}

void isodd(int n){
    if(n==0){
        printf("Odd\n");
    }
    else{
        iseven(n-1);
    }
}