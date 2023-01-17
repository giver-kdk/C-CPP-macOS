#include <stdio.h>
#include <stdlib.h>

struct DLL
{
	int data;
	struct DLL * prevptr;
	struct DLL * nextptr;
};
struct DLL * head = NULL;

int main()
{
	// Driver Code
}

void addbeg(struct DLL * head, int num)
{
	struct DLL * newnode = (struct DLL *) malloc(sizeof(struct DLL));
	newnode->data = num;
	newnode->nextptr = newnode->prevptr = NULL;
	if(head == NULL)
	{
		head = newnode;
	}
	else
	{
		newnode->nextptr = head;
		head->prevptr = newnode;
		head = newnode;
	}
}

void addend(struct DLL * head, int num)
{
	struct DLL * temp;
	struct DLL * newnode = (struct DLL *) malloc(sizeof(struct DLL));
	newnode->data = num;
	newnode->nextptr = newnode->prevptr = NULL;
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
		newnode->prevptr = temp;
	}
}

void delbeg(struct DLL * head)
{
	struct DLL * temp;
	if(head == NULL)
	{
		printf("Linked List doesn't exist");
	}
	else
	{
		temp = head;
		head = head->nextptr;
		head->prevptr = NULL;
		printf("Deleted item is % d", temp->data);
		free(temp);
	}
}

void delend(struct DLL * head)
{
	struct DLL * temp1;
	struct DLL * temp;
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

void display(struct DLL * head)
{
	int count = 0;
	struct DLL * temp;
	temp = head;
	while(temp->nextptr != NULL)
	{
		printf("%d\t", temp->data);
		count++;
		temp = temp->nextptr;
	}
	printf("Total elements: %d", count);
}