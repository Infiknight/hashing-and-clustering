/* 
 * File:   distance_matrix.h
 * Author: Infiknight
 *
 * Created on October 29, 2014, 9:55 AM
 */

#ifndef DISTANCE_MATRIX_H
#define	DISTANCE_MATRIX_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "LSH_structs.h"
#include "bucket.h"
#include <stdio.h>
	
/**
 * Constructs our data_table from some input file
 * @param stream The input stream
 * @param data_table
 * @param dimensions The size of our data_table
 * @return The size of our data_table
 */
element ** dm_parser(
	FILE * stream,
	int * size);
	
/**
 * The distance_matrix version of the LSH
 * @param stream Out data sample.
 * @param L How many hash tablees we r going to use.
 * @param k (It ignores this value and uses K_SIZE instead which is defined in distance_matrix_p.h)
 * @return 0 ok 1 error
 */
int distance_matrix_LSH(
	FILE * stream,
	int L,
	int k);

/**
 * Rad and NN search in the hashtable using a query.
 * @param seed_0
 * @param hash_table
 * @param data_table 
 * @param results pointer to array of results.
 * @param current_results_no Pointer to neighboors found during previous searches.
 * @param radius Radius around the query to look for neighboors.
 * @param item_index Query
 * @return 
 */
element ** dm_L_search(
	int L,
	FILE * stream,
	seed ** seed_0,
	bucket *** hash_table,
	element ** data_table,
	int radius,
	element * query,
	int * results_no);

/**
 * COnstructs a hash table (table of pointers to buckets) and returns a pointer to it.
 * @param data_table The datatable our hashtable is going to be based on.
 * @param data_table_size
 * @param hash_table_size pointer to our hash_table's size.
 * @param seed_0 a seed that identifies our hash_table
 * @return array of pointers to buckets.
 */
bucket ** dm_hash_table_constructor(
	element ** data_table,
	int data_table_size,
	int * hash_table_size,
	seed ** seed_0_PPtr,
	int k);

/**
 * Exhaustive search of the nearest with respect to q neighboor in the data_table.
 * @param data_table
 * @param size Size of the datatable.
 * @param item_index item no of the query.
 * @param stream Where to output our results.
 * @return 
 */
int dm_exhaustive_search(
	element ** data_table,
	int size,
	element * query,
	FILE * stream);

double dm_distance(
	void * data_table,
	int index_1,
	int index_2);

int dm_get_element_pos(
	element * element_ptr);
	
char * dm_get_element_name(
	element * element_ptr);

#ifdef	__cplusplus
}
#endif

#endif	/* DISTANCE_MATRIX_H */

