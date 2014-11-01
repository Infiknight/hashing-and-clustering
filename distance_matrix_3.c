#include "distance_matrix_p.h"
#include "distance_matrix.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <limits.h>

int dm_search(
	seed const * const seed_0,
	bucket ** hash_table,
	element * data_table,
	element *** results,
	int * current_results_no,
	int radius,
	int item_index)
{
	int bucket_no= dm_concatenated_hash(data_table, seed_0, item_index);
	int i,
		already_in;
	element * item;
	bucket * hash_bucket= hash_table[bucket_no];
	bucket_reset_iterator( hash_bucket );
	do{
		item= bucket_get_currnode_data(hash_bucket);
		already_in= 0;
		if(radius == 0){
			for(i= 0; i < *current_results_no; i++){
				if( (*results)[i] == item){
					already_in= 1;
					break;
				}
			}
			if(already_in == 1)
				continue;
			(*current_results_no)++;
			*results= realloc( *results, (*current_results_no)*sizeof(element*));
			(*results)[(*current_results_no)-1]= item;
		}
		else if( item->array[item_index] < radius*C_FACTOR){
			for(i= 0; i < *current_results_no; i++){
				if( (*results)[i] == item){
					already_in= 1;
					break;
				}
			}
			if(already_in == 1)
				continue;
			(*current_results_no)++;
			*results= realloc( *results, (*current_results_no)*sizeof(element*));
			(*results)[(*current_results_no)-1]= item;
		}	
	}while( bucket_next(hash_bucket) == 0);
	bucket_reset_iterator( hash_bucket );
	return 0;
}

int dm_L_search(
	int L,
	FILE * stream,
	seed ** seed_0,
	bucket *** hash_table,
	element * data_table,
	int radius,
	int item_index)
{
	struct timeval stop, start;
	int i,
		current_results_no= 0,
		minimum_distance= INT_MAX;
	char * minimum= NULL;
	element ** results= NULL;
	gettimeofday(&start, NULL);
	for(i= 0; i < L; i++){
		dm_search( &((*seed_0)[i]), hash_table[i], data_table, &results, &current_results_no, radius, item_index);
	}
	fprintf(stream, "Query: %s\n%d-near neighbors:\n", data_table[item_index].name, radius);
	for(i= 0; i < current_results_no; i++){
		if(radius > 0)
			fprintf(stream, "%s\n", results[i]->name);
		if( (results[i]->array[item_index] <= minimum_distance) && (0 != strcmp(results[i]->name, data_table[item_index].name)) ){
			minimum_distance= results[i]->array[item_index];
			minimum= results[i]->name;
		}
	}
	gettimeofday(&stop, NULL);
	if( minimum != NULL )
		fprintf(stream, "Nearest neighbor: %s\ndistanceLSH: %d\ntLSH: %I64u seconds and %I64u microseconds\n", 
			minimum, minimum_distance, (long long) (stop.tv_sec - start.tv_sec), (long long) (stop.tv_usec - start.tv_usec));
	else
		fprintf(stream, "Found no items near the query.\n");
	return 0;
}

int dm_exhaustive_search(
	element * data_table,
	int size,
	int item_index,
	FILE * stream)
{
	struct timeval stop, start;
	int i;
	int minimum_distance= INT_MAX;
	char * minimum= NULL;
	gettimeofday(&start, NULL);
	for(i= 0; i < size; i++){
		if( data_table[item_index].array[i] < minimum_distance && 0 != strcmp(data_table[item_index].name, data_table[i].name) ){
			minimum_distance= data_table[item_index].array[i];
			minimum= data_table[i].name;
		}
	}
	gettimeofday(&stop, NULL);
	fprintf(stream, "distanceTrue: %d\ntTrue: %I64u seconds and %I64u microseconds\n", minimum_distance, 
		(long long) (stop.tv_sec - start.tv_sec), (long long) (stop.tv_usec - start.tv_usec));
	return 0;
}