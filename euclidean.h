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

typedef struct Element element;
	
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

double euc_distance(
	void * data_table,
	int index_1,
	int index_2);

#ifdef	__cplusplus
}
#endif

#endif	/* EUCLIDEAN_H */

