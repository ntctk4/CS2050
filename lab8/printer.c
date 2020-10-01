/*
 *Nathaniel Callahan
 *ntctk4
 *Lab 8
 *Labe code:Pumpkin
 *
 **/
#include<stdio.h>
#include<stdlib.h>
#include "queue.h"
#include<unistd.h>
#include<string.h>


Queue* print(Queue* queue);

int main(int argc, char* argv[])//opens the input file and puts strings in buffer. then put in a queue linked list. Once queue has three nodes main calls print to print out nodes and dequeue each node.
{
	int i = 0;

	if(argc != 2)
	{
		printf("\n Incorrect number of command line arguments\n");
		return 0;
	}

	Queue* queue = NULL;

	FILE* file=fopen(argv[1], "r");

	char buffer[100] = "";

	while(fgets(buffer, 100, file) != NULL)
	{
		
		if(i ==  3)
		{
			queue = print(queue);
			i = 0;
		}

		queue = enqueue(queue, buffer);
		i = size(queue);

	}

	printf("\n<no output here, 1 second pause>\n");

	printf("\n%s", queue->data);
	free(queue);

	return 0;
}

Queue* print(Queue* queue)//dequeue each node in the linked list and prints out the strings in the node. returns the new head of the linked list when finished.
{
	sleep(1);
	int i;
	char* string = NULL;
	
	

	printf("\n<no output here, 1 second pause>\n\n");

	while(queue != NULL)
	{

	string =  dequeue(&queue);
		printf("%s\n", string);
	}
	return queue;
}








