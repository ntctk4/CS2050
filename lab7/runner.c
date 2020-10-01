/*
 *Nathaniel Callahan
 *ntctk4
 *Lab E
 *Lab Code: HAT
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include "set.h"

Set* create_set(char* file);

int main(int argc, char* argv[])//Calls all the functions to open up the input files to put the data into the set nodes. Calls functions to print out the values in each set. Calls a function to check for similar values in the list and makes a third set with only matchig values. Takes value from argument and takes value out of third set and makes a fourth set. Calls function to print out third /fourth set, and calls a function to free all the nodes in the lists.
{
	if (argc != 4)
	{
		printf("\n Incorrect number of command line arguments\n");
		return 0;
	}

	Set* set1 = NULL;

	Set* set2 = NULL;

	Set* set3 = NULL;

	Set* set4 = NULL;

	set1 = create_set(argv[1]);
	
	set2 = create_set(argv[2]);

	printf(" First set\n");
	
	print_set(set1);

	printf(" Second set\n");

	print_set(set2);

	printf(" intersection of the two sets\n");

	set3 = set_intersection(set1, set2);

	print_set(set3);

	printf(" intersection without %s\n", argv[3]);

	set4 = set_remove(set3, atoi(argv[3]));

	print_set(set4);

	free_set(set1);

	free_set(set2);

	free_set(set3);

	free_set(set4);

	return 0;


}

Set* create_set(char* fileName)//Opens up the txt file and calls the insert function to put the data in the file into node of a set list. The insert function checks for duplicates and doesn't add them to the set list. 
{
	int i = 0;
	int data = 0;
	Set* set = NULL;

	FILE* file=fopen(fileName, "r");

	if (file==NULL)
		return set = NULL;

	while(fscanf(file, "%d", &data) != EOF)
	{
		set = set_insert(set, data);
	}

	fclose(file);

	return set;
}
