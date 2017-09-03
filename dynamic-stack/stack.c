#include "stack.h"

stack* create_stack(){
	stack *new_stack = NULL;

	new_stack = (stack*) malloc(sizeof(stack));
	if(new_stack == NULL){
		printf("Error to allocate memory for a stack.\n");
		return NULL;
	}

	new_stack->top = NULL;
	new_stack->size = 0;

	return new_stack;
}

void delete_stack(stack *s){
	cell *q;
	stack_type i;

	for(i = s->size; i > 0; i--){
		q = s->top;
		s->top = s->top->next;
		free(q);
	}

	free(s);
}

void push(stack *s, item_type i){
	cell *new_cell = NULL;
	cell *q;

	new_cell = (cell*) malloc(sizeof(cell));
	if(new_cell == NULL){
		printf("Error to allocate memory for a cell.\n");
		return;
	}

	new_cell->item = i;
	new_cell->next = s->top;

	s->top = new_cell;
	s->size++;
}

item_type pop(stack *s){
	cell *q;
	item_type i;

	if(is_empty(s)){
		printf("Error! Nothing to be removed, the stack is empty!\n");
		i.key = -1;
		return i;
	}

	q = s->top;
	i = q->item;
	s->top = s->top->next;
	s->size--;
	free(q);

	return i;
}

int is_empty(stack *s){
	return s->top == NULL;
}
