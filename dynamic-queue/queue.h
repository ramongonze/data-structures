/*
*	This is a dynamic queue, a data structure. It was based in a chain list.
*	It has the basic operations: create queue; delete queue; enqueue; dequeue
*	and check if the queue is empty. To control the queue length, there is the
*	'length' variable, in the queue struct.
*/

#include <stdio.h>
#include <stdlib.h>

typedef int key_type;
typedef int queue_type;

typedef struct item_type{
	key_type key;
	//	Can add more atributtes
}item_type;

typedef struct cell{
	item_type item;
	struct cell *next;
}cell;

//	Basic queue structure.
typedef struct queue{
	cell *begin;
	cell *end;
	queue_type length;
}queue;

//	Create a new queue.
queue* create_queue();

//	Deallocate all the memory that was allocated, deleting the queue.
void delete_queue(queue *q);

//	Insert an item in the end of the queue.
void enqueue(queue *q, item_type i);

//	Remove the first element in the begining of the queue and returns it to 'item'.
//	It returns 0 if it was succefull or != 0 otherwise (the queue is empty).
int dequeue(queue *q, item_type *item);

// Returns 1 if the queue is empty or 0 otherwise.
int is_empty(queue *q);

