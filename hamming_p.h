/* 
 * File:   hamming_p.h
 * Author: Infiknight
 *
 * Created on December 1, 2014, 11:04 AM
 */

#ifndef HAMMING_P_H
#define	HAMMING_P_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "bucket.h"

typedef struct Element{	
	char * name;
	char * str;
	int position_in_dt;
} element;


struct hash_table_t {
    int size;       /* the size of the table */
    bucket ** table; /* the table elements */
    int * hIndexes; /* the array of the indexes of h*/
    int k; /*k: number of h*/
};

typedef struct Seed{
	int * hIndexes;
	int k;
} seed;

struct hash_table_t * hamming_hash_table_constructor_2( element ** data_table, int data_table_size, int k);

int g(char* str, int * hindexes, int k);

int binaryStringToDecimal(char *str);

int hammingDistance(char *str1, char *str2);

#ifdef	__cplusplus
}
#endif

#endif	/* HAMMING_P_H */

