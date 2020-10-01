/*
 *Nathaniel Callahan
 *ntctk4
 *hw4
 *lab E
 *
 * */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "stackQueue.h"


void push(Stack** s, BST* root)//Adds a new node to the top of the stack if space is available to create a new node. returns nothing. 
{
	Stack* newPtr;

	newPtr = malloc(sizeof(Stack));

	if(newPtr != NULL)
	{
		newPtr->data = root;
		newPtr->next = (*s);
		(*s) = newPtr;
	}
	else
	{
		printf("Node not inserted. No memeory available.\n");
	}
}

BST* top(Stack* s)// checks the value of the top node in the stack and returns that value.
{
	BST* tempPtr = NULL;

	tempPtr = s->data;

	return tempPtr;
}

void pop(Stack** s)//takes the top node out of the stack. returns nothing.
{
	Stack* tempPtr = NULL;
	
	tempPtr = (*s);

	(*s) = (*s)->next;

	free(tempPtr);
}

int isEmpty(Stack* s)//Checks to see if stack is empty. true returns 1 false returns 0.
{
	return s == NULL ? 1 : 0;
}

void enqueue(Stack** queue, BST* root)//adds a node to the back of the queue if a new node can be created.Returns nothing.
{
	Stack* newPtr = malloc(sizeof(Stack));

	if(newPtr != NULL)
	{
		newPtr->data = root;
		newPtr->next = NULL;
	}

	if((*queue) == NULL)
	{
		(*queue) = newPtr;
		return;
	}

	Stack* tempPtr = (*queue);

	while((*queue)->next != NULL)
	{
		(*queue) = (*queue)->next;
	}

	(*queue)->next = newPtr;
	(*queue) = tempPtr;
	return;
}

BST* dequeue(Stack** queue)//takes node out of linked list that has been in the longest. Returns a tree node form the balanced BST.
{
	Stack* tempPtr = NULL;
	BST* data;

	data = (*queue)->data;
	tempPtr = (*queue);
	(*queue) = (*queue)->next;

	free(tempPtr);
	return data;
}






