
#include "bucket.h"
#include "distance_matrix_p.h"
#include "probability_distr.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

bucket ** dm_hash_table_constructor(
	element * data_table,
	int data_table_size,
	int * hash_table_size,
	seed * seed_0)
{
	int i, x_1, x_2;
	//construct seed
	(*seed_0).dimensions= data_table_size;
	(*seed_0).x_1= malloc(K_SIZE*sizeof(int));
	(*seed_0).x_2= malloc(K_SIZE*sizeof(int));
	(*seed_0).t= malloc(K_SIZE*sizeof(double));
	seed_0->k= K_SIZE;
	for(i= 0; i < K_SIZE; i++){
		do{
			x_1= uniform_distr(0, data_table_size-1);
			x_2= uniform_distr(0, data_table_size-1);
		}while(x_1 == x_2);
		(*seed_0).x_1[i]= x_1;
		(*seed_0).x_2[i]= x_2;
		(*seed_0).t[i]=generate_t_value( x_1, x_2, data_table, data_table_size);
	}
	//construct hash table
	*hash_table_size= pow( 2, K_SIZE);
	bucket ** hash_table= malloc( (*hash_table_size) * sizeof(bucket*) );
	for(i= 0; i < *hash_table_size; i++){
		hash_table[i]= bucket_construct();
	}
	int bucket_no;
	for(i= 0; i < data_table_size; i++){
		bucket_no= dm_concatenated_hash(data_table, seed_0, i);
		bucket_add_data( hash_table[bucket_no], &(data_table[i]) );
	}
	return hash_table;
}

