//ntctk4
//lab E
//lab 7
//ntctk4
//lab code:HAT
#include<stdio.h>
#include<stdlib.h>
#include "set.h"

Set* set_insert(Set* set, int data)//takes in the set pointer and data and checks for duplicate numbers. If no duplicated add the data to a new node.
{

	Set* newPtr = malloc(sizeof(Set));

	if(newPtr != NULL)
	{
		newPtr->data = data;
		newPtr->next = NULL;
	
		Set* previousPtr = NULL;
		Set* currentPtr = set;

		while( currentPtr != NULL && data != currentPtr->data)
		{
			previousPtr = currentPtr;
			currentPtr = currentPtr->next;
		}

		if(currentPtr == NULL)
		{
			newPtr -> next = set;
			return newPtr;
		}
		else 
			return set;
	}
}

Set* set_remove(Set* set, int data)//checks data from argument and removes the node with the same data value.
{
	Set* previousPtr = NULL;
	Set* currentPtr = NULL;
	Set* tempPtr = NULL;

	if(data == set->data)
	{
		tempPtr = set;
		set = set->next;
		free(tempPtr);
	}

	else
	{
		previousPtr = set;
		currentPtr = set->next;

		while( currentPtr != NULL && currentPtr->data != data)
		{
			previousPtr = currentPtr;
			currentPtr = currentPtr->next;
		}

		if(currentPtr != NULL)
		{
			tempPtr = currentPtr;
			previousPtr->next = currentPtr->next;
			free(tempPtr);
		}


	}
	return set;
}


Set* set_intersection(Set* first, Set* second)//checks two sets for similar numbers. If they have a match then that data value goes in to a new node in a third set list. Returns the head of the third set list.
{
	Set* currentFirst = NULL;
	Set* currentSecond = NULL;
	Set* third = NULL;
	

	for(currentFirst = first; currentFirst != NULL; currentFirst = currentFirst->next)
	{
		for(currentSecond = second; currentSecond != NULL; currentSecond = currentSecond->next)
		{
			if(currentFirst->data == currentSecond->data)
			{
				third = set_insert(third, currentFirst->data);
			}
		}
	}
	return third;
}

void print_set(Set* set)// takes in a set list and goes through it and prints out the data value.
{
	Set* current = NULL;

	for(current = set; current != NULL; current = current->next)
	{
		printf(" %d ->", current->data);
	}

	printf(" NULL\n");
}

void free_set(Set* set)//takes in a set linked list and frees up all the nodes in the linked list. 
{
	Set* tempPtr = NULL;

	while(set != NULL)
	{
		tempPtr = set;
		set = set->next;
	       free(tempPtr);
	}
}	

