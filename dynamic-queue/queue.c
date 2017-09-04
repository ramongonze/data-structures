#include "queue.h"

queue* create_queue(){
	queue *new_queue = (queue*) malloc(sizeof(queue));
	cell *new_cell = (cell*) malloc(sizeof(cell));

	new_queue->begin = new_cell;
	new_queue->end = new_cell;
	new_queue->length = 0;
	new_cell->next = NULL;

	return new_queue;
}

void delete_queue(queue *q){
	cell *aux;

	aux = q->begin;
	while(aux != NULL){
		q->begin = q->begin->next;
		free(aux);
		aux = q->begin;
	}

	free(q);
}

void enqueue(queue *q, item_type i){
	cell *new = (cell*) malloc(sizeof(cell));

	new->item = i;
	new->next = NULL;
	q->end->next = new;
	q->end = new;
	q->length++;
}

int dequeue(queue *q, item_type *item){
	
	cell *aux;

	if(is_empty(q)){
		return -1;
	}

	*item = q->begin->next->item;
	aux = q->begin->next;
	q->begin->next = aux->next;
	free(aux);
	q->length--;
	
	if(q->begin->next == NULL){
		q->end = q->begin;
	}

	return 0;
}

int is_empty(queue *q){
	return q->begin == q->end;
}