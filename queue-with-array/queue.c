#include "queue.h"

queue* create_queue(){
	queue *new = (queue*) malloc(sizeof(queue));

	new->begin = 0;
	new->end = 0;
	new->length = 0;

	return new;
}

void delete_queue(queue *q){
	free(q);
}

int enqueue(queue *q, item_type i){

	if(q->length == MAX){
		return -1;
	}

	q->end = (q->end + 1) % MAX;
	if(q->end == 0){
		q->q[MAX-1] = i;		
	}else{
		q->q[q->end-1] = i;
	}
	q->length++;

	return 0;
}

int dequeue(queue *q, item_type *item){

	if(is_empty(q)){
		return -1;
	}

	*item = q->q[q->begin];
	q->begin = (q->begin + 1) % MAX;
	q->length--;

	return 0;
}

int is_empty(queue *q){
	return q->length == 0;
}