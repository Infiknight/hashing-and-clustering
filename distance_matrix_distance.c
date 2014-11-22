#include "distance_matrix_p.h"
#include <stdlib.h>

double dm_distance(
	void * data_table,
	int index_1,
	int index_2)
{
	element * data_table_cast= data_table;
	return (double) data_table_cast[index_1].array[index_2];
}