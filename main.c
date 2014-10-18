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

/*
 * 
 */
int main(int argc, char** argv) {
	srand(time(NULL));
	int i;
	vector* vector0= init_rand_vector(4);
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
	bucket_destruct(bucket0);
	//for(i= 0; i<10; i++){
	//	printf("%f\n", normal_distr());
	//}
    return (EXIT_SUCCESS);
}

