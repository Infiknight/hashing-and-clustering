/* 
 * File:   update_medoids.h
 * Author: Infiknight
 *
 * Created on December 1, 2014, 11:38 PM
 */

#ifndef UPDATE_MEDOIDS_H
#define	UPDATE_MEDOIDS_H

#ifdef	__cplusplus
extern "C" {
#endif

int * update_medoids(
	int choice,
	int * assignment,
	double ** distance_matrix,
	element ** data_table,
	int dt_size,
	int * old_medoids,
	int k,
	metric_space current_space);


#ifdef	__cplusplus
}
#endif

#endif	/* UPDATE_MEDOIDS_H */

