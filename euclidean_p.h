/* 
 * File:   euclidean_p.h
 * Author: Infiknight
 *
 * Created on October 23, 2014, 9:51 PM
 */

#ifndef EUCLIDEAN_P_H
#define	EUCLIDEAN_P_H

#ifdef	__cplusplus
extern "C" {
#endif

	//largest prime under 2^28
#define PRIME 268435399
	

	
int concatenated_hash_function(
	vector const * const vector_0,
	seed const * const seed_0,
	int * identifying_value);

	


long long base_hash_function(
	vector const * const vector_0,
	vector const * const vector_1,
	double t,
	int w);

#ifdef	__cplusplus
}
#endif

#endif	/* EUCLIDEAN_P_H */

