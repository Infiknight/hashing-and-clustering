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
	
#define W_SIZE 4
#define K_SIZE 4
	
struct Element{
	char * name;
	vector * vector0;
};

typedef struct Seed seed;

typedef struct Element element;	
	
int parser(
	FILE * stream,
	element ** hash_table);

int parser_clean(
	element * data_table,
	int size);

#ifdef	__cplusplus
}
#endif

#endif	/* EUCLIDEAN_H */

