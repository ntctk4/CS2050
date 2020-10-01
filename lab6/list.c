//ntctk4

#include<stdio.h>
#include<stdlib.h>
#include "list.h"



node* insert_at_head(node* list, int data)//takes in a node and the data value to put into a node and return a pointer for that node to continue the linked list.
{
	node* newPtr = malloc(sizeof(node));

	if(newPtr != NULL)
	{
		newPtr->data = data;
		newPtr->next = list;
	}
	

	return newPtr;
}


void print_list(node* list)//takes node at start of list and print out the linked list data values for the user
{
	node* current = NULL;

	for(current = list; current != NULL; current = current->next)
	{
		printf(" %d ->", current->data);
	}

	

		printf(" NULL\n");
}

void free_list(node* list)//frees all the nodes so there isn't a memory leak.
{
	node* tempPtr = NULL;
	
	while(list != NULL)
	{
		tempPtr = list;
		list = list->next;
		free(tempPtr);
	}
}
