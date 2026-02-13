#include<stdio.h>

void bubblesort(int arr[], int size){
    int i, j, temp;
    for(i =0; i<size; i++){
        for(j=0; j<size-i-1; j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("Sorted elements\n");
    for(i=0; i<size; i++){
        printf("%d\n",arr[i]);
    }
    printf("\n");
}

void BinarySearch(int arr[], int size, int key){
    int low = 0;
    int high = size-1;
    int flag = 0;
    while(low<=high){
        int mid = (low + high)/2;
        if(key==arr[mid]){
            printf("Element %d has been found at position %d\n",key,mid);
            flag = 1;
            break;
        }
        else if(key<mid){
            high = mid-1;
        }
        else{
            low = low + 1;
        }
    }

    if(flag==0){
        printf("Element not found\n");
    }
}

int main(){
    int i, arr[100];
    int n;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    printf("Enter array elements :\n");
    for(i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    bubblesort(arr, n);

    int key;
    printf("Enter the element to be searched\n");
    scanf("%d",&key);

    BinarySearch(arr, n, key);
return 0;
}