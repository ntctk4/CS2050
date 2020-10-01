//ntctk4

#ifndef FUNCTION_H_
#define FUNCTION_H_

typedef struct node_
{
	int data;
	struct node_* next;
}node;

node* insert_at_head(node* list, int data);
void print_list(node* list);
void free_list(node* list);

#endif
