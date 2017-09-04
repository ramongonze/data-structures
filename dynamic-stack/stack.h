/*
*	This is a stack, a dynamic data structure, based in a chain list.
*	It has the basic operations: create stack; delete stack; insert item (push);
*	remove item (pop) and check if the stack is empty.
*/

#include <stdio.h>
#include <stdlib.h>

//	The stack is a list of 'item_type', a structure that contains the data;
typedef int key_type;
typedef int stack_type; //	It's used to control the amount of itens in the stack (through the stack.length) 

typedef struct item_type{
	key_type key;
	//	Can be added more attributes
}item_type;

// Each cell has an 'item_type', and many cells make up the stack
typedef struct cell{
	item_type item;
	struct cell *next;
}cell;

//	Basic stack structure
typedef struct stack{
	cell *top;
	stack_type length;
}stack;

//	Create an empty stack
stack* create_stack();

//	Desallocate all the memory allocated, deleting the stack.
void delete_stack(stack *s);

//	Insert a cell in the top of the stack.
void push(stack *s, item_type i);

//	Remove the item in the top of the stack and returns it into 'i'.
//	It returns 0 if it was succefull or != 0 otherwise (the stack is empty).
int pop(stack *s, item_type *i);

//	Returns 1 if the stack is empty or != 1 otherwise
int is_empty(stack *s);
