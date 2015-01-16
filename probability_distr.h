/* 
 * File:   probability_distr.h
 * Author: Infiknight
 *
 * Created on October 11, 2014, 4:36 PM
 */

#ifndef PROBABILITY_DISTR_H
#define	PROBABILITY_DISTR_H

#ifdef	__cplusplus
extern "C" {
#endif

/** 
 * Returns a double following the Normal Distribution 
 * with 0 mean and 1.0 variance.
 * Srand must have been called at least once 
 * during the current execution.
 * @return The double precision float in question.
 */
double normal_distr();

/**
 * Uniform distribution from min to max (inclusive).
 * @param min Minimum value.
 * @param max Maximum value.
 * @return Integer following the uniform distribution.
 */
int uniform_distr(
	int min,
	int max);

int * random_combination(
	int N,
	int M);

#ifdef	__cplusplus
}
#endif

#endif	/* PLCHLDER_H */

