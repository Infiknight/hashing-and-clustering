#include "bucket.h"
#include "list.h"
#include <stdlib.h>

struct Bucket{
	list * head;	///< The first node of the list.
	list * iterator;	///< A pointer to some node of the list.
	int size;		///< The number of units of data stored in the list.
};

bucket * bucket_construct()
{
	bucket * new_bucket= malloc(sizeof(bucket));
	new_bucket->head= list_construct();
	new_bucket->iterator= new_bucket->head;
	new_bucket->size= 0;
	return new_bucket;
}

int bucket_destruct(
	bucket * bucket0)
{
	int rvalue= list_destruct(bucket0->head);
	free(bucket0);
	return rvalue;
}

int bucket_add_data(
	bucket * bucket0,
	void * data)
{
	if( list_add(bucket0->head, data) == 0){
		bucket0->size++;
		return 0;
	}
	else
		return 1;
}

int bucket_next(
	bucket * bucket0)
{
	list * next_node= list_next_node(bucket0->iterator);
	if(next_node == NULL)
		return 1;	//theres no next node
	bucket0->iterator= next_node;
	return 0;
}

void bucket_reset_iterator(
	bucket * bucket0)
{
	bucket0->iterator= bucket0->head;
}

void * bucket_get_currnode_data(
	bucket * bucket0)
{
	return list_get_currnode_data(bucket0->iterator);
}