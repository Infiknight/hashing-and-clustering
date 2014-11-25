/* 
 * File:   euclidean.h
 * Author: Infiknight
 *
 * Created on October 20, 2014, 10:21 PM
 */

#ifndef EUCLIDEAN_H
#define	EUCLIDEAN_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdio.h>
#include "bucket.h"
#include "vector.h"
#include "LSH_structs.h"
	
/**
 * Euclidean version of the LSH.
 * @param stream
 * @param L
 * @param k
 * @return 
 */
int euclidean_LSH(
	FILE * stream,
	int L,
	int k);

double euc_distance(
	void * data_table,
	int index_1,
	int index_2);

char * euc_get_element_name(
	element * element_ptr);

//-----------------------------------------------------------

/**
 * The LSH uses this to search the L hashtables
 * @param L number of hashtables to check
 * @param stream The output stream
 * @param seed_0 Array of seeds 
 * @param hash_table Array of hash_tables 
 * @param data_table 
 * @param radius The radius of our search
 * @param item_index Item index of our query
 * @return 1= error 0=ok
 */
element ** euc_L_search(
	int L, 
	FILE * stream,
	seed ** seed_0,
	bucket *** hash_table,
	element ** data_table,
	double radius,
	element * query,
	int * results_no);

/**
 * Exhaustive search for the nearest neighbour of the query in the data_table.
 * @param data_table
 * @param size The size of the datatable
 * @param item_index Item index of the query
 * @param stream output sttream
 * @return 0=ok
 */
int euc_exhaustive_search(
	element ** data_table,
	int size,
	element * query,
	FILE * stream);

/**
 * Parses the input stream to build our data table
 * @param stream Input stream
 * @param data_table THe data table in question
 * @return Size of the data_table
 */
element ** euc_parser(
	FILE * stream,
	int * dt_size);

int euc_get_element_pos(
	element * element_ptr);

/**
 * Deallocates the memeory allocated for teh data table
 * @param data_table
 * @param size
 * @return 
 */
int euc_parser_clean(
	element ** data_table,
	int size);

/**
 * Constructs a hash table nondeterministically based on the data_table
 * @param data_table
 * @param data_table_size
 * @param hash_table_size pointer to an int whose memory has already been allocated
 * @param seed_0_PPtr The seed is randomly  generated and identifies the hash table and it's hashing function
 * @param k How many basic hash functions to concatenate in order to craft the main hashing function
 * @return Don't really remember 
 */
bucket ** euc_hash_table_constructor(
	element ** data_table,
	int data_table_size,
	int * hash_table_size,
	seed ** seed_0_PPtr,
	int k);

#ifdef	__cplusplus
}
#endif

#endif	/* EUCLIDEAN_H */

