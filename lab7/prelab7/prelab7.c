#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node_
{
	int data;
	struct node_* next;
}Set;


Set* insert(Set* set, int data);


int main(void)
{
	Set* set = NULL;

	set = insert(set, 1);
	
	
	assert(set != NULL);
	assert(set->data == 1);

	set = insert(set, 2);
	
	
	assert(set->data == 2);

	
	set = insert(set, 1);

	
	
	assert(set->data == 2);
	assert(set->next->data == 1);
	assert(set->next->next == NULL);

	printf("You have completed the prelab\n");
}

Set* insert(Set* set, int data)
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
			newPtr ->next = set;

			return newPtr;
		}

		else 
			return set;
	}

}
