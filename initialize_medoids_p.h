/* 
 * File:   initialize_medoids_p.h
 * Author: Infiknight
 *
 * Created on December 2, 2014, 12:10 AM
 */

#ifndef INITIALIZE_MEDOIDS_P_H
#define	INITIALIZE_MEDOIDS_P_H

#ifdef	__cplusplus
extern "C" {
#endif

int * concentrate(
	double ** distance_matrix,
	int size,
	int k);

int * Spreadout(
	double ** distance_matrix, 
	int size, 
	int k);

#ifdef	__cplusplus
}
#endif

#endif	/* INITIALIZE_MEDOIDS_P_H */

