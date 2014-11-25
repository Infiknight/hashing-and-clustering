#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vector.h"
#include "bucket.h"
#include "euclidean.h"
//#include "euclidean_p.h"

#define LINE_SIZE 10000

int euclidean_LSH(
	FILE * stream,
	int L,
	int k)
{
	int i;
	char line[LINE_SIZE];
	fgets(line, LINE_SIZE, stream);
	fgets(line, LINE_SIZE, stream);
	int size;
	element ** data_table= euc_parser(stream, &size);
	//fclose(stream);
	int item_index;
	double radius;
	int  hash_table_size[L];
	seed * seed_table[L];
	bucket ** hash_table[L];
	for(i= 0; i < L; i++){
		hash_table[i]= euc_hash_table_constructor(data_table, size, &(hash_table_size[i]), &(seed_table[i]), k );
	}
	element ** results= NULL;
	int current_results_no= 0;
	 FILE * qstream= fopen("output.txt", "w");
	printf("Which shall be the radius of our search? (0 for nearest-neighboor)\n");
	fscanf(stdin, "%lf", &radius);
	printf("Which item shall be our query?\nitem");
	fscanf(stdin, "%d", &item_index);
	element * query= data_table[15];
	int results_no;
	euc_L_search(
		L, 
		qstream,
		seed_table,
		hash_table,
		data_table,
		radius,
		query,
		&results_no);
	euc_exhaustive_search(
		data_table,
		size,
		query,
		qstream);
	fclose(qstream);
	//CLEANUP
	euc_parser_clean(
		data_table,
		size);
	free(results);
	int j;
	for(i= 0; i < L; i++){
		for(j= 0;j <  hash_table_size[j]; j++){
			bucket_destruct(hash_table[i][j]);
		}
		free(hash_table[i]);
	}
}
