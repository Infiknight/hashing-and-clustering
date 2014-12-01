#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "k-medoids.h"


int kmedoids(struct hamming_element * datasetArr, int size, int k, int numOfHashFunctions,
			int L, int claransSetFraction, int claransIterations, FILE *fpOutput, int complete){

	int i, j;
	int * medoids, *newMedoids, *oldMedoids;
	cluster * clusters;
	struct timeval start, end;

	oldMedoids = malloc(sizeof(int) * k);
	newMedoids = malloc(sizeof(int) * k);


	gettimeofday(&start, NULL);

	medoids = hammingSpreadout(datasetArr,size , k);

	clusters = hammingPAM(datasetArr, medoids, size, k);

	newMedoids = hammingUpdateAlaLloyd(clusters, datasetArr, size, k);
	oldMedoids = medoids;

	while(stoppingCondition(datasetArr, oldMedoids, newMedoids, k)==0){
		
		clusters = hammingPAM(datasetArr, newMedoids, size, k);
		
		oldMedoids = newMedoids;
		newMedoids = hammingUpdateAlaLloyd(clusters, datasetArr, size, k);

	}

	gettimeofday(&end, NULL);

	printf("SIZE %d\n",clusters[0].size );

	fprintf(fpOutput, "Algorithm: Ι1A1U1\n");

	for(i=0; i<k; i++){
		fprintf(fpOutput, "CLUSTER-%d {size: %d, medoid: item%d}\n", i+1, clusters[i].size, ((clusters[i].medoidIndex )+ 1) );
	}
	fprintf(fpOutput, "clustering_time: %f seconds\n", ((end.tv_sec * 1000000 + end.tv_usec)- (start.tv_sec * 1000000 + start.tv_usec))/1000000.00);

	//Silhouette

	if(complete == 1){
		for(i=1; i<k; i++){
			fprintf(fpOutput, "\nCLUSTER-%d {", i+1);
			for(j=0; j<clusters[i].size; j++){
				fprintf(fpOutput, "item%d, ", clusters[i].elementsIndexes[j]);
			}
			fprintf(fpOutput, "}\n");
		}
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