/* 
 * File:   assign_to_clusters.h
 * Author: Infiknight
 *
 * Created on December 1, 2014, 9:23 PM
 */

#ifndef ASSIGN_TO_CLUSTERS_H
#define	ASSIGN_TO_CLUSTERS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "LSH_structs.h"
	
/**
 * Second step of the clustering process (first to repeat)
 * Assign points to clusters signified by medoids given as arguments
 * @param choice
 * @param medoids
 * @param k
 * @param data_table
 * @param dt_size
 * @param current_space
 * @return 
 */
int * assign_to_clusters(
	void ** seeds_h_tables,
	int choice,
	int * medoids,
	int k,
	element ** data_table,
	double ** distance_matrix,
	int dt_size,
	int number_of_hash_functions,
	int number_of_hash_tables,
	metric_space current_space);


#ifdef	__cplusplus
}
#endif

#endif	/* ASSIGN_TO_CLUSTERS_H */

