#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node *left, *right;
};

struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

struct node *insert(struct node *node, int key) {
  /* If the tree is empty, return a new node */
  if (node == NULL) return newNode(key);

  /* Otherwise, recur down the tree */
  if (key < node->key)
    node->left = insert(node->left, key);
  else if (key > node->key)
    node->right = insert(node->right, key);

  /* return the (unchanged) node pointer */
  return node;
}

struct node *minValueNode(struct node *node) {
  struct node *current = node;

  /* loop down to find the leftmost leaf */
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

struct node *deleteNode(struct node *root, int key) {
  /* base case */
  if (root == NULL) return root;

  /* If the key to be deleted is smaller than the root's key,
     then it lies in the left subtree */
  if (key < root->key)
    root->left = deleteNode(root->left, key);

  /* If the key to be deleted is greater than the root's key,
     then it lies in the right subtree */
  else if (key > root->key)
    root->right = deleteNode(root->right, key);

  /* if key is same as root's key, then This is the node
     to be deleted */
  else {
    /* node with only one child or no child */
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    /* node with two children: Get the inorder successor (smallest
       in the right subtree) */
    struct node *temp = minValueNode(root->right);

    /* Copy the inorder successor's content to this node */
    root->key = temp->key;

    /* Delete the inorder successor */
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

void inorder(struct node *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
  }
}

int main() {
  struct node *root = NULL;
  root = insert(root, 50);
  root = insert(root, 30);
  root = insert(root, 20);
}