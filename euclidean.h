/* 
 * File:   euclidean.h
 * Author: Infiknight
 *
 * Created on October 20, 2014, 10:21 PM
 */

#ifndef EUCLIDEAN_H
#define	EUCLIDEAN_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdio.h>
#include "bucket.h"
#include "vector.h"

/**
 * Euclidean version of the LSH.
 * @param stream
 * @param L
 * @param k
 * @return 
 */
int euclidean_LSH(
	FILE * stream,
	int L,
	int k);
	
#ifdef	__cplusplus
}
#endif

#endif	/* EUCLIDEAN_H */

