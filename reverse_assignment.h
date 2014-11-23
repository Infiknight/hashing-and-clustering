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

enum metric_space{
	hamming,
	euclidean,
	metric
};
	
int * reverse_assignment(
	int * medoids,
	int medoids_size,
	double ** distance_matrix,
	element * data_table,
	int dt_size,
	enum metric_space current_metric_space);


#ifdef	__cplusplus
}
#endif

#endif	/* REVERSE_ASSIGNMENT_H */

