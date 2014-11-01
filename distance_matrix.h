/* 
 * File:   distance_matrix.h
 * Author: Infiknight
 *
 * Created on October 29, 2014, 9:55 AM
 */

#ifndef DISTANCE_MATRIX_H
#define	DISTANCE_MATRIX_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "bucket.h"
#include <stdio.h>
	
/**
 * The distance_matrix version of the LSH
 * @param stream Out data sample.
 * @param L How many hash tablees we r going to use.
 * @param k (It ignores this value and uses K_SIZE instead which is defined in distance_matrix_p.h)
 * @return 0 ok 1 error
 */
int distance_matrix_LSH(
	FILE * stream,
	int L,
	int k);
	
#ifdef	__cplusplus
}
#endif

#endif	/* DISTANCE_MATRIX_H */

