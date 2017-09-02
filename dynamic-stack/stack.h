/*
*	This is a stack, a dynamic data structure, based in a chain list.
*	It has the basic operations: create stack; delete stack; insert item (push);
*	remove item (pop) and check if the stack is empty.
*/

#include <stdio.h>
#include <stdlib.h>

//	The stack is a list of 'item_type', a structure that contains the data;
typedef int key_type;
typedef int stack_type;

typedef struct item_type{
	key_type key;
	//	Can add more attributes
}item_type;

// Define what is beeing stored in the stack.
typedef struct cell{
	item_type item;
	struct cell *next;
}cell;

typedef struct stack{
	cell *top;
	stack_type size;
}stack;

//	Create a stack with a headh (empty cell).
stack* create_stack();

//	Desallocate all the memory allocated, deleting the stack.
void delete_stack(stack *s);

//	Insert a cell in the top of the stack.
void push(stack *s, item_type i);

//	Remove and returns the item in the top of the stack.
item_type pop(stack *s);

//	Returns 1 if the stack is empty or != 1 otherwise
int is_empty(stack *s);