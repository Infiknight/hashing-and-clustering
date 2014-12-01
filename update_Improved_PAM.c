#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <errno.h>
#include "update_Improved_PAM.h"

int * hammingUpdateAlaLloyd(cluster * clusters, struct hamming_element * datasetArr, int size, int k){

	int i, j;
	int * newMedoids;
	int	*newMedoidsCosts;
	newMedoids = malloc(sizeof(int)*k);

	for(i=0; i<k; i++){
		newMedoids[i] = clusters[i].elementsIndexes[0];
		newMedoidsCosts[i] = hammingComputeNewClusterCost(datasetArr, clusters[i].elementsIndexes[0], clusters[i]);
		for(j=1; j<clusters[i].size; j++){
			if(newMedoidsCosts[i] > hammingComputeNewClusterCost(datasetArr, clusters[i].elementsIndexes[j], clusters[i])){
				//printf("%d IS THE NEW MEDOID BECAUSE %d < %d size = %d\n", clusters[i].elementsIndexes[j], hammingComputeNewClusterCost(datasetArr, clusters[i].elementsIndexes[j], clusters[i], size, k), newMedoidsCosts[i], clusters[i].size );
				newMedoids[i] = clusters[i].elementsIndexes[j];
				newMedoidsCosts[i] = hammingComputeNewClusterCost(datasetArr, clusters[i].elementsIndexes[j], clusters[i]);
			}
			else{
				//printf("%d IS NOT THE NEW MEDOID BECAUSE %d > %d size = %d\n", clusters[i].elementsIndexes[j], hammingComputeNewClusterCost(datasetArr, clusters[i].elementsIndexes[j], clusters[i], size, k), newMedoidsCosts[i], clusters[i].size );
			}
		}
	}

	

	printf("NEW MEDOIDS = ");
	for (i = 0; i < k; i++)
	{
		printf("%d cost = %d\n", newMedoids[i], newMedoidsCosts[i]);
	}
	printf("\n");

	return newMedoids;

}

int hammingComputeNewClusterCost(struct hamming_element * datasetArr, int elemIndex, cluster cluster0){
	int totalDistance = 0, i;

	for(i=0; i<cluster0.size; i++){
		//printf("ELEMS: %d\n", cluster0.elementsIndexes[i]);
	}

	for(i=0; i<cluster0.size; i++){
		//if(elemIndex!=cluster0.elementsIndexes[i]){
			//printf("%d and %d has dist = %d\n",elemIndex, cluster0.elementsIndexes[i], hammingDistance(datasetArr[cluster0.elementsIndexes[i]].str, datasetArr[elemIndex].str) );
			//printf("%s and %s has dist = %d\n",elemIndex, cluster0.elementsIndexes[i], hammingDistance(datasetArr[cluster0.elementsIndexes[i]], datasetArr[elemIndex]) );

			//printf("ELEMENTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTINDEXXXXXXXXXXXXXXXXXX = %d\n",cluster0.elementsIndexes[i] );
			totalDistance += hammingDistance(datasetArr[cluster0.elementsIndexes[i]].str, datasetArr[elemIndex].str);
		//}
	}

	//printf("ELEM = %d SIZE = %d, DISTANCE = %d\n",elemIndex, cluster0.size, totalDistance);

	return totalDistance;
}
