#include "hamming_p.h"
#include "hamming.h"
#include <stdlib.h>

double hamming_distance(
	void * data_table,
	int index_1,
	int index_2)
{
	element ** data_table_cast= data_table;
	return (double) hammingDistance( data_table_cast[index_1]->str, data_table_cast[index_2]->str);
}

char * hamming_get_element_name(
	element * element_ptr)
{
	return element_ptr->name;
}

int hamming_get_element_pos(
	element * element_ptr)
{
	return element_ptr->position_in_dt;
}