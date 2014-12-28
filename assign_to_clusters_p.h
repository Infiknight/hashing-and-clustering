/* 
 * File:   assign_to_clusters_p.h
 * Author: Infiknight
 *
 * Created on December 1, 2014, 8:48 PM
 */

#ifndef ASSIGN_TO_CLUSTERS_P_H
#define	ASSIGN_TO_CLUSTERS_P_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "LSH_structs.h"
#include "cluster.h"

cluster * PAM(
	double ** distance_matrix, 
	int * medoids, 
	int size, 
	int k);

int * reverse_assignment(
	void ** seeds_h_tables,
	int * medoids,
	int medoids_size,
	double ** distance_matrix,
	element ** data_table,
	int dt_size,
	int number_of_hash_functions,
	int number_of_hash_tables,
	metric_space current_metric_space);

int * clusterToArray(cluster * clusters, int k);

#ifdef	__cplusplus
}
#endif

#endif	/* ASSIGN_TO_CLUSTERS_P_H */

