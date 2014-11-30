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

typedef enum Metric_space{
	hamming,
	euclidean,
	distance_matrix
} metric_space;

bucket ** hash_table_constructor(
	element ** data_table,
	int data_table_size,
	int * hash_table_size,
	seed ** seed_0_PPtr,
	int k,
	metric_space current_space);

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
	metric_space current_space);

element ** generic_parser(
	FILE * stream,
	int * dt_size,
	metric_space current_space);

double ** general_generate_distance_matrix(
	void * data_table,
	int dt_size,
	metric_space current_space);

int general_clean_distance_matrix(
	double ** distance_matrix_2,
	int size);

#ifdef	__cplusplus
}
#endif

#endif	/* LSH_STRUCTS_H */

