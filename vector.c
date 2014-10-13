#include "vector.h"
#include "probability_distr.h"
#include <stdio.h>
#include <stdlib.h>

struct vector * init_rand_vector(
	int noDimensions)
{
	struct vector * new= malloc(sizeof(struct vector));
	new->dimensionality= noDimensions;
	new->coordinates= malloc(noDimensions*sizeof(double));
	int i;
	for(i= 0; i < noDimensions; i++){
		new->coordinates[i]= normal_distr();
	}
	return new;
}

struct vector * vector_copy(
	struct vector const * const original)
{
	struct vector * new= malloc(sizeof(struct vector));
	new->dimensionality= original->dimensionality;
	new->coordinates= malloc(new->dimensionality*sizeof(double));
	int i;
	for(i= 0; i < original->dimensionality; i++){
		new->coordinates[i]= original->coordinates[i];
	}
	return new;
}

void vector_scalar_multiplication(
	struct vector const * const vector0,
	double const scalar)
{
	int i;
	for(i= 0; i < vector0->dimensionality; i++){
		vector0->coordinates[i]*= scalar;
	}
}

int vector_inner_product(
	struct vector const * const vector1, 
	struct vector const * const vector2,
	double * const result)
{
	if(vector1->dimensionality != vector2->dimensionality)
		return 1;
	int i;
	double sum= 0;
	for(i= 0; i < vector1->dimensionality; i++){
		sum+= vector1->coordinates[i]*vector2->coordinates[i];
	}
	*result= sum;
	return 0;
}

void vector_print(
	struct vector const * const vector0)
{
	int i;
	for(i= 0; i < vector0->dimensionality; i++){
		printf("component %d= %f\n", i, vector0->coordinates[i]);
	}
}