/* 
 * File:   cluster.h
 * Author: Infiknight
 *
 * Created on December 1, 2014, 8:19 PM
 */

#ifndef CLUSTER_H
#define	CLUSTER_H

#ifdef	__cplusplus
extern "C" {
#endif

struct Cluster{
	int medoidIndex;
	int * elementsIndexes;
	int size;
	double cost;
};
typedef struct Cluster cluster;

cluster * assignmentToCluster(
	int * assignment, 
	double ** distance_matrix,
	int dt_size, 
	int * medoids,
	int k);

typedef struct Cluster cluster;

#ifdef	__cplusplus
}
#endif

#endif	/* CLUSTER_H */

