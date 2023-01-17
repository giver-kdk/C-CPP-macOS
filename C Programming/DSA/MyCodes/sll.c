#include <stdio.h>
#include <stdlib.h>

struct SLL
{
	int data;
	struct SLL * nextptr;
};
struct SLL * head = NULL;

int main()
{
	// Driver Code
}

void addbeg(struct SLL * head, int num)
{
	struct SLL * newnode = (struct SLL *) malloc(sizeof(struct SLL));
	newnode->data = num;
	newnode->nextptr = NULL;
	if(head == NULL)
	{
		head = newnode;
	}
	else
	{
		newnode->nextptr = head;
		head = newnode;
	}
}

void addend(struct SLL * head, int num)
{
	struct SLL * temp;
	struct SLL * newnode = (struct SLL *) malloc(sizeof(struct SLL));
	newnode->data = num;
	newnode->nextptr = NULL;
	if(head == NULL)
	{
		head = newnode;
	}
	else
	{
		temp = head;
		while(temp->nextptr != NULL)
		{
			temp = temp->nextptr;
		}
		temp->nextptr = newnode;
	}
}

void delbeg(struct SLL * head)
{
	struct SLL * temp;
	if(head == NULL)
	{
		printf("Linked List doesn't exist");
	}
	else
	{
		temp = head;
		head = head->nextptr;
		printf("Deleted item is % d", temp->data);
		free(temp);
	}
}

void delend(struct SLL * head)
{
	struct SLL * temp1;
	struct SLL * temp;
	if(head == NULL)
	{
		printf("Linked List Doesn't Exist");
	}
	else
	{
		temp = head;
		while(temp->nextptr != NULL)
		{
			temp1 = temp;
			temp = temp->nextptr;
		}
		temp1->nextptr = NULL;
		free(temp);
	}
}

void display(struct SLL * head)
{
	int count = 0;
	struct SLL * temp;
	temp = head;
	while(temp->nextptr != NULL)
	{
		printf("%d\t", temp->data);
		count++;
		temp = temp->nextptr;
	}
	printf("Total elements: %d", count);
}