/*
 *Nathaniel Callahan
 *hw3
 *
 *
 *
 * */
#include<stdio.h>
#include <stdlib.h>
#include "stack.h"

stack* create_stack()//creates a linked list that is used as a stack
{
	stack* s = malloc(sizeof(stack));

	return s;

}

void push(stack *s, int val)//adds a node to the stack if the new pointer is malloced correctly and there is memeory for it.
{
	node* newPtr;

	newPtr = malloc(sizeof(node));

	if(newPtr != NULL)
	{
		newPtr->data = val;
		newPtr->next = s->stack;
		s->stack = newPtr;
	}
	else
	{
		printf("%d not inserted. No memory available.\n", val);
	}
}

void pop(stack *s)//deletes the top node from the top of the stakc linked list.
{

	node* tempPtr = NULL;
	int popValue;

	tempPtr = s->stack;
	popValue = s->stack->data;
	s->stack = s->stack->next;
	free(tempPtr);
}

int top(stack *s)//takes the value from the top of the stack and returns the integer.
{
	int i = 0;


	i = s->stack->data;

	return i;
}

int isEmpty(stack *s)//checks to see if the stack is empty or not. 
{
	return s->stack == NULL ? 1 : 0;
}
