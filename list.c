#include "list.h"
#include <stdlib.h>

struct List{
	void * elementPtr;	///< pointer to current node's data
	struct List * next;	///< pointer to the next node
};

//typedef struct List list;

list * list_construct()
{
	list * new_list= malloc(sizeof(list));
	new_list->elementPtr= NULL;
	new_list->next= NULL;
	return new_list;
}

int list_add(
	list * node,
	void * data)
{
	if(node->elementPtr == NULL){
		node->elementPtr= data;
		return 0;
	}
	else if(node->next == NULL)
		node->next= list_construct();
	return list_add( node->next, data);
}

void * list_get_currnode_data(
	list * node)
{
	return node->elementPtr;
}

list * list_next_node(
	list * node)
{
	return node->next;
}

int list_destruct(
	list * head)
{
	if(head->next != NULL)
		if(list_destruct(head->next) != 0)
			return 1;
	free(head);
	return 0;
}