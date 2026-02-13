#include<stdio.h>
#define max 5
char queue[max];
int front = -1;
int rear = -1;

void enqueue(char ch){
    if((rear+1)%max == front){
        printf("queue overflow");
    }
    else if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = ch;
    }
    else
    {
        rear = (rear + 1)%max;
        queue[rear] = ch;
    }
    printf("Element %c has been enequed",ch);
}

void dequeue(){
    if(front == -1 && rear == -1){
        printf("queue is empty\n");
    }
    else if(front == rear)
    {
        printf("%d has been dequed",queue[front]);
        front = rear = -1;
    }
    else{
        printf("%d has been dequeued", queue[front]);
        front = (front + 1)%max;
    }
}

void display(){
    int i = front;
    printf("The elements of the queue are\n");
    while(i!=rear){
        printf("%c ",queue[i]);
        i = (i+1)%max;
    }
}

int main() { 
    int choice; 
    char item; 
 
    while (1) { 
        printf("\n--- Circular Queue Menu ---\n"); 
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n"); 
        printf("Enter choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
        case 1: 
            printf("Enter character: "); 
            //leave space here idk why
            scanf(" %c", &item); 
            enqueue(item); 
            break; 
        case 2: 
            dequeue(); 
            break; 
        case 3: 
            display(); 
            break; 
        case 4: 
            return 0; 
        default: 
            printf("\nInvalid choice!\n"); 
        } 
    } 
}