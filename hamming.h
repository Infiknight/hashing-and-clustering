#include "list.h"
#include "bucket.h"

#ifndef HAMMING_H
#define	HAMMING_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "LSH_structs.h"

element ** hamming_parser(
	FILE *fp,
	int *arrSize);

element ** hamming_L_search(
	int L,
	FILE * stream,
	seed ** seed_0,
	bucket *** hash_table,
	element ** data_table,
	int radius,
	element * query,
	int * results_no);

bucket ** hamming_hash_table_constructor(
	element ** data_table,
	int data_table_size,
	int * hash_table_size,
	seed ** seed_0_PPtr,
	int k);

double hamming_distance(
	void * data_table,
	int index_1,
	int index_2);

int hamming_get_element_pos(
	element * element_ptr);

char * hamming_get_element_name(
	element * element_ptr);

#ifdef	__cplusplus
}
#endif

#endif	