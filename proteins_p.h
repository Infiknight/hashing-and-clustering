/* 
 * File:   proteins_p.h
 * Author: Infiknight
 *
 * Created on January 5, 2015, 2:34 PM
 */

#ifndef PROTEINS_P_H
#define	PROTEINS_P_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "proteins.h"
#include "distance_matrix_p.h"
	
double protein_distance_c(
	gsl_matrix * X,
	gsl_matrix * Y);

int translate_to_origin(
	gsl_matrix * protein);

gsl_matrix ** protein_parser(
	FILE * stream,
	int * numConform);


#ifdef	__cplusplus
}
#endif

#endif	/* PROTEINS_P_H */

