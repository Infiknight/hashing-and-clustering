#include "vector.h"
#include <stdlib.h>
#include "bucket.h"
#include "euclidean_p.h"


//typedef struct Seed seed;

bucket ** euc_hash_table_constructor(
	element ** data_table,
	int data_table_size,
	int * hash_table_size,
	seed ** seed_0_PPtr,
	int k,
	vector_metric vector_metric_0)
{
	augmented_data * augmented_data_Ptr;
	int i, bucket_no, identifying_value;
	int dimensions= vector_dimensions(data_table[0]->vector0);
	*hash_table_size= data_table_size/N_DENOMINATOR;
	bucket ** hash_table= malloc( (*hash_table_size)*sizeof(bucket *));
	for(i= 0; i < *hash_table_size; i++){
		hash_table[i]= bucket_construct();
	}
	*seed_0_PPtr= malloc(sizeof(seed));
	seed * const seed_0= *seed_0_PPtr;
	seed_0->vector_table= malloc(k*sizeof(vector*));
	seed_0->t_table= malloc(k*sizeof(double));
	seed_0->k= k;
	seed_0->w= W_SIZE;
	seed_0->n= *hash_table_size;
	for(i= 0; i < k; i++){
		seed_0->vector_table[i]= vector_construct_random(dimensions);
		seed_0->t_table[i]= ( (double)rand()/((double)RAND_MAX+1) )*W_SIZE;
	}
	for(i= 0; i < data_table_size; i++){
		bucket_no= euc_concatenated_hash_function(data_table[i]->vector0, seed_0, &identifying_value, vector_metric_0);
		augmented_data_Ptr= malloc(sizeof(augmented_data));
		augmented_data_Ptr->augment= identifying_value;
		augmented_data_Ptr->data= data_table[i];
		bucket_add_data(hash_table[bucket_no], augmented_data_Ptr);
	}
	return hash_table;
}

