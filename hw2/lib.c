/*
 *Nathaneil Callahan
 *ntctk4
 *HW2
 *
 *
 * */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "lib.h"

Seat* create_seat(char* fName, char* lName, char* origin, char* dest, int num)//Takes the data from mian from the txt file and puts all the data into one node for the linked list
{
	Seat* newPtr = malloc(sizeof(Seat));

	if(newPtr != NULL)
	{
		newPtr->fName = malloc(sizeof(fName));
		newPtr->lName = malloc(sizeof(lName));
		newPtr->origin = malloc(sizeof(origin));
		newPtr->dest = malloc(sizeof(dest));


		strcpy(newPtr->fName, fName);
		strcpy(newPtr->lName, lName);
		strcpy(newPtr->origin, origin);
		strcpy(newPtr->dest, dest);
		(newPtr)->seatNumber = num;
		newPtr->next = NULL;

	}
	return newPtr;
}

void empty_seat(Seat** seat)//Takes a seat node and frees all the data in the node, then frees the node to it can't be used anymore.
{


		free((*seat)->fName);
		free((*seat)->lName);
		free((*seat)->origin);
		free((*seat)->dest);
		free(*seat);
}

Seat* check_in(Seat* plane, Seat* seat)// Puts the nodes into the linked list in sorted order based on the seatNumber.
{

	Seat* tempPtr = NULL;

	if(plane == NULL)
	{

			return seat;
		
	}

	if(plane->seatNumber >  seat->seatNumber)
	{
		seat->next = plane;
		return seat;
		
	}

	else
	{

		plane->next  = check_in(plane->next, seat);
	
	}
	return plane;
}

Seat* land(Seat* plane, char* location)//checks to see if location value is the same as dest value in each node. If they equal each other then the empty seat function is called to deleate the node.
{

	Seat* tempPtr = NULL;

	if(plane == NULL)
		return plane;

	int result = strcmp(plane->dest, location);

	if(result == 0)
	{
		printf("%s %s left the plane in %s\n", plane->fName, plane->lName, plane->dest);
		tempPtr = plane;
		plane = plane->next;
		empty_seat(&tempPtr);
		plane = land(plane, location);
	}

	else
	{

		
		plane->next = land(plane->next, location);
	}

		return plane;
}

