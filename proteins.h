/* 
 * File:   proteins.h
 * Author: Infiknight
 *
 * Created on January 5, 2015, 2:35 PM
 */

#ifndef PROTEINS_H
#define	PROTEINS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "LSH_structs.h"
	
element ** protein_parser_c(
	FILE * stream,
	int * dt_size);

element ** protein_parser_d(
	FILE * stream,
	int * dt_size,
	int no_pairs);


#ifdef	__cplusplus
}
#endif

#endif	/* PROTEINS_H */

