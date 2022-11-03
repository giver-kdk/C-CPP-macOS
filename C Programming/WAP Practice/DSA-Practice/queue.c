#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int front = 0;
int rear = -1;

void Enqueue(int queue[], int num);
void Dequeue(int queue[]);
void display(int queue[]);


int main()
{
    int num, choice, queue[50];
    printf("1. Enqueue\n2. Dequeue \n3. Display\n4. Exit");
    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
			case 1:
				printf("Enter the no. you want: ");
				scanf("%d", &num);
				Enqueue(queue, num);
				break;
			case 2:
				Dequeue(queue);
				break;
			case 3:
				display(queue);
				break;
			case 4:
				exit(0);
        }
    }
    return 0;
}

void Enqueue(int queue[], int num)
{
	if(rear == SIZE - 1)
	{
		printf("Queue Oveflow");
	}
	else
	{
		rear++;
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
		int dt = queue[front];
		front++;
		printf("The deleted item is: %d", dt);
	}
}
void display(int queue[])
{
	int i;
	if(rear < front)
	{
		printf("Queue is Empty");
	}
	else
	{
		for(i = front; i <= rear; i++)
		{
			printf("%d\t", queue[i]);
		}
	}
}