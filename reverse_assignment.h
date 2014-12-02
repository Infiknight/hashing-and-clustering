/* 
 * File:   reverse_assignment.h
 * Author: Infiknight
 *
 * Created on November 24, 2014, 4:06 PM
 */

#ifndef REVERSE_ASSIGNMENT_H
#define	REVERSE_ASSIGNMENT_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "LSH_structs.h"
#include "bucket.h"
#include <stdio.h>
	
int * reverse_assignment(
	int * medoids,
	int medoids_size,
	double ** distance_matrix,
	element ** data_table,
	int dt_size,
	int number_of_hash_functions,
	int number_of_hash_tables,
	metric_space current_metric_space);


#ifdef	__cplusplus
}
#endif

#endif	/* REVERSE_ASSIGNMENT_H */

