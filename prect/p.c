#include <stdio.h>

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;

    printf("x is %d and y is %d",x,y);
}

void main()
{
    int x,y;
    printf("wnter data to be swapped\n");
    scanf("%d",&x);
    scanf("%d",&y);

    swap(&x, &y);
}