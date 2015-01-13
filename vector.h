/* 
 * File:   vector.h
 * Author: Infiknight
 *
 * Created on October 12, 2014, 10:35 PM
 */

#ifndef VECTOR_H
#define	VECTOR_H

#ifdef	__cplusplus
extern "C" {
#endif

/**
 * A vector consisting of its number of dimensions along with
 * a pointer to an array holding its coordinates.
 */
typedef struct Vector vector;

/**
 * Create a vector in 0 dimensional space.
 * @return A pointer to the newly created vector.
 */
vector * vector_construct();

/**
 * Create a vector and initialize with random values following the standard
 * normal distribution.
 * @param noDimensions Number of dimensions of the vector to be created.
 * @return A pointer to the newly created vector.
 */
vector* vector_construct_random(
	int noDimensions);

/**
 * Extend? a vector to a new dimension.
 * @param vector0 The vector in question.
 * @param dimvalue The value the vector is going to have in the new dimension.
 * @return 1 if an error occurred, 0 otherwise.
 */
int vector_add_dimension(
	vector * const vector0,
	double dimvalue);

/**
 * Make a copy of a vector.
 * @param original Vector to be copied.
 * @return The copy of the given vector.
 */
vector * vector_copy(
	vector const * const original);

/**
 * Multiply a vector by a scalar.
 * @param vector0 The vector to be multiplied. It also acts as the result of this operation.
 * @param scalar The value by which the vector is multiplied.
 */
void vector_scalar_multiplication(
	vector const * const vector0,
	double const scalar);

/**
 * Calculates the dot/scalar product of two vectors of equal dimensionality.
 * @param vector1 The first operand.
 * @param vector2 The second operand.
 * @param result The result of the operation, which is a scalar.
 * @return 1 if the vectors' dimensionalities differ, otherwise 0.
 */
int vector_inner_product(
	vector const * const vector1, 
	vector const * const vector2,
	double * const result);

/**
 * Calculates the euclidean distance of two vectors.
 * @param vector1 The first vector.
 * @param vector2 The second vector.
 * @return The eculidean distance as a double.
 */
double vector_euclidean_distance(
	vector const * const vector1,
	vector const * const vector2);

double vector_cosine_distance(
	vector const * const vector1,
	vector const * const vector2);

/**
 * Returns a vector's number of dimensions
 * @param vector_0	The vector whose dimensionality we want to know.
 * @return The dimensionality of the vector.
 */
int vector_dimensions(
	vector const * const vector_0);

/**
 * Print the components of a vector.
 * @param vector0 The vector in question.
 */
void vector_print(
	vector const * const vector0);

/**
 * Destroy a vector and release its memory.
 * @param vector0 Vector to be destroyed.
 */
void vector_destruct(
	vector * const vector0);

#ifdef	__cplusplus
}
#endif

#endif	/* VECTOR_H */

