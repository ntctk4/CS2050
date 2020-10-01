#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct node_
{
	int data;
	struct node_ *left;
	struct node_ *right;
} BST;

BST* build_balanced_tree(int a[], int low, int high);

void padding(char ch, int n)
{
	int i;
	
	for (i=0; i < n; ++i)
	{
		putchar(ch);
	}
}

void structure(BST* root, int level)
{
	int i;

	if (root == NULL)
	{
		padding('\t', level);
		puts("~");
	}
	else
	{
		structure(root-> right, level+1);
		padding('\t', level);
		printf("%d\n", root->data);
		structure(root->left, level+1);
	}
}

int main(void)
{
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	BST* root = build_balanced_tree(a, 0, 8);

	structure(root, 0);

	assert(root != NULL);
	assert(root->data ==5);
	assert(root->left != NULL);
	assert(root->left->data == 2);
	assert(root->left->left->data == 1);
	assert(root->left->left->left == NULL);
	assert(root->left->left->right == NULL);
	assert(root->left->right != NULL);
	assert(root->left->right->data == 3);
	assert(root->left->right->left ==NULL);
	assert(root->left->right->right != NULL);
	assert(root->left->right->right->data == 4);
	assert(root->left->right->right->left == NULL);
	assert(root->left->right->right->right == NULL);

	assert(root->right != NULL);
	assert(root->right->data == 7);
	assert(root->right->left != NULL);
	assert(root->right->left->data == 6);
	assert(root->right->left->right == NULL);
	assert(root->right->left->left == NULL);
	assert(root->right->right != NULL);
	assert(root->right->right->data == 8);
	assert(root->right->right->left == NULL);
	assert(root->right->right->right != NULL);
	assert(root->right->right->right->data == 9);
	assert(root->right->right->right->left == NULL);
	assert(root->right->right->right->right == NULL);
	assert(root->right->right->left == NULL);

	printf("Yay!\n");

	return 0;
}

BST* insert(int data)
{
	BST* root = malloc(sizeof(BST));

	root->data = data;
	root->left = NULL;
	root->right = NULL;
	
	return root;
}

BST* build_balanced_tree(int a[], int low, int high)
{
	if(low>high)
		return NULL;

	int mid = (low+high)/2;
	BST* root = insert(a[mid]);

	root->left = build_balanced_tree(a, low, mid-1);

	root->right = build_balanced_tree(a, mid+1, high);

	return root;
}
