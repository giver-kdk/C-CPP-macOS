#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int queue[SIZE];
int front = 0;
int rear = -1;

void Enqueue(int queue[], int num)
{
	if(rear == SIZE - 1)
	{
		printf("Queue Overflow");
	}
	else
	{
		rear = rear + 1;
		queue[rear] = num;
	}
}
void Dequeue(int queue[])
{
	if(rear < front)
	{
		printf("Queue Underflow");
	}
	else
	{
		int data = queue[front];
		front = front + 1;
		printf("Deleted item is %d", data);
	}
}
void Display(int queue[])
{
	if(rear < front)
	{
		printf("Queue is empty");
	}
	else
	{
		int i = 0;
		printf("Queue Items are: \n");
		for(i = front; i <= rear; i++)
		{
			printf("%d\t", queue[i]);
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
				printf("Enter the number to enqueue: ");
				scanf("%d", &num);
				Enqueue(queue, num);
				break;
			case 2: 
				Dequeue(queue);
				break;
			case 3:
				Display(queue);
				break;
			case 4:
				exit(0);
			default: 
				printf("Invalid Choice!");
		}
	}
	return 0;
}
