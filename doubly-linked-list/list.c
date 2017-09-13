#include "list.h"

list* create_list(){
	list *new = (list*) malloc(sizeof(list));

	new-> begin = new->end = NULL;
	new->length = 0;
	
	return new;
}

void delete_list(list *l){

}

//	It insert an intem in the end of the list.
void insert(list *l, item_type i){
	cell *new_cell = (cell*) malloc(sizeof(cell));

	new_cell->next = NULL;
	new_cell->previous = l->end;
	l->end->next = new_cell;
	l->end = new_cell;
	
	if(l->length == 0){
		l->begin = l->end;
	}

	l->length++;
}

//	Remove the item with the key 'k'. Returns 0 if it was successful or != 0 otherwise (the item isn't in the list).
int remove(list l, key_type k, item_type *i){
	item_type aux;
	cell *aux;
	int find;

	find = 0;
	aux = l->begin;
	while(aux != NULL){
		if(aux->item.key == k){
			find = 1;
			break;
		}
		aux = aux->next;
	}
	
	i = aux;
	if(aux == l->begin){
		aux->next->previous = NULL;
		l->begin = aux->next;
	}else if(aux == l->end){
		aux->previous->next = NULL;
		l->end = aux->previous;
	}else{
		aux->previous->next = aux->next;
		aux->next->previous = aux->previous;
	}

	free(aux);
	
	if(find){
		return 0;
	}else{
		return -1;
	}

}

//	Remove the first item in the list. Returns 0 if it was successful or != 0 otherwise (empty list).
void remove_from_the_begin(list *l);

//	Remove the last item in the list. Returns 0 if it was successful or != 0 otherwise (empty list).
void remove_from_the_end(list *l);

//	Serch an item in the list, which's the key is 'k'.
item_type search(list *l, key_type k);