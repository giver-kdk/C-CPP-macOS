#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int cqueue[SIZE];
int front = SIZE - 1;
int rear = SIZE - 1;

void Enqueue(int cqueue[], int num)
{
	if((rear + 1) % SIZE == front)
	{
		printf("Queue Overflow");
	}
	else
	{
		rear = (rear + 1) % SIZE;
		cqueue[rear] = num;
	}
}																						
void Dequeue(int cqueue[])
{
	if(rear == front)
	{
		printf("Queue Underflow");
	}
	else
	{
		front = (front + 1) % SIZE;
		int data = cqueue[front];
		printf("Deleted Item is: %d", data);
	}
}
void Display(int cqueue[])
{
	if(rear == front)
	{
		printf("Queue is empty");
	}
	else
	{
		int i = 0;
		printf("Circular Queue items are: \n");
		for(i = (front + 1) % SIZE; i != (rear + 1) % SIZE; i = (i + 1) % SIZE)
		{
			printf("%d\t", cqueue[i]);
		}
	}
}

int main ()
{
	int num ,choice;
	printf("1) Enqueue\n2) Dequeue\n3) Display\n4) Exit\n");
	while(1)
	{
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: 
				printf("Enter the number to encqueue: ");
				scanf("%d", &num);
				Enqueue(cqueue, num);
				break;
			case 2: 
				Dequeue(cqueue);
				break;
			case 3:
				Display(cqueue);
				break;
			case 4:
				exit(0);
			default: 
				printf("Invalid Choice!");
		}
	}
	return 0;
}
