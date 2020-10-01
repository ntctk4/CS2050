/*
 *Nathaniel Callahan
 *ntctk4
 *hw4
 *labE
 *
 *
 * */
#ifndef STACK_H_
#define STACK_H_

#include "traversal.h"

typedef struct stack_//data structure to make both stacks and queues since they use the same data structure.
{
	BST* data;
	struct stack_ *next;
} Stack;

void push(Stack** s, BST* root);
BST* top(Stack* s);
void pop(Stack** s);
int isEmpty(Stack* s);
void enqueue(Stack** q, BST* root);
BST* dequeue(Stack** q);

#endif
