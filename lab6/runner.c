/*
 *Nathaniel Callahan
 *ntctk4
 *lab 6
 *LAB CODE: TONY
 *
 **/
#include<stdio.h>
#include<stdlib.h>
#include"list.h"


node* create_list(char* file);


int main(int argc, char* argv[])//takes in an input file and calls functions to load linked list, print it, and frre it. 
{
	if(argc != 2)
	{
		printf("\n Incorrect number of command line arguments\n");
	return 0;
	}

	node* list = NULL;

	list = create_list(argv[1]);

	print_list(list);

	free_list(list);

	return 0;

}

node* create_list(char* fileName)// calls the insert function and fill the the linked list data spots with the values in the input file that this function opens. Returns the last list pointer node from the while loop. 
{
	int i = 0;
	int data = 0;
	node* list = NULL;


	FILE* file=fopen(fileName, "r");

	if (file==NULL)
		return list = NULL;

	while(fscanf(file, "%d", &data) != EOF)
	{

		list = insert_at_head(list, data);
	
	}

	fclose(file);

	return list;
}
