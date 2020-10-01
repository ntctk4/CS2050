/*
 * Nathaniel Callahan
 * lab 9
 * labe code:LEGO
 *
 * */

#include<stdio.h>
#include<stdlib.h>
#include "bst.h"

BST* insert(BST* tree, int data)// inserts the nodes into the bianry tree and returns the root of the tree.
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

	if(data <= tree->data)
	{
		tree->left = insert(tree->left, data);
	}

	else if(data > tree->data)
	{
		tree->right = insert(tree->right, data);
	}
	return tree;
}

BST* find(BST* tree, int data)//checks to see if data value is in BST if it is the tree is returned if not NULL is returned.
{
	
	if(tree == NULL)
		return NULL;
	
	
	if(data == tree->data)

		return tree;

	if(data < tree->data)
	{
		return find(tree->left, data);
	}

	else if(data > tree->data)
	{
		return find(tree->right, data);
	}


}

void inorder(BST* tree)//Prints out teh BST by using inorder traversal
{
	if(tree != NULL)
	{
		inorder(tree->left);
		printf(" %d", tree->data);
		inorder(tree->right);
	}
}

void print(BST* tree)//frees all the nodes in the binary tree.
{

	if(tree != NULL)
	{
		print(tree->left);
		print(tree->right);
		free(tree);
	}
}
