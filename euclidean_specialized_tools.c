#include "vector.h"
#include "euclidean_p.h"
#include <stdlib.h>

double euc_distance(
	void * data_table,
	int index_1,
	int index_2)
{
	element ** data_table_cast= data_table;
	return vector_euclidean_distance( data_table_cast[index_1]->vector0, data_table_cast[index_2]->vector0);
}


char * euc_get_element_name(
	element * element_ptr)
{
	return element_ptr->name;
}

int euc_get_element_pos(
	element * element_ptr)
{
	return element_ptr->position_in_dt;
}
