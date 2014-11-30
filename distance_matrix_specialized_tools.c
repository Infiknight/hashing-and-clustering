#include "distance_matrix_p.h"
#include <stdlib.h>

double dm_distance(
	void * data_table,
	int index_1,
	int index_2)
{
	element ** data_table_cast= (element**) data_table;
	return data_table_cast[index_1]->array[index_2];
}


char * dm_get_element_name(
	element * element_ptr)
{
	return element_ptr->name;
}

int dm_get_element_pos(
	element * element_ptr)
{
	return element_ptr->position_in_dt;
}