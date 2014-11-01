#include "euclidean.h"
#include "vector.h"
#include <stdlib.h>
#include <float.h>
#include <time.h>
#include <sys/time.h>
#include "bucket.h"
#include "euclidean_p.h"

int euc_search(
	vector const * const query,
	bucket ** hash_table,
	element *** results,
	int * current_results_no,
	seed const * const seed_0,
	double radius)
{
	augmented_data * aug_dat_ptr;
	element * element_0;
	vector * vector_2;
	double distance;
	int identifying_value;
	int i, already_in;
	int bucket_no= euc_concatenated_hash_function(query, seed_0, &identifying_value);
	bucket_reset_iterator( hash_table[bucket_no] );
	do{
		already_in= 0;
		aug_dat_ptr= bucket_get_currnode_data(hash_table[bucket_no]);
		if( aug_dat_ptr->augment != identifying_value )
			continue;
		vector_2= ((element*) aug_dat_ptr->data)->vector0;
		distance= vector_euclidean_distance(query, vector_2);
		if( distance < 0){
			printf("damn \n");
			return -1;
		}
		if( radius == 0 || distance < radius ){
			
			for(i= 0; i < *current_results_no; i++){
				if( (*results)[i] == aug_dat_ptr->data ){
					already_in= 1;
					break;
				}
			}
			if(already_in == 1)
				continue;
			(*current_results_no)++;
			*results= realloc( *results, (*current_results_no)*sizeof(element*));
			(*results)[(*current_results_no)-1]= aug_dat_ptr->data;
		}
	}while( bucket_next(hash_table[bucket_no]) == 0 );
	bucket_reset_iterator( hash_table[bucket_no] );
	return 0;
}

int euc_L_search(
	int L, 
	FILE * stream,
	seed ** seed_0,
	bucket *** hash_table,
	element * data_table,
	double radius,
	int item_index)
{
	struct timeval stop, start;
	int i,
		current_results_no= 0;
	double	minimum_distance= DBL_MAX;
	char * minimum= NULL;
	element ** results= NULL;
	gettimeofday(&start, NULL);
	for(i= 0; i < L; i++){
		euc_search( data_table[item_index].vector0, hash_table[i], &results, &current_results_no, seed_0[i], radius);
	}
	fprintf(stream, "Query: %s\n%f-near neighbors:\n", data_table[item_index].name, radius);
	for(i= 0; i < current_results_no; i++){
		if(radius > 0)
			fprintf(stream, "%s\n", results[i]->name);
		if( ( vector_euclidean_distance( results[i]->vector0, data_table[item_index].vector0) <= minimum_distance) 
			&& (0 != strcmp(results[i]->name, data_table[item_index].name)) ){
				minimum_distance= vector_euclidean_distance( results[i]->vector0, data_table[item_index].vector0);
				minimum= results[i]->name;
		}
	}
	gettimeofday(&stop, NULL);
	if( minimum != NULL )
		fprintf(stream, "Nearest neighbor: %s\ndistanceLSH: %lf\ntLSH: %I64u seconds and %I64u microseconds\n", 
			minimum, minimum_distance, (long long) (stop.tv_sec - start.tv_sec), (long long) (stop.tv_usec - start.tv_usec));
	else
		fprintf(stream, "Found no items near the query.\n");
	return 0;
}

int euc_exhaustive_search(
	element * data_table,
	int size,
	int item_index,
	FILE * stream)
{
	struct timeval stop, start;
	int i;
	double minimum_distance= DBL_MAX;
	char * minimum= NULL;
	gettimeofday(&start, NULL);
	for(i= 0; i < size; i++){
		if( ( vector_euclidean_distance( data_table[i].vector0, data_table[item_index].vector0) <= minimum_distance) 
			&& (0 != strcmp(data_table[i].name, data_table[item_index].name)) ){
			minimum_distance= vector_euclidean_distance( data_table[i].vector0, data_table[item_index].vector0);
			minimum= data_table[i].name;
		}
	}
	gettimeofday(&stop, NULL);
	fprintf(stream, "distanceTrue: %lf\ntTrue: %I64u seconds and %I64u microseconds\n", minimum_distance, 
		(long long) (stop.tv_sec - start.tv_sec), (long long) (stop.tv_usec - start.tv_usec));
	return 0;
}