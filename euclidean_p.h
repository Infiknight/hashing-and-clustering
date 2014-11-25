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
#include "euclidean.h"
	
	//largest prime under 2^28
#define PRIME 268435399
#define W_SIZE 16
#define N_DENOMINATOR 1


struct Element{
	int position_in_dt;
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

