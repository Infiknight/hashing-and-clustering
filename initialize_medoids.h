/* 
 * File:   initialize_medoids.h
 * Author: Infiknight
 *
 * Created on December 2, 2014, 12:31 AM
 */

#ifndef INITIALIZE_MEDOIDS_H
#define	INITIALIZE_MEDOIDS_H

#ifdef	__cplusplus
extern "C" {
#endif

int * initialize(
	double ** distance_matrix,
	int size,
	int k,
	int choice);

#ifdef	__cplusplus
}
#endif

#endif	/* INITIALIZE_MEDOIDS_H */

