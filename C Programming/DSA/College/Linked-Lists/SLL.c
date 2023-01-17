// Program to implement Single Linked List
#include <stdio.h>
#include <stdlib.h>

struct SLL
{
	int data;
	struct SLL *nextptr;
};
struct SLL *header = NULL;


void addbeg(struct SLL *head, int num)
{
	struct SLL *newNode;
	newNode = (struct SLL *) malloc(sizeof(struct SLL));
	newNode->data = num;
	newNode->nextptr = NULL;

	if(head == NULL)
	{
		header = newNode;
		printf("NULL Haha");
	}
	else
	{
		newNode->nextptr = header;
		header = newNode;
		printf("\nNew node has been added from beginning");
	}
}
void addend(struct SLL *head, int num)
{
	struct SLL *newNode, *temp;
	newNode = (struct SLL *) malloc(sizeof(struct SLL));
	newNode->data = num;
	newNode->nextptr = NULL;
	if(head == NULL)
	{
		header = newNode;
	}
	else
	{
		temp = header;
		while(temp->nextptr != NULL)
		{
			temp = temp->nextptr;
		}
		temp->nextptr = newNode;
	}
	printf("\nNew node has been added from end");
}
void delbeg(struct SLL *head)
{
	struct SLL *temp;
	if(head == NULL)
	{
		// Print No Linked List 
		printf("Linked list is empty");
	}
	else
	{
		temp = header;
		header = header->nextptr;
		// Print temp->data
	}
	printf("\nNode has been deleted from beginning");
}
void delend(struct SLL *head)
{
	struct SLL *temp1, *temp;
	if(head == NULL)
	{
		// Print No Linked List 
		printf("Linked list is empty");
	}
	else
	{
		temp = header;
		while(temp->nextptr != NULL)
		{
			temp1 = temp;
			temp = temp->nextptr;
		}
		temp1->nextptr = NULL;
		// Print temp->data
	}
	printf("\nNode has been deleted from end");
}

void display(struct SLL *head)
{
	if(head == NULL)
	{
		// Print Empty
		printf("Linked list is empty");
	}
	else
	{
		struct SLL *temp;
		temp = header;
		printf("\n%d", temp->data);
		while(temp->nextptr != NULL)
		{
			// print temp->data
			temp = temp->nextptr;
			printf("\n%d", temp->data);
		}
	}
}
void count(struct SLL *head)
{
	int count = 0;
	if(head == NULL)
	{
		// Print Empty
		printf("Linked list is empty");
	}
	else
	{
		struct SLL *temp;
		temp = header;
		while(temp->nextptr != NULL)
		{
			count++;
			temp = temp->nextptr;
		}
		count++;
		printf("There are %d nodes in Linked List", count);
		// priunt "count"
	}
}

int main()
{
	int num, choice;
	printf("1. Add Beginning\n2. Add End\n3. Display\n4. Delete Begining\n5. Delete End\n6. Count\n7. Exit\n");
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
				count(header);
				break;
			case 7:
				exit(0);
				break;
			
		}
	}
	return 0;
}