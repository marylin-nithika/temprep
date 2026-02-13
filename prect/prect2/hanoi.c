#include<stdio.h>

void hanoi(int n, char A, char B, char C){
    if(n==1){
        printf("move disks from %c to %c",A,C);
        return;
    }
    else{
        hanoi(n-1,A,C,B);
        printf("move disk from %c to %c", A,C);
        hanoi(n-1,B,A,C);
    }
}

void main(){
    int n=3;

    hanoi(n, 'A','B', 'C');

    return 0;
}
