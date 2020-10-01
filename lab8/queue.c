/*
 *Nathaniel Callahan
 *ntctk4
 *lab 8 
 *lab code:Pumpkin
 *
 * */
#include<stdio.h>
#include<stdlib.h>
#include "queue.h"
#include<string.h>

Queue* enqueue(Queue* queue, char* data)//Adds nodes in to a linked list sorted as a queue, first in first out.
{
	Queue* newPtr = malloc(sizeof(Queue));
	

	if(newPtr != NULL)
	{
		newPtr->data = malloc(sizeof(char)* strlen(data) +1);
		
		strcpy(newPtr->data, data);
		newPtr->next = NULL;
	}

	if(queue == NULL)
	{
		queue = newPtr;
		return queue;
	}
	
	

	Queue* tempPtr = queue;	
	
		while(queue->next != NULL)
		{
			
			queue = queue->next;
		}
		queue->next  = newPtr;
		return tempPtr;
	
	
}

char* dequeue(Queue** queue)//removes nodes from a linked list like a queue, first in first out. The node added first will be removed first. returns the string that was in the deleted node.
{
	
	char* data = NULL;
	Queue* tempPtr = NULL;




	data = (*queue)->data;
	tempPtr = (*queue);
	(*queue)  = (*queue)->next;
	
	
	return data;
}

int size(Queue* queue)//takes a linked list and counts the number of nodes and returns that value to main.
{

	int i = 0;

	
	while(queue != NULL)
	{
		i++;
		queue = queue->next;
		
	}
		

	return i;
}
