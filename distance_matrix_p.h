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
	
struct Element{
	char * name;
	int * array;
};
typedef struct Element element;	
	

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
int dm_L_search(
	int L,
	FILE * stream,
	seed ** seed_0,
	bucket *** hash_table,
	element * data_table,
	int radius,
	element * query);

/**
 * COnstructs a hash table (table of pointers to buckets) and returns a pointer to it.
 * @param data_table The datatable our hashtable is going to be based on.
 * @param data_table_size
 * @param hash_table_size pointer to our hash_table's size.
 * @param seed_0 a seed that identifies our hash_table
 * @return array of pointers to buckets.
 */
bucket ** dm_hash_table_constructor(
	element * data_table,
	int data_table_size,
	int * hash_table_size,
	seed * seed_0);

/**
 * Exhaustive search of the nearest with respect to q neighboor in the data_table.
 * @param data_table
 * @param size Size of the datatable.
 * @param item_index item no of the query.
 * @param stream Where to output our results.
 * @return 
 */
int dm_exhaustive_search(
	element * data_table,
	int size,
	element * query,
	FILE * stream);

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
	element * data_table,
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
	element * data_table,
	int data_table_size);

/**
 * The concatenation of our hashes
 * @param data_table
 * @param seed_0 the seed of our hashtable
 * @param query the item we want to hash
 * @return the hash value
 */
int dm_concatenated_hash(
	element * data_table,
	seed const * const seed_0,
	element * query);

/**
 * Constructs our data_table from some input file
 * @param stream The input stream
 * @param data_table
 * @param dimensions The size of our data_table
 * @return The size of our data_table
 */
int dm_parser(
	FILE * stream,
	element ** data_table,
	int * dimensions);

#ifdef	__cplusplus
}
#endif

#endif	/* DISTANCE_MATRIX_P_H */

