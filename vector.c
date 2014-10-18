#include "vector.h"
#include "probability_distr.h"
#include <stdio.h>
#include <stdlib.h>

struct Vector{
	int dimensionality;		///< number of dimensions of the vector
	double *coordinates;	///< points to an array holding the vector's components
};

vector * init_vector()
{
	vector * new= malloc(sizeof(vector));
	new->dimensionality= 0;
	new->coordinates= NULL;
	return new;
}

vector * init_rand_vector(
	int noDimensions)
{
	vector * new= malloc(sizeof(vector));
	new->dimensionality= noDimensions;
	new->coordinates= malloc(noDimensions*sizeof(double));
	int i;
	for(i= 0; i < noDimensions; i++){
		new->coordinates[i]= normal_distr();
	}
	return new;
}

int vector_add_dimension(
	vector * const vector0,
	double dimvalue)
{
	vector0->dimensionality+= 1;
	vector0->coordinates= realloc( vector0->coordinates, vector0->dimensionality*sizeof(double) );
	if(vector0->coordinates == NULL)
		return 1;
	vector0->coordinates[vector0->dimensionality - 1]= dimvalue;
	return 0;
}

vector * vector_copy(
	vector const * const original)
{
	vector * new= malloc(sizeof(vector));
	new->dimensionality= original->dimensionality;
	new->coordinates= malloc(new->dimensionality*sizeof(double));
	int i;
	for(i= 0; i < original->dimensionality; i++){
		new->coordinates[i]= original->coordinates[i];
	}
	return new;
}

void vector_scalar_multiplication(
	vector const * const vector0,
	double const scalar)
{
	int i;
	for(i= 0; i < vector0->dimensionality; i++){
		vector0->coordinates[i]*= scalar;
	}
}

int vector_inner_product(
	vector const * const vector1, 
	vector const * const vector2,
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
	vector const * const vector0)
{
	int i;
	for(i= 0; i < vector0->dimensionality; i++){
		printf("component %d= %f\n", i, vector0->coordinates[i]);
	}
}

void vector_destruct(
	vector * const vector0)
{
	free(vector0->coordinates);
	free(vector0);
}