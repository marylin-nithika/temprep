#include <stdio.h>

int fact(int n){

    if(n == 0){
        return 1;
    }
    else{
        return n * fib(n-1);
    }
}

void main(){
    int n = 4;
}