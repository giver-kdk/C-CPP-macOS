#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int front = SIZE - 1;
int rear = SIZE - 1;

void Enqueue(int cQueue[], int num);
void Dequeue(int cQueue[]);
void display(int cQueue[]);

int main()
{
    int num, choice, cQueue[50];
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
void Enqueue(int cQueue[], int num)
{
	if((rear + 1) % SIZE == front)
	{
		printf("Queue Overflow");
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
	if(rear == front)
	{
		printf("Queue Underflow");
	}
	else
	{
		front = (front + 1) % SIZE;
		dt = cQueue[front];
		printf("The deleted iutem is %d", dt);
	}
}
void display(int cQueue[])
{
	int i;
	if(rear == front)
	{
		printf("Queue is empty");
	}
	else
	{
		for(i = (front + 1) % SIZE; i != (rear + 1) % SIZE; i = (i + 1) % SIZE)
		{
			printf("%d\t", cQueue[i]);
		}
	}
}

