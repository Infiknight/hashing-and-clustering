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

/*
 * 
 */
int main(int argc, char** argv) {
	srand(time(NULL));
	int i;
	struct vector* vector0= init_rand_vector(4);
	struct vector * vector1= vector_copy(vector0);
	vector_scalar_multiplication(vector0, 2);
	vector_print(vector0);
	vector_print(vector1);
	double aa;
	vector_inner_product(vector0, vector1, &aa);
	printf("dot product= %f \n", aa);
	//for(i= 0; i<10; i++){
	//	printf("%f\n", normal_distr());
	//}
    return (EXIT_SUCCESS);
}

