#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int queue[SIZE];
int front = SIZE - 1;
int rear = SIZE - 1;

void enqueue(int queue[], int num);
void dequeue(int queue[]);
void display(int queue[]);

int main()
{
	int number, choice;
	printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit");
	while (1)
	{
		printf("\nEnter you choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("\nEnter the number you want to enqueue: ");
			scanf("%d", &number);
			enqueue(queue, number);
			break;
		case 2:
			dequeue(queue);
			break;
		case 3:
			display(queue);
			break;
		case 4:
			exit(0);
		}
	}
}

void enqueue(int queue[], int num)
{
	if ((rear + 1) % SIZE == front)
	{
		printf("\nQueue Overflow");
	}
	else
	{
		rear = (rear + 1) % SIZE;
		queue[rear] = num;
	}
}
void dequeue(int queue[])
{
	int item;
	if (front == rear)
	{
		printf("\nQueue Underflow");
	}
	else
	{
		front = (front + 1) % SIZE;
		item = queue[front];
		printf("\nDeleted item is %d", item);
	}
}
void display(int queue[])
{
	int i;
	if (front == rear)
	{
		printf("\nQueue is Empty");
	}
	else
	{
		printf("\nQueue items are: \n");
		for (i = (front + 1) % SIZE; i != (rear + 1) % SIZE; i = (i + 1) % SIZE)
		{
			printf("%d\t", queue[i]);
		}
	}
}
