#include "LSH_recommend.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "k-medoids.h"
#include "sys/time.h"
#include "assign_to_clusters.h"
#include "initialize_medoids.h"
#include "update_medoids.h"
#include "silhouette.h"
#include "cluster.h"
#include "compare.h"

#define LOWER_BOUND 20
#define HIGHER_BOUND 50

int LSH_recommend(
	FILE * fpInput,
	FILE *fpOutput,
	int top_limit,
	vector_metric vector_metric_0,
	int numOfHashFunctions,
	int L)
{
	metric_space current_space= euclidean;
	int i, j;
	int dt_size;
	struct timeval start, end;
	void * seeds_and_htables= NULL;
	element ** data_table= NULL;
	double ** distance_matrix_2;
	gettimeofday(&start, NULL);
	data_table= generic_parser(fpInput, &dt_size, current_space, 1000);
	distance_matrix_2= general_generate_distance_matrix((void*)data_table, dt_size, current_space, vector_metric_0);
	int no_neighbors;
	fprintf(fpOutput, "NN LSH\n");
	for(j= 0; j < dt_size; j++){
		int * neighbors= repeated_binary_search(
			j,
			&no_neighbors,
			LOWER_BOUND,
			HIGHER_BOUND,
			&seeds_and_htables,
			data_table,
			dt_size,
			distance_matrix_2,
			numOfHashFunctions,
			L,
			current_space,
			vector_metric_0);
		tagged_double * top_recs= find_top_recommendations(
			j,
			top_limit,
			neighbors,
			no_neighbors,
			data_table,
			distance_matrix_2);
		for(i= 0; i < no_neighbors; i++){
			//printf("%d: %d\n", i, neighbors[i]);
		}
		fprintf(fpOutput, "%d	", j);
		for(i= 0; i < top_limit; i++){
			//printf("top %d: item %d rating %lf\n", i+1, top_recs[i].tag, top_recs[i].value);
			fprintf(fpOutput, "%d	", top_recs[i].tag);
		}
		fprintf(fpOutput, "\n");
	}
	gettimeofday(&end, NULL);
	fprintf(fpOutput, "Execution time: %f seconds\n", ((end.tv_sec * 1000000 + end.tv_usec)- (start.tv_sec * 1000000 + start.tv_usec))/1000000.00);
	return 0;
}