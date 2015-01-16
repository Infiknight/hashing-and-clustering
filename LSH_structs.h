/* 
 * File:   LSH_structs.h
 * Author: Infiknight
 *
 * Created on November 25, 2014, 2:19 PM
 */

#ifndef LSH_STRUCTS_H
#define	LSH_STRUCTS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdio.h>
#include "bucket.h"
	
typedef struct Element element;
typedef struct Seed seed;

typedef struct Seed_table_bundle{
	int * hash_table_size;
	seed ** seed_table;
	bucket *** hash_table;
}seed_table_bundle;

typedef enum Metric_space{
	hamming,
	euclidean,
	distance_matrix,
	protein_c_rmsd,
	protein_d_rmsd
} metric_space;

typedef enum{
	euclidean_metric,
	cosine_metric
}vector_metric;

bucket ** hash_table_constructor(
	element ** data_table,
	int data_table_size,
	int * hash_table_size,
	seed ** seed_0_PPtr,
	int k,
	metric_space current_space,
	vector_metric vector_metric_0);

int get_element_pos(
	element * element_ptr,
	metric_space current_space);

char * get_element_name(
	element * element_ptr,
	metric_space current_space);

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
	vector_metric vector_metric_0);

element ** generic_parser(
	FILE * stream,
	int * dt_size,
	metric_space current_space,
	int r);

double ** general_generate_distance_matrix(
	void * data_table,
	int dt_size,
	metric_space current_space,
	vector_metric vector_metric_0);

int general_clean_distance_matrix(
	double ** distance_matrix_2,
	int size);

#ifdef	__cplusplus
}
#endif

#endif	/* LSH_STRUCTS_H */

