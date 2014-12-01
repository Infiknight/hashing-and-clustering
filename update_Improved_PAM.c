#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <errno.h>

double ComputeNewClusterCost(
	double ** distance_matrix,
	int elemIndex,
	cluster cluster0)
{
    double totalDistance = 0;
    int i;
 
    for(i=0; i<cluster0.size; i++){
        //printf("ELEMS: %d\n", cluster0.elementsIndexes[i]);
    }
 
    for(i=0; i<cluster0.size; i++){
        //if(elemIndex!=cluster0.elementsIndexes[i]){
            //printf("%d and %d has dist = %d\n",elemIndex, cluster0.elementsIndexes[i], hammingDistance(datasetArr[cluster0.elementsIndexes[i]].str, datasetArr[elemIndex].str) );
            //printf("%s and %s has dist = %d\n",elemIndex, cluster0.elementsIndexes[i], hammingDistance(datasetArr[cluster0.elementsIndexes[i]], datasetArr[elemIndex]) );
 
            //printf("ELEMENTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTINDEXXXXXXXXXXXXXXXXXX = %d\n",cluster0.elementsIndexes[i] );
            totalDistance += distance_matrix[cluster0.elementsIndexes[i]][elemIndex];
        //}
    }
 
    //printf("ELEM = %d SIZE = %d, DISTANCE = %d\n",elemIndex, cluster0.size, totalDistance);
 
    return totalDistance;
}

int * UpdateAlaLloyd(
	cluster * clusters,
	double ** distance_matrix,
	int k)
{
    int i, j;
    int * newMedoids;
    double  *newMedoidsCosts;
    newMedoids = malloc(sizeof(double)*k);
    for(i=0; i<k; i++){
        newMedoids[i] = clusters[i].elementsIndexes[5];
        newMedoidsCosts[i] = ComputeNewClusterCost(distance_matrix, clusters[i].elementsIndexes[0], clusters[i]);
        for(j=6; j<clusters[i].size; j++){
            if(newMedoidsCosts[i] > ComputeNewClusterCost(distance_matrix, clusters[i].elementsIndexes[j], clusters[i])){
                //printf("%d IS THE NEW MEDOID BECAUSE %d < %d size = %d\n", clusters[i].elementsIndexes[j], hammingComputeNewClusterCost(datasetArr, clusters[i].elementsIndexes[j], clusters[i], size, k), newMedoidsCosts[i], clusters[i].size );
                newMedoids[i] = clusters[i].elementsIndexes[j];
                newMedoidsCosts[i] = ComputeNewClusterCost(distance_matrix, clusters[i].elementsIndexes[j], clusters[i]);
            }
            else{
                //printf("%d IS NOT THE NEW MEDOID BECAUSE %d > %d size = %d\n", clusters[i].elementsIndexes[j], hammingComputeNewClusterCost(datasetArr, clusters[i].elementsIndexes[j], clusters[i], size, k), newMedoidsCosts[i], clusters[i].size );
            }
        }
    }
    printf("NEW MEDOIDS = ");
    for (i = 0; i < k; i++)
    {
        printf("%d cost = %f\n", newMedoids[i], newMedoidsCosts[i]);
    }
    printf("\n");
    return newMedoids;
}

