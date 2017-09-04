#include "stack.h"

stack* create_stack(){
	stack *new_stack = NULL;

	new_stack = (stack*) malloc(sizeof(stack));
	new_stack->top = NULL;
	new_stack->length = 0;

	return new_stack;
}

void delete_stack(stack *s){
	cell *q;
	stack_type i;

	for(i = s->length; i > 0; i--){
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
	new_cell->item = i;
	new_cell->next = s->top;

	s->top = new_cell;
	s->length++;
}

int pop(stack *s, item_type *i){
	cell *q;

	if(is_empty(s)){
		return -1;
	}

	q = s->top;
	*i = q->item;
	s->top = s->top->next;
	s->length--;
	free(q);

	return 0;
}

int is_empty(stack *s){
	return s->top == NULL;
}
