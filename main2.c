/* 
 * File:   main.c
 * Author: Infiknight
 *
 * Created on October 10, 2014, 10:38 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "probability_distr.h"
#include "vector.h"
#include "bucket.h"
#include "euclidean.h"
#include "euclidean_p.h"
//#include "distance_matrix.h"
//#include "distance_matrix_p.h"

#define LINE_SIZE 10000



/*
 * 
 */
int main(int argc, char** argv) {
		srand(time(NULL));
	FILE * stream= fopen("DataEuclidean.csv", "r");
	euclidean_LSH(
	 stream,
	7,
	9);
	/*FILE * stream2= fopen("DistanceMatrix.csv", "r");
	int i2, j2, hash_table_size;
	element * dt;
	int dimensions;
	char trash[LINE_SIZE];
	fgets(trash, LINE_SIZE, stream2);
	int size= parser2(stream2, &dt, &dimensions);
	seed seed_0;
	bucket ** b= hash_table_constructor1(dt, size, &hash_table_size, &seed_0);
	element ** results= NULL;
	int current_results_no= 0;*/
	/*int L= 5;
	int k= 12;
	FILE * stream= fopen("DistanceMatrix.csv", "r");
	distance_matrix_LSH(
	stream,
	L,
	k);*/
	/*dm_search(&seed_0, b, dt, &results, &current_results_no, 10, 3);
	for(i2= 0; i2 < current_results_no; i2++){
		printf("%s\n", results[i2]->name);
	}*/
	/*for(i2= 0; i2 < size; i2++){
		for(j2= 0; j2 < dimensions; j2++){
			printf("%d	", dt[i2].array[j2]);
			//fflush(stdout);
		}
		printf("\n");
	}*/
	/*for(i2=0; i2<hash_table_size; i2++){
		if(NULL != bucket_get_currnode_data(b[i2])){
			element * e= bucket_get_currnode_data(b[i2]);
			printf("%d: %s	", i2,  e->name);
			while(bucket_next(b[i2]) == 0){
				element * e= bucket_get_currnode_data(b[i2]);
				printf("%s	",  e->name);
			}
			printf("\n");
			//vector_print(e->vector0);
		}
	}*/
	//return (EXIT_SUCCESS);


	//int i;
	/*vector* vector0= vector_construct_random(4);
	vector * vector1= vector_copy(vector0);
	vector_scalar_multiplication(vector0, 2);
	vector_print(vector0);
	vector_print(vector1);
	double aa;
	vector_inner_product(vector0, vector1, &aa);
	printf("dot product= %f \n\n", aa);
	int array[7]= {1,2,3,4,5,6,7};
	int * arr= array;
	bucket * bucket0= bucket_construct();
	for(i= 0; i < 7; i++){
		bucket_add_data(bucket0, arr);
		arr++;
	}
	array[5]=56;
	for(i= 0; i < 7; i++){
		printf("%d ", *((int*) bucket_get_currnode_data(bucket0)) );
		printf("%d \n", bucket_next(bucket0) );
	}
	bucket_reset_iterator(bucket0);
	printf("%d ", *((int*) bucket_get_currnode_data(bucket0)) );
	bucket_destruct(bucket0);*/
	/*FILE * stream= fopen("DataEuclidean.csv", "r");
	char line[LINE_SIZE];
	fgets(line, LINE_SIZE, stream);
	fgets(line, LINE_SIZE, stream);
	//int size;
	element * data_table= NULL;
	int size= euc_parser(stream, &data_table);
	fclose(stream);
	int L= 5,
		item_index= 6;
	double radius= 1500;
	int  hash_table_size[L];
	seed * seed_table[L];
	//seed ** seedptr= &seed_table;
	bucket ** hash_table[L];
	for(i= 0; i < L; i++){
		hash_table[i]= euc_hash_table_constructor(data_table, size, &(hash_table_size[i]), &(seed_table[i]) );
	}
	element ** results= NULL;
	int current_results_no= 0;
	stream= fopen("out2.txt", "w");
	euc_L_search(
		L, 
		stream,
		seed_table,
		hash_table,
		data_table,
		radius,
		item_index);
	//euc_search(data_table[999].vector0, b, &results, &current_results_no, seed_0, 1000); //return (EXIT_SUCCESS);
	for(i= 0; i < current_results_no; i++){
		printf("%s\n", results[i]->name);
	}
	fclose(stream);*/
	/*for(i=0; i<hash_size; i++){
		if(NULL != bucket_get_currnode_data(b[i])){
			element * e= ((augmented_data*)bucket_get_currnode_data(b[i]))->data;
			printf("%d: %s	", i,  e->name);
			while(bucket_next(b[i]) == 0){
				element * e= ((augmented_data*)bucket_get_currnode_data(b[i]))->data;
				printf("%s	",  e->name);
			}
			printf("\n");
			//vector_print(e->vector0);
		}
	}*/
	//vector * v= e->vector0;
	//vector_print(v);
	//for(i= 0; i<10; i++){
	//	printf("%f\n", normal_distr());
	//}
    return (EXIT_SUCCESS);
}

