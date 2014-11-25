#include <float.h>
#include <limits.h>
#include <stdlib.h>
#include "reverse_assignment.h"
//asdkjgflshdgfj
int * reverse_assignment(
	int * medoids,
	int medoids_size,
	double ** distance_matrix,
	element ** data_table,
	int dt_size,
	metric_space current_metric_space,
	bucket ** (*hash_table_constructor)(element **,int,int *,seed **,int),
	element ** (*L_search)(int, FILE *,seed **,bucket ***,element **,double,element *,int *))
{
	int L= 50;
	int k= 4;
	int i, j,
		currently_allocated= 0;
	int * medoid_allocation_table= malloc(dt_size * sizeof(int));
	int no_iteration_table[dt_size];
	for(i= 0; i < dt_size; i++){
		medoid_allocation_table[i]= -1;
		no_iteration_table[i]= -1;
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
		hash_table[i]= hash_table_constructor(data_table, dt_size, &(hash_table_size[i]), &(seed_table[i]), k );
	}
	int results_no;
	element * query;
	element ** results;
	int element_position,
		current_iteration= 0;
	FILE * qstream= fopen("output.txt", "w");
	while( radius < DBL_MAX/2 && currently_allocated <= dt_size){	//until radius reaches threshold or all points assigned
		for(i= 0; i < medoids_size; i++){
			query= data_table[ medoids[i] ];
			results= L_search(
				L,
				qstream,
				seed_table,
				hash_table,
				data_table,
				radius,
				query,
				&results_no);
			for(j= 0; j < results_no; j++){
				element_position= get_element_pos(results[j], current_metric_space);	//get current result's position in the data table
				if( no_iteration_table[element_position] == -1 ){	//allocate to medoid if free
					medoid_allocation_table[element_position]= i;
					no_iteration_table[element_position]= current_iteration;
					currently_allocated++;
				}
				else if(no_iteration_table[element_position] == current_iteration){	//if current medoid closer than previous one, update
					if( distance_matrix[ medoids[medoid_allocation_table[element_position]] ][ element_position ] > distance_matrix[ medoids[i] ][ element_position ] )
						medoid_allocation_table[element_position]= i;
				}
			}
		}
		free(results);
		radius*= 2;
		current_iteration++;
	}
	double minimum_distance;
	for(i= 0; i < dt_size; i++){
		if(currently_allocated == dt_size)
			break;
		if(medoid_allocation_table[i] == -1){
			medoid_allocation_table[i]= 0;
			minimum_distance= distance_matrix[ i ][ medoids[0] ];
			currently_allocated++;
			for(j= 1; j < medoids_size; j++){
				if( minimum_distance > distance_matrix[ i ][ medoids[j] ]){
					minimum_distance= distance_matrix[ i ][ medoids[j] ];
					medoid_allocation_table[i]= j;
				}
			}
		}
	}
	for(i= 0; i < dt_size; i++){
		fprintf(qstream, "%s ' s medoid is %d\n", get_element_name(data_table[i], current_metric_space), medoid_allocation_table[i]);
	}
	fclose(qstream);
	//CLEANUP
	euc_parser_clean(
		data_table,
		dt_size);
	//int j;
	for(i= 0; i < L; i++){
		for(j= 0;j <  hash_table_size[j]; j++){
			bucket_destruct(hash_table[i][j]);
		}
		free(hash_table[i]);
	}
	return medoid_allocation_table;
}
