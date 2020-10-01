#include <stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct node_
{
	int data;
	struct node_* next;
} node;

node* insert_at_head(node* list, int data);

int main(void)
{

	node* start = NULL;
	

	node* second = insert_at_head(start, 2);
	assert(second->data == 2);
	assert(second->next == start);


	node* third = insert_at_head(second, 3);
	assert(third->data == 3);
	assert(third->next == second);

	free(third);
	free(second);
	printf("You have successfully completed the prelab\n");
	return 0;
}

node* insert_at_head(node* list, int data)
{

	node* newPtr = malloc(sizeof(node));

	if(newPtr != NULL)
	{
		newPtr->data = data;
		newPtr->next = list;
	}

	return newPtr;
}
