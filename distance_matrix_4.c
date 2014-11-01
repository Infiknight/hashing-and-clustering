#include "distance_matrix_p.h"
#include <math.h>

double line_projection(
	int x,
	int x_1,
	int x_2,
	element * data_table)
{
	double d_x_x1= data_table[x].array[x_1];
	double d_x_x2= data_table[x].array[x_2];
	double d_x1_x2= data_table[x_1].array[x_2];
	return ( pow(d_x_x1, 2) + pow(d_x_x2, 2) - pow(d_x1_x2, 2) ) / ( 2 * d_x1_x2 );
}

int base_hash(
	element * data_table,
	seed const * const seed_0,
	int seed_index,
	int query)
{
	int x_1= seed_0->x_1[seed_index],
		x_2= seed_0->x_2[seed_index];
	double t= seed_0->t[seed_index];
	if( line_projection( query, x_1, x_2, data_table) <t )
		return 0;
	else
		return 1;
}

int dm_concatenated_hash(
	element * data_table,
	seed const * const seed_0,
	int query)
{
	int i,
		base_hash_0,
		sum= 0;
	for(i= 0; i < seed_0->k; i++){
		base_hash_0= base_hash( data_table, seed_0, i, query);
		//printf("1 d\n", base_hash_0);
		sum+= pow(2, i) * base_hash_0;
	}
	return sum;
}


double comp_double(
	const void * elem1,
	const void * elem2)
{
    double f = *((double*)elem1);
    double s = *((double*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

double generate_t_value(
	int x_1,
	int x_2,
	element * data_table,
	int data_table_size)
{
	int i;
	double values[data_table_size];
	for(i= 0; i < data_table_size; i++){
		values[i]= line_projection( i, x_1, x_2, data_table);
	}
	qsort(values, data_table_size, sizeof(double), comp_double);
	return values[data_table_size/2];
}


