#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "k-medoids.h"


int kmedoids(struct hamming_element * datasetArr, int size, int k, int numOfHashFunctions, int L, int claransSetFraction, int claransIterations){

	int * medoids, *newMedoids, *oldMedoids;
	cluster * clusters;

	oldMedoids = malloc(sizeof(int) * k);
	newMedoids = malloc(sizeof(int) * k);

	medoids = hammingSpreadout(datasetArr,size , k);

	clusters = hammingPAM(datasetArr, medoids, size, k);

	newMedoids = hammingUpdateAlaLloyd(clusters, datasetArr, size, k);
	oldMedoids = medoids;

	while(stoppingCondition(datasetArr, oldMedoids, newMedoids, k)==0){

		clusters = hammingPAM(datasetArr, newMedoids, size, k);

		oldMedoids = newMedoids;
		newMedoids = hammingUpdateAlaLloyd(clusters, datasetArr, size, k);
	}



}


int stoppingCondition(struct hamming_element * datasetArr, int *medoids, int *newMedoids, int k){

	int stop = 0, i;

	for(i=0; i<k; i++){
		if(hammingDistance(datasetArr[medoids[i]].str, datasetArr[newMedoids[i]].str) < 3 ){
			stop++;
		}
	}

	if(stop==k){
		return 1;//STOP!!!
	}
	else{
		return 0;//CONTINUE!!!
	}

}