/*
 *Nathaniel Callahan
 *ntctk4
 *hw4
 *lab E
 *
 * */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "traversal.h"

#define MAX_SIZE 250


BST* insert(int data);
BST* balanced_BST(int array[], int low, int high);
void structure(BST* root, int level);
void padding(char ch, int n);
void freeTree(BST* root);

int main(int argc, char* argv[])//takes in a file of sorted numbers and puts them in an array.Puts in balanced BST and displays it. calls the three traversal methods to print each one off then frees the balanced BST.
{








	//instead of ./a.out I used ./hw4
	






	int data;
	int i = 0;
	int array[MAX_SIZE] = {0};

	if(argc != 2)
	{
		printf("Incorrect number of command line arguments");
		return 1;
	}

	FILE* fp = fopen(argv[1], "r");

	if(fp == NULL)
	{
		printf("unable to open file: %s\n", argv[1]);
		return 1;
	}

	while(fscanf(fp, "%d", &data) != EOF)
	{
		array[i] = data;
		i++;
	}

	
	BST* tree = balanced_BST(array, 0, i-1);
		

	fclose(fp);

	printf("\nBalanced Binary Search Tree:\n");

	structure(tree, 0);

	printf("\nPreorder Traversal of balanced BST:\n\n");
	
	preorder(tree);

	printf("Inorder Traversal of balanced BST:\n\n");

	inorder(tree);

	printf("BreadthFirst Traversal of balanced BST:\n\n");

	breadthFirst(tree);

	freeTree(tree);

	return 1;
}

BST* insert(int data)//created a node into the balanced BST.
{
	BST* root = malloc(sizeof(BST));

	root->data = data;
	root->left = NULL;
	root->right = NULL;

	return root;
}

BST* balanced_BST(int array[], int low, int high)//goes through the aarray in a binary fashion and puts the data into a balanced binary tree.
{

	if(low>high)
		return NULL;
	
	int mid = (low+high)/2;
	BST* root = insert(array[mid]);
	

	root->left = balanced_BST(array, low, mid-1);

	root->right = balanced_BST(array, mid+1, high);

	return root;
}

void padding(char ch, int n)//used in function structure to display the balanced BST
{
	int i;

	for(i = 0; i<n; ++i)
	{
		putchar(ch);
	}
}

void structure(BST* root, int level)//Displays the balanced BST to the user.
{

	if(root == NULL)
	{
		padding('\t', level);
		puts("~");
	}

	else
	{
		structure(root->right, level+1);
		padding('\t', level);
		printf("%d\n", root->data);
		structure(root->left, level+1);
	}
}

void freeTree(BST* tree)//frees all the nodes in the BST
{
	if(tree != NULL)
	{
		freeTree(tree->left);
		freeTree(tree->right);
		free(tree);
	}
}

		
