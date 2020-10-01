/*
 *Nathaniel Callahan
 *ntctk4
 *HW2
 *
 *
 * */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "lib.h"


int main(int argc, char* argv[])//main opens each file and takes the data and calls crate seat to make a node and check in to put in sorted linked list. main uses the file name as the origin of the passengers. The land function is called to deleate nodes at there dest value. One the last text file is read main calls empty seat to release the rest of the nodes after the last stop.

{
	int i = 0;
	int seatNumber;
	char* fName = malloc(sizeof(char*));
	char* lName = malloc(sizeof(char*));
	char* dest = malloc(sizeof(char*));


	if(argc < 3)//for argument plane, and needs at least one origin and one destination.
	{
		printf("\n Incorrect number of command line arguments\n");
		return 0;
	}

	Seat* seat = NULL;
	Seat* plane = malloc(sizeof(Seat*));
	plane->dest = malloc(sizeof(char*));

	for(i=1; i<argc; i++)
	{

		FILE* file=fopen(argv[i], "r");

		argv[i][strlen(argv[i])-4] = '\0';

		plane = land(plane, argv[i]);


		if(file==NULL)
		{
			printf("No passengers found");
		
		}	
		else
		{	
			while(fscanf(file, "%s %s %s %d", fName, lName, dest, &seatNumber) != EOF)
			{	

				seat = create_seat(fName, lName, argv[i], dest, seatNumber);
				plane = check_in(plane, seat);
				printf("%s %s got on the plane in %s\n", fName, lName, argv[i]);
			}	
			
			fclose(file);
		}
	}

	Seat* previousPtr = plane;
	Seat* currentPtr = plane->next;

	while(currentPtr != NULL)
	{
		empty_seat(&previousPtr);
		previousPtr = currentPtr;
		currentPtr = currentPtr->next;
	}
		empty_seat(&previousPtr);
		free(fName);
		free(lName);
		free(dest);

	return 0;
}



