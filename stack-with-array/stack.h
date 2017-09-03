/*
*	This is a stack, a static data structure created using arrays.
*	It has the basic operations: create stack; delete stack; insert item (push);
*	remove item (pop) and check if the stack is empty.
*	The max size of the stack can be changed in the 'MAX' value.
*	The itens are stored starting in the position 1 of the array. The position 0
*	is used to identify a empty stack.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

//	The stack is a list of 'item_type', a structure that contains the data;
typedef int key_type;
typedef int stack_type; //	It's used to control the amount of itens in the stack

typedef struct item_type{
	key_type key;
	//	Can be added more attributes
}item_type;

//	Basic stack structure
typedef struct stack{
	item_type st[MAX];
	stack_type top;
}stack;

//	Create an empty stack
stack* create_stack();

//	Delete the stack. Returns 0 if it was succefull or != 0 otherwise.
int delete_stack(stack *s);

//	Insert a item in the top of the stack. Returns 0 if it was
//	succefull or != 0 otherwise.
int push(stack *s, item_type i);

//	Remove and returns the item in the top of the stack. Returns 0 if it was
//	succefull or != 0 otherwise.
int pop(stack *s, item_type *i);

//	Returns 1 if the stack is empty or 0 otherwise.
int is_empty(stack *s);
