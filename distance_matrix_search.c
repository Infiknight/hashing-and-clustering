#include "distance_matrix_p.h"
#include "distance_matrix.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <limits.h>

int dm_search(
	seed const * const seed_0,
	bucket ** hash_table,
	element ** data_table,
	element *** results,
	int * current_results_no,
	int radius,
	element * query)
{
	int bucket_no= dm_concatenated_hash(data_table, seed_0, query);
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
		else if( query->array[item->position_in_dt] < radius*C_FACTOR){
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

element ** dm_L_search(
	int L,
	FILE * stream,
	seed ** seed_0,
	bucket *** hash_table,
	element ** data_table,
	int radius,
	element * query,
	int * results_no)
{
	struct timeval stop, start;
	int i,
		minimum_distance= INT_MAX;
	*results_no= 0;
	char * minimum= NULL;
	element ** results= NULL;
	gettimeofday(&start, NULL);
	for(i= 0; i < L; i++){
		dm_search( seed_0[i], hash_table[i], data_table, &results, results_no, radius, query);
	}
	/*fprintf(stream, "Query: %s\n%d-near neighbors:\n", query->name, radius);
	for(i= 0; i < *results_no; i++){
		if(radius > 0)
			fprintf(stream, "%s\n", results[i]->name);
		if( (query->array[results[i] - data_table] <= minimum_distance) && (0 != strcmp(results[i]->name, query->name)) ){
			minimum_distance= query->array[results[i] - data_table];
			minimum= results[i]->name;
		}
	}*/
	gettimeofday(&stop, NULL);
	/*if( minimum != NULL )
		fprintf(stream, "Nearest neighbor: %s\ndistanceLSH: %d\ntLSH: %I64u seconds and %I64u microseconds\n", 
			minimum, minimum_distance, (long long) (stop.tv_sec - start.tv_sec), (long long) (stop.tv_usec - start.tv_usec));
	else
		fprintf(stream, "Found no items near the query.\n");*/
	return results;
}

int dm_exhaustive_search(
	element ** data_table,
	int size,
	element * query,
	FILE * stream)
{
	struct timeval stop, start;
	int i;
	int minimum_distance= INT_MAX;
	char * minimum= NULL;
	gettimeofday(&start, NULL);
	for(i= 0; i < size; i++){
		if( query->array[i] < minimum_distance && 0 != strcmp(query->name, data_table[i]->name) ){
			minimum_distance= query->array[i];
			minimum= data_table[i]->name;
		}
	}
	gettimeofday(&stop, NULL);
	fprintf(stream, "distanceTrue: %d\ntTrue: %I64u seconds and %I64u microseconds\n", minimum_distance, 
		(long long) (stop.tv_sec - start.tv_sec), (long long) (stop.tv_usec - start.tv_usec));
	return 0;
}