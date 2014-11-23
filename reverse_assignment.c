#include "euclidean_p.h"

enum metric_space{
	hamming,
	euclidean,
	metric
};

int reverse_assignment(
	int * medoids,
	int medoids_size,
	double ** distance_matrix,
	element * data_table,
	int dt_size,
	metric_space current_metric_space)
{
	int L= 20;
	int k= 5;
	int i, j;
	int * medoid_allocation_table= malloc(dt_size * sizeof(int));
	int iteration_table[dt_size];
	for(i= 0; i < dt_size; i++){
		medoid_allocation_table[i]= -1;
		iteration_table[i]= 0;
	}
	double radius= distance_matrix[ medoids[0] ][ medoids[1] ];
	double current_distance;
	for(i= 0; i < medoids_size-1; i++){
		for(j= i+1; j < medoids_size; j++){
			current_distance= distance_matrix[ medoids[i] ][ medoids[j] ];
			if(radius > current_distance)
				radius= current_distance;
		}
	}
	radius/= 2;
	int  hash_table_size[L];
	seed * seed_table[L];
	bucket ** hash_table[L];
	for(i= 0; i < L; i++){
		hash_table[i]= euc_hash_table_constructor(data_table, dt_size, &(hash_table_size[i]), &(seed_table[i]), k );
	}
	int results_no;
	FILE * qstream= fopen("output.txt", "w");
	element * query= &(data_table[15]);
	element ** results= euc_L_search(
		L,
		qstream,
		seed_table,
		hash_table,
		data_table,
		radius,
		query,
		&results_no);
	euc_exhaustive_search(
		data_table,
		dt_size,
		query,
		qstream);
	fclose(qstream);
	//CLEANUP
	euc_parser_clean(
		data_table,
		dt_size);
	free(results);
	int j;
	for(i= 0; i < L; i++){
		for(j= 0;j <  hash_table_size[j]; j++){
			bucket_destruct(hash_table[i][j]);
		}
		free(hash_table[i]);
	}
}