#include "euclidean.h"
#include "vector.h"
#include <stdlib.h>
#include "bucket.h"
#include "euclidean_p.h"


//typedef struct Seed seed;

bucket ** hash_table_constructor(
	element * data_table,
	int data_table_size,
	int * hash_table_size,
	seed ** seed_0_PPtr)
{
	augmented_data * augmented_data_Ptr;
	int i, bucket_no, identifying_value;
	int dimensions= vector_dimensions(data_table->vector0);
	*hash_table_size= data_table_size/N_DENOMINATOR;
	bucket ** hash_table= malloc( (*hash_table_size)*sizeof(bucket *));
	for(i= 0; i < *hash_table_size; i++){
		hash_table[i]= bucket_construct();
	}
	*seed_0_PPtr= malloc(sizeof(seed));
	seed * const seed_0= *seed_0_PPtr;
	seed_0->vector_table= malloc(K_SIZE*sizeof(vector*));
	seed_0->t_table= malloc(K_SIZE*sizeof(double));
	seed_0->k= K_SIZE;
	seed_0->w= W_SIZE;
	seed_0->n= *hash_table_size;
	//printf("1111\n");
	for(i= 0; i < K_SIZE; i++){
		seed_0->vector_table[i]= vector_construct_random(dimensions);
		seed_0->t_table[i]= ( (double)rand()/((double)RAND_MAX+1) )*W_SIZE;
	}
	//printf("222\n");
	for(i= 0; i < data_table_size; i++){
		bucket_no= concatenated_hash_function(data_table[i].vector0, seed_0, &identifying_value);
		//printf("%d\n", identifying_value);
		augmented_data_Ptr= malloc(sizeof(augmented_data));
		augmented_data_Ptr->augment= identifying_value;
		augmented_data_Ptr->data= &data_table[i];
		bucket_add_data(hash_table[bucket_no], augmented_data_Ptr);
	}
	return hash_table;
}

int search(
	vector const * const query,
	bucket ** hash_table,
	seed const * const seed_0,
	double radius)
{
	augmented_data * aug_dat_ptr;
	element * element_0;
	vector * vector_2;
	double distance;
	int identifying_value;
	int bucket_no= concatenated_hash_function(query, seed_0, &identifying_value);
	//printf("444\n");
	bucket_reset_iterator( hash_table[bucket_no] );
	do{
		if( bucket_get_currnode_data(hash_table[bucket_no]) != NULL){
			aug_dat_ptr= bucket_get_currnode_data(hash_table[bucket_no]);
			if( aug_dat_ptr->augment != identifying_value )
				continue;
			vector_2= ((element*) aug_dat_ptr->data)->vector0;
			distance= vector_euclidean_distance(query, vector_2);
			if( distance < 0){
				printf("damn \n");
				return -1;
			}
			if( distance <= radius )
				printf("neighbor: %s\n", ((element*) aug_dat_ptr->data)->name);
		}	
	}while( bucket_next(hash_table[bucket_no]) == 0 );
}