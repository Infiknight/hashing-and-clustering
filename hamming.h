#include "list.h"
#include "bucket.h"

#ifndef HAMMING_H
#define	HAMMING_H

#ifdef	__cplusplus
extern "C" {
#endif


struct hamming{	
	char * name;
	char * str;
};


struct hash_table_t {
    int size;       /* the size of the table */
    bucket ** table; /* the table elements */
    int * hIndexes; /* the array of the indexes of h*/
    int k; /*k: number of h*/
};



struct hamming * parser(FILE *fp, int *arrSize);

struct hash_table_t * hamming_hash_table_constructor(struct hamming* data_table, int data_table_size, int k);

int g(char* str, int * hindexes, int k);

int binaryStringToDecimal(char *str);

int hammingDistance(char *str1, char *str2);





#ifdef	__cplusplus
}
#endif

#endif	