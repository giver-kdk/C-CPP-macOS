#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define SIZE 5
int top = -1;

void push(int stack[], int num);
void pop(int stack[]);
void display(int stack[]);

int main()
{
	int num, choice, stack[50];

	printf("1. PUSH\n2. POP\n3. Display\n4. Exit\n");
	while (1)
	{
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("\nEnter the number you want to push: ");
			scanf("%d", &num);
			push(stack, num);
			break;
		case 2:
			pop(stack);
			break;
		case 3:
			display(stack);
			break;
		case 4:
			exit(0);
		}
	}
}
void push(int stack[], int num)
{
	if (top >= SIZE - 1)
	{
		printf("Stack Overflow");
	}
	else
	{
		top++;
		stack[top] = num;
	}
}
void pop(int stack[])
{
	if (top == -1)
	{
		printf("Stack Underflow");
	}
	else
	{
		int dt = stack[top];
		printf("The deleted item is %d", dt);
		top--;
	}
}
void display(int stack[])
{
	int i;
	if(top == -1)
	{
		printf("Stack is empty");
	}
	else
	{
		printf("The stack items are: \n");
		for(i = top; i >= 0; i--)
		{
			printf("%d\n", stack[i]);
		}
	}
}