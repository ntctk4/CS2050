//ntctk4
//Nathaniel Callahan
//lab E
//lave code: HAT
#ifndef FUNCTION_H_
#define FUNCTION_H_

typedef struct node_
{
	int data;
	struct node_* next;
}Set;

Set* set_insert(Set* set, int data);
Set* set_remove(Set* set, int data);
Set* set_intersection(Set* first, Set* second);
void print_set(Set* set);
void free_set(Set* set);

#endif
