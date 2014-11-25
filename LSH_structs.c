#include "LSH_structs.h"
#include "euclidean.h"
#include "distance_matrix.h"

int get_element_pos(
	element * element_ptr,
	metric_space current_space)
{
	if(current_space == euclidean)
		return euc_get_element_pos(element_ptr);
	else if(current_space == distance_matrix)
		return dm_get_element_pos(element_ptr);
	//else
}

char * get_element_name(
	element * element_ptr,
	metric_space current_space)
{
	if(current_space == euclidean)
		return euc_get_element_name(element_ptr);
	else if(current_space == distance_matrix)
		return dm_get_element_name(element_ptr);
	//else
}
