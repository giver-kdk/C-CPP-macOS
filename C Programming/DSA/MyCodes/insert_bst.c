#include <stdio.h>
struct node
{
	int key;
	struct node * left;
	struct node * right;
};
struct node * root = NULL;

struct node * newNode(int key)
{
	struct node * temp = (struct node *) malloc(sizeof(struct node));
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
}

struct node * insert(struct node * root, int key)
{
	if(root == NULL)
	{
		return newNode(key);
	}
	if(key <= root->key)
	{
		root->left = insert(root->left, key);
	}
	if(key > root->key)
	{
		root->right = insert(root->right, key);
	}
	return root;
}
