/* 
 * File:   general_distance_matrix.h
 * Author: Infiknight
 *
 * Created on November 19, 2014, 12:20 PM
 */

#ifndef GENERAL_DISTANCE_MATRIX_H
#define	GENERAL_DISTANCE_MATRIX_H

#ifdef	__cplusplus
extern "C" {
#endif

/**
 * Use the data table to generate a distance matrix.
 * @param data_table
 * @param dt_size Size of the data table
 * @return The 2-d distance matrix
 */
double ** generate_distance_matrix(
	double (*distance_function)(void*, int, int),
	element * data_table,
	int dt_size);

/**
 * Free the memory allocated to the distance matrix.
 * @param distance_matrix_2
 * @param size
 * @return 0 if everything's ok
 */
int clean_distance_matrix(
	double ** distance_matrix_2,
	int size);


#ifdef	__cplusplus
}
#endif

#endif	/* GENERAL_DISTANCE_MATRIX_H */

