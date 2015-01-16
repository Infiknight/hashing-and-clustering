#include "euclidean.h"
#include "compare.h"
#include "LSH_recommend.h"
#include <float.h>
#include <stdlib.h>

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
	vector_metric vector_metric_0)
{
	int L= number_of_hash_tables;
	int k= number_of_hash_functions;
	int i, j;
	int * hash_table_size;
	seed ** seed_table;
	element * query;
	element ** results;
	bucket *** hash_table;
	double max_range= 0;
	for(i= 0; i < dt_size; i++){
		if(max_range < distance_matrix[no_query][i])
			max_range= distance_matrix[no_query][i];
	}
	double min_difference= max_range/10000;
	double radius= max_range/2;
	if(*seeds_h_tables == NULL){
		*seeds_h_tables= malloc(sizeof(seed_table_bundle));
		seed_table= malloc(L*sizeof(seed*));
		hash_table= malloc(L*sizeof(bucket**));
		hash_table_size= malloc(L*sizeof(int));
		((seed_table_bundle*) *seeds_h_tables)->seed_table= seed_table;
		((seed_table_bundle*) *seeds_h_tables)->hash_table= hash_table;
		((seed_table_bundle*) *seeds_h_tables)->hash_table_size= hash_table_size;
		for(i= 0; i < L; i++){
			hash_table[i]= hash_table_constructor(data_table, dt_size, &(hash_table_size[i]), &(seed_table[i]), k, current_metric_space, vector_metric_0);
		}
	}
	else{
		seed_table= ((seed_table_bundle*) *seeds_h_tables)->seed_table;
		hash_table= ((seed_table_bundle*) *seeds_h_tables)->hash_table;
		hash_table_size= ((seed_table_bundle*) *seeds_h_tables)->hash_table_size;
	}
	FILE * qstream= fopen("output2.txt", "w");
	double previous_difference= radius/2;
	int results_no,
		last_iteration= 0;
	do{
		query= data_table[ no_query ];
		results= L_search(
			L,
			qstream,
			seed_table,
			hash_table,
			data_table,
			radius,
			query,
			&results_no,
			current_metric_space,
			vector_metric_0);
		if((results_no < higher_bound) && (results_no > lower_bound))
			break;
		else if(results_no > higher_bound)
			radius-= previous_difference;
		else if(results_no < lower_bound)
			radius+= previous_difference;
		if(min_difference < previous_difference)
			previous_difference/= 2;
		else
			last_iteration++;
		if(last_iteration == 1){
			if(results_no > higher_bound){
				results_no= higher_bound;
				results= (element**) realloc(results, results_no*sizeof(element*));
			}
			break;
		}
	}while(1);
	int * nearest_neighbors= (int*) malloc(results_no*sizeof(int));
	for(i= 0; i < results_no; i++){
		nearest_neighbors[i]= get_element_pos(results[i], current_metric_space);
	}
	*no_neighbors= results_no;
	return nearest_neighbors;
	//for(i= 0; i < L; i++){
	//	free(hash_table[i]);
	//}
	//free(hash_table);
	//free(seed_table);
}

tagged_double * find_top_recommendations(
	int no_query,
	int top_limit,
	int * neighbors,
	int no_neighbors,
	element ** data_table,
	double ** distance_matrix)
{
	int no_items= euc_get_dimensions(data_table[0]);
	tagged_double * rating= (tagged_double*) malloc(no_items*sizeof(tagged_double));
	int * unrated_items= (int*) malloc(no_items*sizeof(int));
	int i, j;
	double z= 0;
	for(i= 0; i < no_items; i++){
		rating[i].tag= i;
		if(euc_get_vector_element(data_table[no_query], i) == 0){
			unrated_items[i]= 1;
			rating[i].value= 0;
		}
		else{
			unrated_items[i]= 0;
			rating[i].value= euc_get_vector_element(data_table[no_query], i);
		}
	}
	for(i= 0; i < no_neighbors; i++){
		z+= distance_matrix[no_query][neighbors[i]];
	}
	for(i= 0; i < no_items; i++){
		if(unrated_items[i] == 0)
			continue;
		for(j= 0; j < no_neighbors; j++){
			rating[i].value+= distance_matrix[no_query][neighbors[j]]*euc_get_vector_element(data_table[j], i);
		}
		rating[i].value/= z;
	}
	qsort(rating, no_items, sizeof(tagged_double), comp_tagged_double);
	int count= 0;
	tagged_double * top_ratings= (tagged_double*) malloc(top_limit*sizeof(tagged_double));
	for(i= no_items; i >= 0; i--){
		if(unrated_items[i] == 1){
			top_ratings[count]= rating[i];
			count++;
		}
		if(count >= top_limit)
			break;
	}
	free(rating);
	free(unrated_items);
	return top_ratings;
}