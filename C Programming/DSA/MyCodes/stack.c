#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int top  = -1;
int stack[SIZE];

void push(int stack[], int num);
void pop(int stack[]);
void display(int stack[]);

int main ()
{
	int num ,choice;
	printf("1) PUSH\n2) POP\n3) Display\n4) Exit\n");
	while(1)
	{
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: 
				printf("Enter the number to push: ");
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
			default: 
				printf("Invalid Choice!");
		}
	}
	return 0;
}
void push(int stack[], int num)
{
	if(top ==  SIZE - 1)
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
	if(top == -1)
	{
		printf("Stack Underflow");
	}
	else
	{
		int data = stack[top];
		top--;
		printf("Deleted Item is %d", data);
	}
}
void display(int stack[])
{
	if(top == -1)
	{
		printf("Stack is Empty");
	}
	else
	{
		int i = 0;
		printf("Stack Items are:\n");
		for(i = top; i >= 0; i--)
		{
			printf("%d\t", stack[i]);
		}
	}
}