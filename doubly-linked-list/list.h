/*
*	This is a doubly linked list, a data structure.
*	Each element in this list is connected with the previous and the next element.
*	It has the following operations: create_list; delete_list; search; insert and remove item;
*/

#include <stdio.h>
#include <stdlib.h>

typedef int key_type;
typedef int list_type;

typedef struct item_type{
	key_type key;
	// Can add more atributtes
}item_type;

typedef struct cell{
	item_type item;
	struct cell *next;
	struct cell *previous;
}cell;

typedef struct list{
	cell *begin;
	cell *end;
	list_type length;
}list;

list* create_list();

void delete_list(list *l);

//	It insert an intem in the end of the list.
void insert(list *l, item_type i);

//	Remove the item with the key 'k'. Returns 0 if it was successful or != 0 otherwise (the item isn't in the list).
int remove(list *l, key_type k, item_type *i);

//	Remove the first item in the list. Returns 0 if it was successful or != 0 otherwise (empty list).
void remove_from_the_begin(list *l);

//	Remove the last item in the list. Returns 0 if it was successful or != 0 otherwise (empty list).
void remove_from_the_end(list *l);

//	Serch an item in the list, which's the key is 'k'.
item_type search(list *l, key_type k);