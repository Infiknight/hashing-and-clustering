/* 
 * File:   initialize.h
 * Author: Infiknight
 *
 * Created on November 18, 2014, 2:57 PM
 */

#ifndef INITIALIZE_H
#define	INITIALIZE_H

#ifdef	__cplusplus
extern "C" {
#endif

/**
 * Initialize k medoids using a spread out pattern if choice == 1 or a 
 * concentrated pattern in choice == 2
 * @param distance_matrix The distance matrix of our data
 * @param size Size of the distance matrix
 * @param k Number of medoids
 * @param choice
 * @return Array of the positions of the medoids in the dataset/distance matrix
 */
int * initialize(
	double ** distance_matrix,
	int size,
	int k,
	int choice);

#ifdef	__cplusplus
}
#endif

#endif	/* INITIALIZE_H */

