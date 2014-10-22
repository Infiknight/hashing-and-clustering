#include "euclidean.h"
#include "vector.h"
#include <stdlib.h>
#include "bucket.h"

struct Seed{
	vector ** vector_table;
	double * t_table;
	int w, k;
};
//typedef struct Seed seed;

int hash_table_constructor(
	element * data_table,
	int data_table_size,
	int hash_table_size)
{
	int w= W_SIZE, k= K_SIZE, i;
	int dimensions= vector_dimensions(data_table->vector0);
	
	seed * seed_0= malloc(sizeof(seed));
	seed_0->vector_table= malloc(k*sizeof(vector*));
	seed_0->t_table= malloc(k*sizeof(double));
	seed_0->k= k;
	seed_0->w= w;
	for(i= 0; i < k; i++){
		seed_0->vector_table[i]= vector_construct_random(dimensions);
		seed_0->t_table[i]= ( (double)rand()/((double)RAND_MAX+1) )*(double)w;
	}
	
}