#include <stdio.h>
#include <stdlib.h>


void main()
{
    int n;
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    printf("\n");

    int *arr;
    int i;

    arr = (int*)calloc(n,sizeof(int));

    if(arr == NULL){
        printf("allocation failed\n");
        return;
    }

    printf("Array elements are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("Enter the elements of the array : \n");
    for(i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    printf("Array elements are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}