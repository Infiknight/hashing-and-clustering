#include "LSH_structs.h"
#include "euclidean.h"
#include "distance_matrix.h"
#include "hamming.h"
#include "proteins.h"
#include <stdlib.h>

int get_element_pos(
	element * element_ptr,
	metric_space current_space)
{
	if(current_space == euclidean)
		return euc_get_element_pos(element_ptr);
	else if((current_space == distance_matrix) || (current_space == protein_c_rmsd) || (current_space == protein_d_rmsd))
		return dm_get_element_pos(element_ptr);
	else if(current_space == hamming)
		return hamming_get_element_pos(element_ptr);
	return -1;
}

char * get_element_name(
	element * element_ptr,
	metric_space current_space)
{
	if(current_space == euclidean)
		return euc_get_element_name(element_ptr);
	else if((current_space == distance_matrix) || (current_space == protein_c_rmsd) || (current_space == protein_d_rmsd))
		return dm_get_element_name(element_ptr);
	else if(current_space == hamming)
		return hamming_get_element_name(element_ptr);
	return NULL;
}

bucket ** hash_table_constructor(
	element ** data_table,
	int data_table_size,
	int * hash_table_size,
	seed ** seed_0_PPtr,
	int k,
	metric_space current_space,
	vector_metric vector_metric_0)
{
	if(current_space == euclidean)
		return euc_hash_table_constructor(
			data_table,
			data_table_size,
			hash_table_size,
			seed_0_PPtr,
			k,
			vector_metric_0);
	else if((current_space == distance_matrix) || (current_space == protein_c_rmsd) || (current_space == protein_d_rmsd))
		return dm_hash_table_constructor(
			data_table,
			data_table_size,
			hash_table_size,
			seed_0_PPtr,
			k);
	else if(current_space == hamming)
		return hamming_hash_table_constructor(
			data_table,
			data_table_size,
			hash_table_size,
			seed_0_PPtr,
			k);
	return NULL;
}

element ** L_search(
	int L, 
	FILE * stream,
	seed ** seed_0,
	bucket *** hash_table,
	element ** data_table,
	double radius,
	element * query,
	int * results_no,
	metric_space current_space,
	vector_metric vector_metric_0)
{
	if(current_space == euclidean)
		return euc_L_search(
			L, 
			stream,
			seed_0,
			hash_table,
			data_table,
			radius,
			query,
			results_no,
			vector_metric_0);
	else if((current_space == distance_matrix) || (current_space == protein_c_rmsd) || (current_space == protein_d_rmsd))
		return dm_L_search(
			L, 
			stream,
			seed_0,
			hash_table,
			data_table,
			radius,
			query,
			results_no);
	else if(current_space == hamming)
		return hamming_L_search(
			L, 
			stream,
			seed_0,
			hash_table,
			data_table,
			radius,
			query,
			results_no);
	return NULL;
}

element ** generic_parser(
	FILE * stream,
	int * dt_size,
	metric_space current_space,
	int r)
{
	if(current_space == euclidean)
		return euc_parser(
			stream,
			dt_size);
	else if(current_space == distance_matrix)
		return dm_parser(
			stream,
			dt_size);
	else if(current_space == protein_c_rmsd)
		return protein_parser_c(
			stream,
			dt_size);
	else if(current_space == protein_d_rmsd)
		return protein_parser_d(
			stream,
			dt_size,
			r);
	else if(current_space == hamming)
		return hamming_parser(
			stream,
			dt_size);
	return NULL;
}

double ** general_generate_distance_matrix(
	void * data_table,
	int dt_size,
	metric_space current_space,
	vector_metric vector_metric_0)
{
	double ** distance_matrix_2= (double**) malloc(dt_size * sizeof(double*));
	int i, j;
	for(i= 0; i < dt_size; i++){
		distance_matrix_2[i]= (double*) malloc(dt_size * sizeof(double));
		for(j= 0; j < dt_size; j++){
			if( i < j ){
				if((current_space == distance_matrix) || (current_space == protein_c_rmsd) || (current_space == protein_d_rmsd))
					distance_matrix_2[i][j]= dm_distance( data_table, i, j);
				else if(current_space == euclidean)
					distance_matrix_2[i][j]= euc_distance( data_table, i, j, vector_metric_0);
				else if(current_space == hamming)
					distance_matrix_2[i][j]= hamming_distance( data_table, i, j);
			}
			else if( i == j )
				distance_matrix_2[i][j]= 0;
			else
				distance_matrix_2[i][j]= distance_matrix_2[j][i];
		}
	}
	return distance_matrix_2;
}

int general_clean_distance_matrix(
	double ** distance_matrix_2,
	int size)
{
	int i;
	for(i= 0; i < size; i++){
		free(distance_matrix_2[i]);
	}
	free(distance_matrix_2);
	return 0;
}