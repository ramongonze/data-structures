#include "queue.h"

int main(){
	queue *q;
	item_type item;
	int i, j;

	q = create_queue();

	item.key = 1;
	enqueue(q, item);
	item.key = 2;
	enqueue(q, item);
	enqueue(q, item);
	item.key = 3;
	enqueue(q, item);
	item.key = 99;
	enqueue(q, item);
	enqueue(q, item);
	enqueue(q, item);

	for(i = q->begin, j = 0; j < q->length; i = (i+1)%MAX, j++){
		printf("[%d] ", q->q[i].key);
	}printf("\n");

	dequeue(q, &item);

	delete_queue(q);

	return 0;
}