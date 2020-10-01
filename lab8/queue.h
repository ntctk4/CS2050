/*ntctk4
 *Nathan Callahan
 *lab code: Pumpkin
 * */

#ifndef LIB_H_
#define LIB_H_

typedef struct node_
{
	char* data;
	struct node_* next;
} Queue;

Queue* enqueue(Queue* queue, char* data);
char* dequeue(Queue** queue);
int size(Queue* queue);

#endif
