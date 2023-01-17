#include <stdio.h>
struct node
{
	int key;
	struct node * left;
	struct node * right;
};
struct node * root = NULL;

struct node * search(struct node * root, int key)
{
	if(root == NULL || (root->key) == key)
	{
		return root;
	}
	if(key < (root->key))
	{
		search(root->left, key);
	}
	if(key > (root->key))
	{
		search(root->right, key);
	}
}