#include "euclidean.h"
#include "vector.h"
#include <stdlib.h>
#include <float.h>
#include <time.h>
#include <string.h>
//#include <sys/time.h>
#include "bucket.h"
#include "euclidean_p.h"

int euc_search(
	vector const * const query,
	bucket ** hash_table,
	element *** results,
	int * current_results_no,
	seed const * const seed_0,
	double radius,
	vector_metric vector_metric_0)
{
	augmented_data * aug_dat_ptr;
	element * element_0;
	vector * vector_2;
	double distance;
	int identifying_value;
	int i, already_in;
	int bucket_no= euc_concatenated_hash_function(query, seed_0, &identifying_value, vector_metric_0);
	bucket_reset_iterator( hash_table[bucket_no] );
	do{
		already_in= 0;
		aug_dat_ptr= bucket_get_currnode_data(hash_table[bucket_no]);
		if( aug_dat_ptr->augment != identifying_value )
			continue;
		vector_2= ((element*) aug_dat_ptr->data)->vector0;
		if(vector_metric_0 == euclidean_metric)
			distance= vector_euclidean_distance(query, vector_2);
		else if(vector_metric_0 == cosine_metric)
			distance= vector_cosine_distance(query, vector_2);
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

element ** euc_L_search(
	int L, 
	FILE * stream,
	seed ** seed_0,
	bucket *** hash_table,
	element ** data_table,
	double radius,
	element * query,
	int * results_no,
	vector_metric vector_metric_0)
{
	struct timespec stop, start;
	int i;
	*results_no= 0;
	double	minimum_distance= DBL_MAX;
	char * minimum= NULL;
	element ** results= NULL;
	clock_gettime(CLOCK_MONOTONIC, &start);
	for(i= 0; i < L; i++){
		euc_search( query->vector0, hash_table[i], &results, results_no, seed_0[i], radius, vector_metric_0);
	}
	//fprintf(stream, "Query: %s\n%f-near neighbors:\n", query->name, radius);
	/*for(i= 0; i < *results_no; i++){
		if(radius > 0)
			fprintf(stream, "%s\n", results[i]->name);
		if( ( vector_euclidean_distance( results[i]->vector0, query->vector0) <= minimum_distance) 
			&& (0 != strcmp(results[i]->name, query->name)) ){
				minimum_distance= vector_euclidean_distance( results[i]->vector0, query->vector0);
				minimum= results[i]->name;
		}
	}*/
	clock_gettime(CLOCK_MONOTONIC, &stop);
	/*if( minimum != NULL )
		fprintf(stream, "Nearest neighbor: %s\ndistanceLSH: %lf\ntLSH: %lld seconds and %lld microseconds\n", 
			minimum, minimum_distance, (long long) (stop.tv_sec - start.tv_sec), (long long) (stop.tv_nsec - start.tv_nsec));
	else
		fprintf(stream, "Found no items near the query.\n");*/
	return results;
}

int euc_exhaustive_search(
	element ** data_table,
	int size,
	element * query,
	FILE * stream,
	vector_metric vector_metric_0)
{
	struct timespec stop, start;
	int i;
	double minimum_distance= DBL_MAX;
	char * minimum= NULL;
	//gettimeofday(&start, NULL);
	clock_gettime(CLOCK_MONOTONIC, &start);
	if(vector_metric_0 == euclidean_metric)
		for(i= 0; i < size; i++){
			if( ( vector_euclidean_distance( data_table[i]->vector0, query->vector0) <= minimum_distance) 
				&& (0 != strcmp(data_table[i]->name, query->name)) ){
				minimum_distance= vector_euclidean_distance( data_table[i]->vector0, query->vector0);
				minimum= data_table[i]->name;
			}
		}
	else if(vector_metric_0 == cosine_metric)
		for(i= 0; i < size; i++){
			if( ( vector_cosine_distance( data_table[i]->vector0, query->vector0) <= minimum_distance) 
				&& (0 != strcmp(data_table[i]->name, query->name)) ){
				minimum_distance= vector_cosine_distance( data_table[i]->vector0, query->vector0);
				minimum= data_table[i]->name;
			}
		}
	clock_gettime(CLOCK_MONOTONIC, &stop);
	fprintf(stream, "distanceTrue: %lf\ntTrue: %lld seconds and %lld microseconds\n", minimum_distance, 
		(long long) (stop.tv_sec - start.tv_sec), (long long) (stop.tv_nsec - start.tv_nsec));
	return 0;
}