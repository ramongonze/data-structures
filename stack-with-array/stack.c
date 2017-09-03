#include "stack.h"

stack* create_stack(){
	stack *new_stack = NULL;

	new_stack = (stack*) malloc(sizeof(stack));
	if(new_stack == NULL){
		printf("Error to allocate memory for a stack.\n");
		return NULL;
	}

	new_stack->top = 0;

	return new_stack;
}

int delete_stack(stack *s){
	free(s);
	if(s == NULL) return 0;
	else return -1;
}

int push(stack *s, item_type i){

	if(s->top == (MAX-1)){
		printf("Error! Cannot be inserted, the stack is full!\n");
		return -1;
	}

	s->top++;
	s->st[s->top] = i;
	return 0;
}

int pop(stack *s, item_type *i){

	if(is_empty(s)){
		printf("Error! Nothing to be removed, the stack is empty!\n");
		return -1;
	}

	*i = s->st[s->top];
	s->top--;

	return 0;
}

int is_empty(stack *s){
	return s->top == 0;
}
