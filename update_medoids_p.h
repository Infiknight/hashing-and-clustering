/* 
 * File:   update_medoids_p.h
 * Author: Infiknight
 *
 * Created on December 1, 2014, 9:39 PM
 */

#ifndef UPDATE_MEDOIDS_P_H
#define	UPDATE_MEDOIDS_P_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "cluster.h"
#include "LSH_structs.h"
	
int * UpdateAlaLloyd(
	cluster * clusters,
	double ** distance_matrix,
	int k);

int * clarans(
	int k,
	double ** distance_matrix,
	element ** data_table,
	int * medoids,
	int * assignment,
	int n,
	int clarans_set_fraction,
	int clarans_iterations);

#ifdef	__cplusplus
}
#endif

#endif	/* UPDATE_MEDOIDS_P_H */

