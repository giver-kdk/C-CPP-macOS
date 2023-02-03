#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node * left;
	struct node * right;
};
struct node * root = NULL;

struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

int search(struct node* root, int data) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == data) {
        return 1;
    }
    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}
void display(struct node* root) {
    if (root == NULL) {
        return;
    }
    display(root->left);
    printf("%d ", root->data);
    display(root->right);
}

int main() 
{
	int choice, key;
	while(1)
	{
		printf("Enter your choice:");
		printf("\n1. Insert BST\n2. Search BST\n3. Exit\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: 
				printf("Enter key to insert in BST: ");
				scanf("%d", &key);
				root = insert(root, key);
				printf("BST after insertion is: ");
				display(root);
				break;
			case 2: 
				printf("Enter key to search in BST: ");
				scanf("%d", &key);
				if (search(root, key)) 
				{
					printf("Value found in the tree.\n");
				} 
				else 
				{
					printf("Value not found in the tree.\n");
    			}
				break;
			case 3: 
				exit(0);
				break;
			default:
				printf("Invalid Choice!!!");
		}
	}
    return 0;
}