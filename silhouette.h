/* 
 * File:   silhouette.h
 * Author: Infiknight
 *
 * Created on December 2, 2014, 8:12 PM
 */

#ifndef SILHOUETTE_H
#define	SILHOUETTE_H

#ifdef	__cplusplus
extern "C" {
#endif

double silhouette(
	double ** distance_matrix,
	int * assignment,
	int dt_size,
	int * medoids,
	int medoids_size);


#ifdef	__cplusplus
}
#endif

#endif	/* SILHOUETTE_H */

