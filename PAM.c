#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <errno.h>
#include "PAM.h"

cluster * hammingPAM(struct hamming_element * datasetArr, int * medoids, int size, int k){
	int i, nearestMedoidIndex, nearestMedoidDist, j;

	cluster *clusters;
	clusters = malloc(sizeof(cluster) *k);


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

	for(i=0; i<size; i++){


		nearestMedoidIndex = 0; //to index tou kontinoterou medoid sto pinaka medoids
		nearestMedoidDist = hammingDistance(datasetArr[clusters[nearestMedoidIndex].medoidIndex].str, datasetArr[i].str);
		for(j=1; j<k; j++){
			if( hammingDistance(datasetArr[clusters[j].medoidIndex].str, datasetArr[i].str) < nearestMedoidDist ){
				nearestMedoidIndex = j;
				nearestMedoidDist = hammingDistance(datasetArr[clusters[nearestMedoidIndex].medoidIndex].str, datasetArr[i].str);
			}
		}

		//printf("%d\n",i );
		clusters[nearestMedoidIndex].elementsIndexes = realloc(clusters[nearestMedoidIndex].elementsIndexes, (size +1) * sizeof(int));
		clusters[nearestMedoidIndex].elementsIndexes[clusters[nearestMedoidIndex].size] = i;
		//printf("nearestMedoidIndex = %d size = \n",nearestMedoidIndex, size );
		//printf("%d\n",clusters[nearestMedoidIndex].elementsIndexes[size] );
		clusters[nearestMedoidIndex].cost += (double)hammingDistance(datasetArr[clusters[nearestMedoidIndex].medoidIndex].str, datasetArr[i].str);
		clusters[nearestMedoidIndex].size++;

	}

	printf("kkkkkkkkkkkkkkkkkkkkkkkkkkkk = %d\n",k );
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


cluster * euclideanPAM(element ** datasetArr, int * medoids, int size, int k){
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

	printf("HELLO\n");

	for(i=0; i<size; i++){

		printf("HELLO2\n");


		nearestMedoidIndex = 0; //to index tou kontinoterou medoid sto pinaka medoids
		printf("HELLO3\n");
		nearestMedoidDist = vector_euclidean_distance(datasetArr[clusters[nearestMedoidIndex].medoidIndex]->vector0, datasetArr[i]->vector0);
		printf("HELLO4\n");
		for(j=1; j<k; j++){
			if( vector_euclidean_distance(datasetArr[clusters[j].medoidIndex]->vector0, datasetArr[i]->vector0) < nearestMedoidDist ){
				nearestMedoidIndex = j;
				nearestMedoidDist = vector_euclidean_distance(datasetArr[clusters[nearestMedoidIndex].medoidIndex]->vector0, datasetArr[i]->vector0);
			}
		}

		printf("%d\n",i );
		clusters[nearestMedoidIndex].elementsIndexes = realloc(clusters[nearestMedoidIndex].elementsIndexes, (size +1) * sizeof(int));
		clusters[nearestMedoidIndex].elementsIndexes[clusters[nearestMedoidIndex].size] = i;
		//printf("nearestMedoidIndex = %d size = \n",nearestMedoidIndex, size );
		//printf("%d\n",clusters[nearestMedoidIndex].elementsIndexes[size] );
		clusters[nearestMedoidIndex].cost += vector_euclidean_distance(datasetArr[clusters[nearestMedoidIndex].medoidIndex]->vector0, datasetArr[i]->vector0);
		clusters[nearestMedoidIndex].size++;

	}

	printf("kkkkkkkkkkkkkkkkkkkkkkkkkkkk = %d\n",k );
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