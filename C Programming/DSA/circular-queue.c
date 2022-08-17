// Program to implement circular queue
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int cQueue[SIZE];
int front = SIZE - 1;
int rear = SIZE - 1;

void Enqueue(int cQueue[], int num)
{
    if((rear + 1) % SIZE == front)
    {
        printf("\nQueue Overflow");
    }
    else
    {
        rear = (rear + 1) % SIZE;
        cQueue[rear] = num;
    }
}
void Dequeue(int cQueue[])
{
    int dt;
    if(front == rear)
    {
        printf("\nQueue Underflow");
    }
    else
    {
        front = (front + 1) % SIZE;
        dt = cQueue[front];
        printf("\nDeleted item = %d", dt);
    }
}

void display(int cQueue[])
{
    int i;
    if(rear == front)
    {
        printf("\nQueue is empty");
    }
    else
    {
        printf("\nContent of queue is: \n");
        for(i = (front + 1) % SIZE; i != rear + 1; i = (i + 1) % SIZE)
        {
            printf("%d\t", cQueue[i]);
        }
    }
}

int main()
{
    int num, choice;
    printf("1. Enqueue\n2. Dequeue \n3. Display\n4. Exit");
    while(1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            printf("Enter the no. you want: ");
            scanf("%d", &num);
            Enqueue(cQueue, num);
            break;
            case 2:
            Dequeue(cQueue);
            break;
            case 3:
            display(cQueue);
            break;
            case 4:
            exit(0);
        }
    }
    return 0;
}