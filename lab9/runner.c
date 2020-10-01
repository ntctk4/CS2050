/*
 * Nathaniel Callahan
 * ntctk4
 * lab 9
 * lab code:LEGO
 *
 * */
#include<stdio.h>
#include<stdlib.h>
#include "bst.h"


int main(int argc, char* argv[])//opens an input file to put the data into a BST, calls function to print out the binary tree in inorder traversal, takes third argument and checks to see if it is in the tree with find func., and frees all the nodes with the print func.
{
	BST* tree = NULL;
	int data;

	if(argc < 3)
	{
		printf("\nIncorrect number of command line arguments\n");
		return 0;
	}

	FILE* file = fopen(argv[1], "r");

	if (file==NULL)
	{
		printf("no Input file found");
		return 0;
	}

	while(fscanf(file, "%d", &data) != EOF)
	{
		tree = insert(tree, data);
	}
	fclose(file);

	inorder(tree);

	int checkTree = atoi(argv[2]);

	BST* bst = find(tree, checkTree);

	if(bst != NULL)
	{
		printf("\n%d was found\n", checkTree);
	}
	
	else if(bst == NULL)
	{
		printf("\n%d was not found\n", checkTree);
	}

	print(tree);
	return 0;
}
