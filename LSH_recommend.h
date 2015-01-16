/* 
 * File:   LSH_recommend.h
 * Author: Infiknight
 *
 * Created on January 16, 2015, 11:46 AM
 */

#ifndef LSH_RECOMMEND_H
#define	LSH_RECOMMEND_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "compare.h"
#include "LSH_structs.h"

int LSH_recommend(
	FILE * fpInput,
	FILE *fpOutput,
	int top_limit,
	vector_metric vector_metric_0,
	int numOfHashFunctions,
	int L);
	
int * repeated_binary_search(
	int no_query,
	int * no_neighbors,
	int lower_bound,
	int higher_bound,
	void ** seeds_h_tables,
	element ** data_table,
	int dt_size,
	double ** distance_matrix,
	int number_of_hash_functions,
	int number_of_hash_tables,
	metric_space current_metric_space,
	vector_metric vector_metric_0);

tagged_double * find_top_recommendations(
	int no_query,
	int top_limit,
	int * neighbors,
	int no_neighbors,
	element ** data_table,
	double ** distance_matrix);

#ifdef	__cplusplus
}
#endif

#endif	/* LSH_RECOMMEND_H */

