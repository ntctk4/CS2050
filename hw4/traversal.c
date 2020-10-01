/**
 *Nathaniel Callahan
 *ntctk4
 *hw4
 *lab E
 *
 * */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "traversal.h"
#include "stackQueue.h"

void preorder(BST* root)//This function traverses the balanced BST in preorder using a stack and prints out the tree's values in preorder.
{

	Stack* s = NULL;

	BST* value = NULL;

	if(root == NULL)
	{
		return;
	}

	push(&s, root);

	while(s != NULL)
	{
	
		value = top(s);
	

		printf(" %d", value->data);



		pop(&s);


		if(value->right != NULL)
		{
			push(&s, value->right);
		}
		if(value->left)
		{
			push(&s, value->left);
		}	
	}

	printf("\n\n");
}


void inorder(BST* root)//This function traverses the balanced BST in inorder using a stack and prints out the tree's values in inorder.
{
	Stack* s = NULL;

	BST* current = root;
	int i = 0;

	if(root == NULL)
	{
		return;
	}
	


	while(!i)
	{
		if(current != NULL)
		{
			push(&s, current);
			current = current->left;
		}

		else
		{
			if(!isEmpty(s))
			{
				current	= top(s);

				pop(&s);

				printf(" %d", current->data);

				current = current->right;
			}

			else
				i = 1;
		}
	}

	printf("\n\n");
}


void breadthFirst(BST* root)//This function traverses the balanced BST in breadth-first traversal using a queue and prints out the tree's values in breadth-first. 
{
	Stack* q = NULL;	
	BST* value = NULL;


	if(root == NULL)
	{
		return;
	}



	enqueue(&q, root);

	while(q != NULL)
	{
		value = dequeue(&q);

		printf(" %d", value->data);

		if(value->left != NULL)
			enqueue(&q, value->left);
		if(value->right != NULL)
			enqueue(&q, value->right);
		free(value);
		value = NULL;
	}

	printf("\n\n");
}



