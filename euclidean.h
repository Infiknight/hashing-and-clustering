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
	
#define W_SIZE 40
#define K_SIZE 4
#define N_DENOMINATOR 1
	

//typedef struct Seed seed;
	
	struct Element{
	char * name;
	vector * vector0;
};
typedef struct Element element;		

	typedef struct Augmented_data{
	element * data;
	int augment;
} augmented_data;
	
	typedef struct Seed{
	vector ** vector_table;
	double * t_table;
	int w, k, n;
} seed;


	
int parser(
	FILE * stream,
	element ** hash_table);

int parser_clean(
	element * data_table,
	int size);

bucket ** hash_table_constructor(
	element * data_table,
	int data_table_size,
	int * hash_table_size,
	seed ** seed_0_PPtr);

int search(
	vector const * const query,
	bucket ** hash_table,
	seed const * const seed_0,
	double radius);

#ifdef	__cplusplus
}
#endif

#endif	/* EUCLIDEAN_H */

