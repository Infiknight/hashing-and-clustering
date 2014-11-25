/* 
 * File:   LSH_structs.h
 * Author: Infiknight
 *
 * Created on November 25, 2014, 2:19 PM
 */

#ifndef LSH_STRUCTS_H
#define	LSH_STRUCTS_H

#ifdef	__cplusplus
extern "C" {
#endif

typedef struct Element element;
typedef struct Seed seed;

typedef enum Metric_space{
	hamming,
	euclidean,
	distance_matrix
} metric_space;

int get_element_pos(
	element * element_ptr,
	metric_space current_space);

char * get_element_name(
	element * element_ptr,
	metric_space current_space);

#ifdef	__cplusplus
}
#endif

#endif	/* LSH_STRUCTS_H */

