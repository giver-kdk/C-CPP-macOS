#include <stdio.h>
#include <stdlib.h>

struct DLL
{
	int data;
	struct DLL * prevptr;
	struct DLL * nextptr;
};
struct DLL * header = NULL;

void addbeg(struct DLL * head, int num)
{
	struct DLL * newnode = (struct DLL *) malloc(sizeof(struct DLL));
	newnode->data = num;
	newnode->nextptr = newnode->prevptr = NULL;
	if(head == NULL)
	{
		header = newnode;
	}
	else
	{
		newnode->nextptr = head;
		header->prevptr = newnode;
		header = newnode;
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
		header = newnode;
	}
	else
	{
		temp = header;
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
		temp = header;
		header = header->nextptr;
		header->prevptr = NULL;
		printf("Deleted item is % d", temp->data);
	}
}

void delend(struct DLL * head)
{
	struct DLL * temp1, *temp;
	if(head == NULL)
	{
		printf("Linked List Doesn't Exist");
	}
	else
	{
		temp = header;
		temp1 = temp;
		while(temp->nextptr != NULL)
		{
			temp1 = temp;
			temp = temp->nextptr;
		}
		temp1->nextptr = NULL;
	}
	printf("\nNode has been deleted from end");
}

void display(struct DLL * head)
{
	int count = 0;
	struct DLL * temp;
	temp = header;
	if(head == NULL)
	{
		// Print No Linked List 
		printf("Linked list is empty");
	}
	printf("%d\t", temp->data);
	while(temp->nextptr != NULL)
	{
		count++;
		temp = temp->nextptr;
		printf("%d\t", temp->data);
	}
	count++;
	printf("Total elements: %d", count);
}

int main()
{
	int num, choice;
	printf("Doubly Linked List:\n");
	printf("1. Add Beginning\n2. Add End\n3. Display\n4. Delete Begining\n5. Delete End\n6. Exit\n");
	while(1)
	{
		printf("\nEnter your choice : ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("\nEnter the number: ");
				scanf("%d", &num);
				addbeg(header, num);
				break;
			case 2:
				printf("\nEnter the number: ");
				scanf("%d", &num);
				addend(header, num);
				break;
			case 3:
				display(header);
				break;
			case 4:
				delbeg(header);
				break;
			case 5:
				delend(header);
				break;
			case 6:
				exit(0);
				break;
			default:
				printf("Invalid Option");
		}
	}
	return 0;
}