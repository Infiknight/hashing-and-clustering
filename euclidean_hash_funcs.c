#include "euclidean.h"
#include "vector.h"
#include <stdlib.h>
#include <math.h>
#include "bucket.h"
#include "euclidean_p.h"
#include <string.h>

#define CONCAT_SIZE 500
#define RAW_SIZE 500

int euc_euc_concatenated_hash_function(
	vector const * const vector_0,
	seed const * const seed_0,
	int * identifying_value)
{
	char concat_hash_str[CONCAT_SIZE], raw_hash_str[RAW_SIZE];
	memset(concat_hash_str, 0, CONCAT_SIZE);
	int i;
	long long raw_hash, concat_hash;
	for(i= 0; i < seed_0->k; i++){
		raw_hash= euc_euc_base_hash_function(vector_0, seed_0->vector_table[i], seed_0->t_table[i], seed_0->w);
		if(raw_hash < 0){
			raw_hash= llabs(raw_hash);
			if( (raw_hash % 2) == 0)
				raw_hash++;
		}
		else if( (raw_hash % 2) == 1)
			raw_hash++;
		raw_hash%= PRIME;
		raw_hash*= 10;
		memset(raw_hash_str, 0, RAW_SIZE);
		sprintf(raw_hash_str, "%lld", raw_hash);
		strcat(raw_hash_str, concat_hash_str);
		memset(concat_hash_str, 0, CONCAT_SIZE);
		strcpy(concat_hash_str, raw_hash_str);
		concat_hash= strtoll(concat_hash_str, NULL, 10);
		concat_hash%= PRIME;
		memset(concat_hash_str, 0, CONCAT_SIZE);
		sprintf(concat_hash_str, "%lld", concat_hash);
	}
	*identifying_value= (int) concat_hash;
	concat_hash%= seed_0->n;
	return (int) concat_hash;
}

long long euc_euc_base_hash_function(
	vector const * const vector_0,
	vector const * const vector_1,
	double t,
	int w)
{
	double inner_product;
	if( vector_inner_product(vector_0, vector_1, &inner_product) ){
		printf("euc_euc_base_hash_function error at inner_product\n");
		exit(EXIT_FAILURE);
	}
	return floor( (inner_product + t) / w );
}

long long euc_cos_base_hash_function(
	vector const * const vector_0,
	vector const * const vector_1)
{
	double inner_product;
	if( vector_inner_product(vector_0, vector_1, &inner_product))
		exit(EXIT_FAILURE);
	if(inner_product >= 0)
		return 1;
	else
		return 0;
}

int euc_cos_concatenated_hash_function(
	vector const * const vector_0,
	seed const * const seed_0,
	int * identifying_value)
{
	int i;
	long long concat_hash= 0;
	for(i= 0; i < seed_0->k; i++){
		concat_hash= concat_hash << 1;
		concat_hash+= euc_cos_base_hash_function( vector_0, seed_0->vector_table[i]);
	}
	concat_hash%= PRIME;
	*identifying_value= (int) concat_hash;
	concat_hash%= seed_0->n;
	return (int) concat_hash;
}

int euc_concatenated_hash_function(
	vector const * const vector_0,
	seed const * const seed_0,
	int * identifying_value,
	vector_metric vector_metric_0)
{
	if( vector_metric_0 == euclidean_metric)
		return euc_euc_concatenated_hash_function(
			vector_0,
			seed_0,
			identifying_value);
	else if( vector_metric_0 == cosine_metric)
		return euc_cos_concatenated_hash_function(
			vector_0,
			seed_0,
			identifying_value);
	return -1;
}