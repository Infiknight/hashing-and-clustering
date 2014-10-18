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
vector * init_vector();

/**
 * Create a vector and initialize with random values following the standard
 * normal distribution.
 * @param noDimensions Number of dimensions of the vector to be created.
 * @return A pointer to the newly created vector.
 */
vector* init_rand_vector(
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

