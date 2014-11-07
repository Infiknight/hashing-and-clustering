/* 
 * File:   euclidean_p.h
 * Author: Infiknight
 *
 * Created on October 23, 2014, 9:51 PM
 */

#ifndef EUCLIDEAN_P_H
#define	EUCLIDEAN_P_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdio.h>
#include "bucket.h"
#include "vector.h"
	
	//largest prime under 2^28
#define PRIME 268435399
#define W_SIZE 4
#define N_DENOMINATOR 1


struct Element{
	char * name;
	vector * vector0;
};
typedef struct Element element;		

typedef struct Augmented_data{
	element * data;	///the actual data
	int augment;	/// holds the value before the application of the strict mod
} augmented_data;

//this seed identifies uniquely a hashtable and it's hash function
typedef struct Seed{
	vector ** vector_table;
	double * t_table;
	int w, k, n;
} seed;
	
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
int euc_L_search(
	int L, 
	FILE * stream,
	seed ** seed_0,
	bucket *** hash_table,
	element * data_table,
	double radius,
	int item_index);

/**
 * Exhaustive search for the nearest neighbour of the query in the data_table.
 * @param data_table
 * @param size The size of the datatable
 * @param item_index Item index of the query
 * @param stream output sttream
 * @return 0=ok
 */
int euc_exhaustive_search(
	element * data_table,
	int size,
	int item_index,
	FILE * stream);

/**
 * Hash function based on the concatenation of other more basic functs
 * @param vector_0 The vector which we are going to hash.
 * @param seed_0 The seed which identifies an instance of this function
 * @param identifying_value The augment used to craft an augmented datum
 * @return 
 */
int euc_concatenated_hash_function(
	vector const * const vector_0,
	seed const * const seed_0,
	int * identifying_value);

/**
 * Parses the input stream to build our data table
 * @param stream Input stream
 * @param data_table THe data table in question
 * @return Size of the data_table
 */
int euc_parser(
	FILE * stream,
	element ** data_table);

/**
 * Deallocates the memeory allocated for teh data table
 * @param data_table
 * @param size
 * @return 
 */
int euc_parser_clean(
	element * data_table,
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
	element * data_table,
	int data_table_size,
	int * hash_table_size,
	seed ** seed_0_PPtr,
	int k);

/**
 * basic linear search in a bucket of our hash table
 * @param query The query whose bucket we gotta find and search inside
 * @param hash_table
 * @param results Pointer to an array of search results found up to now (and update with new)
 * @param current_results_no results found before the search (we add to this the no of the new ones)
 * @param seed_0 Seed of the hash table
 * @param radius Radius of our search (0 for NN only)
 * @return
 */
int euc_search(
	vector const * const query,
	bucket ** hash_table,
	element *** results,
	int * current_results_no,
	seed const * const seed_0,
	double radius);
	
/**
 * Used by the concatenated hash function
 * @param vector_0 First vector used for the hash
 * @param vector_1 Second vector 
 * @param t perturbation
 * @param w size of cell
 * @return The base hash
 */
long long euc_base_hash_function(
	vector const * const vector_0,
	vector const * const vector_1,
	double t,
	int w);

#ifdef	__cplusplus
}
#endif

#endif	/* EUCLIDEAN_P_H */

