/*
*	This is a queue, a static data structure created using arrays.
*	It has the basic operations: create queue; delete queue; enqueue;
*	dequeue and check if the queue is empty.
*	The max size of the queue can be changed in the 'MAX' value.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 3

typedef int key_type;
typedef int queue_type;


typedef struct item_type{
	key_type key;
	//	Can add more atributtes
}item_type;

//	Basic queue structure
typedef struct queue{
	item_type q[MAX];
	queue_type begin;
	queue_type end;
	queue_type length;
}queue;

//	Create a queue
queue* create_queue();

//	Deallocate all the memory allocated for a queue
void delete_queue(queue *q);

//	Insert an item in the begin of the queue. It returns 0 if
//	it was successful and != 0 otherwise (the queue is full).
int enqueue(queue *q, item_type i);

//	Remove an intem from the begining of the queue and returns it into 'item'.
//	It returns 0 if it was successful and != 0 otherwise (the queue is empty).
int dequeue(queue *q, item_type *item);

//	Returns 1 if the queue is empty or 0 otherwise.
int is_empty(queue *q);