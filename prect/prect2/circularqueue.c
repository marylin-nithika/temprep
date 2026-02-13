#include<stdio.h>
#define max 5

int queue[max];
int front = -1;
int rear = -1;


void enqueue(int x){
    if(((rear+1)%max) == front)
    {
        printf("queue is full\n");
    }
    else if(rear == -1){
        rear = 0;
        queue[rear] = x;
    }
    else{
        queue[(rear+1)%max] = x;
    }
}

void dequeue(){
    if(front == -1){
        printf("queue underflow\n");
    }
    else if(rear == front){
        front = -1;
        rear = -1;
        printf("element has been dequeued\n");
    }
    else{
        int x = queue[front];
        printf("element %d has been dequeued",x);
        front = (front+1)%max;
    }
}

void display(){
    int i = front;

    while(i!=rear){
        printf("%d", queue[i]);
        i = (i+1)%max;
    }
}

