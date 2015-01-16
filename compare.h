/* 
 * File:   compare.h
 * Author: Infiknight
 *
 * Created on November 18, 2014, 12:26 PM
 */

#ifndef COMPARE_H
#define	COMPARE_H

#ifdef	__cplusplus
extern "C" {
#endif

struct Tagged_double{
	int tag;
	double value;
};
typedef struct Tagged_double tagged_double;
	
int comp_int(
	const void * elem1,
	const void * elem2);

/**
 * Compare doubles elem1 and elem2 and return 1 if elem1 is greater than elem2,
 * -1 if elem2 is greater than elem1 and 0 if they are equal
 * @param elem1
 * @param elem2
 * @return
 */
int comp_double(
	const void * elem1,
	const void * elem2);

/**
 * Compare tagged doubles in the same way we would compare doubles: 1 if
 * elem1 greater than elem2 0 if equal -1 otherwise
 * @param elem1
 * @param elem2
 * @return 
 */
int comp_tagged_double(
	const void * elem1,
	const void * elem2);

#ifdef	__cplusplus
}
#endif

#endif	/* COMPARE_H */

