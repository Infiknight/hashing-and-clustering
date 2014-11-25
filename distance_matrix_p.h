/* 
 * File:   distance_matrix_p.h
 * Author: Infiknight
 *
 * Created on October 30, 2014, 4:27 PM
 */

#ifndef DISTANCE_MATRIX_P_H
#define	DISTANCE_MATRIX_P_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdio.h>	
#include "distance_matrix.h"
	
#define C_FACTOR 1
#define K_SIZE 15
	

	
typedef struct Seed{
	int * x_1;
	int * x_2;
	double * t;
	int k; //K_SIZE
	int dimensions; //size of the hash_table
} seed;
	
typedef struct Element{
	int position_in_dt;
	char * name;
	int * array;
} element;
	



/**
 * Hash search in a bucket.
 * @param seed_0 the seed of the hashtable of our bucket
 * @param hash_table 
 * @param data_table
 * @param results Array of results up to now which is updated with the results of this search
 * @param current_results_no number of results up to now
 * @param radius Radius of our search
 * @param item_index Number of the Query.
 * @return 0=ok 1=error
 */
int dm_search(
	seed const * const seed_0,
	bucket ** hash_table,
	element ** data_table,
	element *** results,
	int * current_results_no,
	int radius,
	element * query);

/**
 * Generate a t value so according to the DBH rules.
 * @param x_1
 * @param x_2
 * @param data_table
 * @param data_table_size
 * @return the t value
 */
double generate_t_value(
	int x_1,
	int x_2,
	element ** data_table,
	int data_table_size);

/**
 * The concatenation of our hashes
 * @param data_table
 * @param seed_0 the seed of our hashtable
 * @param query the item we want to hash
 * @return the hash value
 */
int dm_concatenated_hash(
	element ** data_table,
	seed const * const seed_0,
	element * query);



#ifdef	__cplusplus
}
#endif

#endif	/* DISTANCE_MATRIX_P_H */

