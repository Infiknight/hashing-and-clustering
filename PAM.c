#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <errno.h>
#include "cluster.h"

cluster * PAM(
	double ** distance_matrix, 
	int * medoids, 
	int size, 
	int k)
{
	int i, nearestMedoidIndex, j;
	double nearestMedoidDist;

	cluster *clusters;
	clusters = malloc(sizeof(cluster) *k);

	printf("SIZE = %d\n",size );

	for(i=0; i<k; i++){
		//printf("%d\n", medoids[i]);
	}

	for(i=0; i<k; i++){
		clusters[i].medoidIndex = medoids[i];

	}

	for(i=0; i<k; i++){
		clusters[i].elementsIndexes = NULL;
	}

	for(i=0; i<k; i++){
		clusters[i].size = 0;
	}

	for(i=0; i<k; i++){
		clusters[i].cost = 0.0;
	}

	for(i=0; i<k; i++){
		//printf("%d\n", clusters[i].medoidIndex);
	}

	//printf("HELLO\n");

	for(i=0; i<size; i++){

		//printf("HELLO2\n");


		nearestMedoidIndex = 0; //to index tou kontinoterou medoid sto pinaka medoids
		//printf("HELLO3\n");
		nearestMedoidDist = distance_matrix[clusters[nearestMedoidIndex].medoidIndex][i];
		//printf("HELLO4\n");
		for(j=1; j<k; j++){
			if( distance_matrix[clusters[j].medoidIndex][i] < nearestMedoidDist ){
				nearestMedoidIndex = j;
				nearestMedoidDist = distance_matrix[clusters[nearestMedoidIndex].medoidIndex][i];
			}
		}

		//printf("%d\n",i );
		clusters[nearestMedoidIndex].elementsIndexes = realloc(clusters[nearestMedoidIndex].elementsIndexes, (size +1) * sizeof(int));
		clusters[nearestMedoidIndex].elementsIndexes[clusters[nearestMedoidIndex].size] = i;
		//printf("nearestMedoidIndex = %d size = \n",nearestMedoidIndex, size );
		//printf("%d\n",clusters[nearestMedoidIndex].elementsIndexes[size] );
		clusters[nearestMedoidIndex].cost += distance_matrix[clusters[nearestMedoidIndex].medoidIndex][i];
		clusters[nearestMedoidIndex].size++;

	}

	//printf("kkkkkkkkkkkkkkkkkkkkkkkkkkkk = %d\n",k );
	printf("%d \n", clusters[0].elementsIndexes[0]);

	for(i=0; i<k; i++){
		printf("Cluster %d with Cost = %lf ", clusters[i].medoidIndex, clusters[i].cost);
		printf("has elements with indexes:\n");
		for(j=0; j<clusters[i].size; j++){
			
			printf("%d ", clusters[i].elementsIndexes[j]);
			printf("\n");
		}
	}


	return clusters;


}