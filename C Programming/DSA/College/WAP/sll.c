#include <stdio.h>
#include <stdlib.h>

struct SLL
{
	int data;
	struct SLL *nextptr;
};
struct SLL *head = NULL;

void adddbeg(struct SLL *head, int num)
{
	struct SLL *newNode;
	newNode = (struct SLL *) malloc(sizeof(struct SLL));
	newNode->data = num;
	newNode->nextptr = NULL;
	if(head == NULL)
	{
		head = newNode;
	}
	else
	{
		newNode->nextptr = head;
		head = newNode;
	}
}
void adddend(struct SLL *head, int num)
{
	struct SLL *newNode, *temp;
	newNode = (struct SLL *) malloc(sizeof(struct SLL));
	newNode->data = num;
	newNode->nextptr = NULL;
	if(head == NULL)
	{
		head = newNode;
	}
	else
	{
		temp = head;
		while(temp->nextptr != NULL)
		{
			temp = temp->nextptr;
		}
		temp->nextptr = newNode;
	}
}
void delbeg(struct SLL *head)
{
	struct SLL *temp;
	if(head == NULL)
	{
		// Print No Linked List 
	}
	else
	{
		temp = head;
		head = head->nextptr;
		// Print temp->data
		free(temp);
	}
}
void delend(struct SLL *head)
{
	struct SLL *temp1, *temp;
	if(head == NULL)
	{
		// Print No Linked List 
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
		// Print temp->data
		free(temp);
	}
}

void display(struct SLL *head)
{
	if(head == NULL)
	{
		// Print Empty
	}
	else
	{
		struct SLL *temp;
		temp = head;
		while(temp->nextptr != NULL)
		{
			// print temp->data
			temp = temp->nextptr;
		}
	}
}
void count(struct SLL *head)
{
	int count = 0;
	if(head == NULL)
	{
		// Print Empty
	}
	else
	{
		struct SLL *temp;
		temp = head;
		while(temp->nextptr != NULL)
		{
			count++;
			temp = temp->nextptr;
		}
		// priunt "count"
	}
}