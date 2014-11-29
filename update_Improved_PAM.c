#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <errno.h>
#include "update_Improved_PAM.h"

hammingUpdateAlaLloyd(cluster * clusters, struct hamming_element * datasetArr, int size, int k){

	int i, j;
	int * newMedoids;
	int	*newMedoidsCosts;
	newMedoids = malloc(sizeof(int)*k);

	for(i=0; i<k; i++){
		newMedoids[i] = clusters[i].elementsIndexes[0];
		newMedoidsCosts[i] = hammingComputeNewClusterCost(datasetArr, clusters[i].elementsIndexes[0], clusters[i]);
		for(j=1; j<clusters[i].size; j++){
			if(newMedoidsCosts[i] > hammingComputeNewClusterCost(datasetArr, clusters[i].elementsIndexes[j], clusters[i])){
				newMedoids[i] = clusters[i].elementsIndexes[j];
				newMedoidsCosts[i] = hammingComputeNewClusterCost(datasetArr, clusters[i].elementsIndexes[j], clusters[i]);
			}
			else{
				//printf("%d IS NOT THE NEW MEDOID BECAUSE %d > %d size = %d\n", clusters[i].elementsIndexes[j], hammingComputeNewClusterCost(datasetArr, clusters[i].elementsIndexes[j], clusters[i], size, k), newMedoidsCosts[i], clusters[i].size );
			}
		}
	}

	/*printf("TOTAL DISTANCE1 = %d\n", hammingComputeNewClusterCost(datasetArr, clusters[0].elementsIndexes[0], clusters[0]));
	printf("TOTAL DISTANCE2 = %d\n", hammingComputeNewClusterCost(datasetArr, clusters[0].elementsIndexes[1], clusters[0]));
	printf("TOTAL DISTANCE3 = %d\n", hammingComputeNewClusterCost(datasetArr, clusters[0].elementsIndexes[2], clusters[0]));
	printf("TOTAL DISTANCE4 = %d\n", hammingComputeNewClusterCost(datasetArr, clusters[0].elementsIndexes[3], clusters[0]));
	printf("TOTAL DISTANCE5 = %d\n", hammingComputeNewClusterCost(datasetArr, clusters[0].elementsIndexes[4], clusters[0]));
	*/

	//printf("NEW MEDOIDS = ");
	for (i = 0; i < k; i++)
	{
		printf("%d cost = %d\n", newMedoids[i], newMedoidsCosts[i]);
	}
	printf("\n");

}

int hammingComputeNewClusterCost(struct hamming_element * datasetArr, int elemIndex, cluster cluster0){
	int totalDistance = 0, i;

	for(i=0; i<cluster0.size; i++){
		if(elemIndex!=cluster0.elementsIndexes[i]){
			//printf("dist = %d\n",hammingDistance(datasetArr[cluster0.elementsIndexes[i]], datasetArr[elemIndex]) );
			//printf("ELEMENTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTINDEXXXXXXXXXXXXXXXXXX = %d\n",cluster0.elementsIndexes[i] );
			totalDistance += hammingDistance(datasetArr[cluster0.elementsIndexes[i]], datasetArr[elemIndex]);
		}
	}

	//printf("ELEM = %d SIZE = %d, DISTANCE = %d\n",elemIndex, cluster0.size, totalDistance);

	return totalDistance;
}
