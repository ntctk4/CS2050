#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct node_
{
	int data;
	struct node_* left;
	struct node_* right;
}BST;

BST* insert(BST* tree, int data);

int main(void)
{
	BST* tree = NULL;

	tree = insert(tree, 5);
	assert(tree->data == 5);
	assert(tree->left == NULL);
	assert(tree->right == NULL);

	tree = insert(tree, 3);
	assert(tree->left != NULL);
	assert(tree->left->data == 3);

	tree = insert(tree, 8);
	assert(tree->right != NULL);
	assert(tree->right->data == 8);

	tree = insert(tree, 6);
	assert(tree->right->left != NULL);
	assert(tree->right->left->data == 6);

	free(tree->right->left);
	free(tree->right);
	free(tree->left);

	printf("You have completed the pre-lab\n");
}

BST* insert(BST* tree, int data)
{
	if(tree == NULL)
	{
		tree = malloc(sizeof(BST));

		if(tree != NULL)
		{
			tree->data = data;
			tree->left = NULL;
			tree->right = NULL;
			return tree;
			
		}
		else
		{
			printf("%d not inserted. No memory available.\n", data);
		}
	}

	
		if(data < tree->data)
		{
			//printf("%d\n", tree->data);
			tree->left  = insert(tree->left, data);
		}

		else if(data > tree->data)
		{
			tree->right = insert(tree->right, data);
		}
	return tree;
}
