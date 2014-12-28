#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "k-medoids.h"
#include "sys/time.h"
#include "assign_to_clusters.h"
#include "initialize_medoids.h"
#include "update_medoids.h"
#include "silhouette.h"
#include "cluster.h"

int stoppingCondition(
	double ** distance_matrix, 
	int *medoids, 
	int *newMedoids, 
	int k);

int kmedoids( FILE * fpInput, metric_space current_space, int k, int numOfHashFunctions,
			int L, int claransSetFraction, int claransIterations, FILE *fpOutput, int choice_1, int choice_2, int choice_3 ,int complete){
	
	int i, j;
	int * medoids, *newMedoids, *oldMedoids, dt_size, * assignment;
	struct timeval start, end;
	void * seeds_and_htables= NULL;
	cluster* clusters;
	element ** data_table= NULL;
	double ** distance_matrix_2;
	gettimeofday(&start, NULL);
	data_table= generic_parser(fpInput, &dt_size, current_space);
	distance_matrix_2= general_generate_distance_matrix((void*)data_table, dt_size, current_space);
	newMedoids = initialize(distance_matrix_2, dt_size, k, choice_1);
	int counter= 0;
	do{	
		//printf("COUNTER = %d\n", counter);
		counter++;
		assignment= assign_to_clusters(&seeds_and_htables, choice_2, newMedoids, k, data_table, distance_matrix_2, dt_size, numOfHashFunctions, L, current_space);	
		oldMedoids = newMedoids;
		newMedoids = update_medoids(choice_3, assignment, distance_matrix_2, data_table, dt_size, oldMedoids, k, claransSetFraction, claransIterations);
		//seeds_and_htables= NULL;
	}while(stoppingCondition(distance_matrix_2, oldMedoids, newMedoids, k)==0 && (counter != 5));

	gettimeofday(&end, NULL);

	//printf("SIZE %d\n",clusters[0].size );

	fprintf(fpOutput, "Algorithm: Ι%dA%dU%d\n", choice_1, choice_2, choice_3);
	/*double sil= silhouette(
		distance_matrix_2,
		assignment,
		dt_size,
		newMedoids,
		k);
	printf("%lf\n", sil);*/
	clusters= assignmentToCluster(
		assignment, 
		distance_matrix_2,
		dt_size, 
		newMedoids,
		k);
        for(i=0; i<k; i++){
		fprintf(fpOutput, "CLUSTER-%d {size: %d, medoid: item%d}\n", i+1, clusters[i].size, ((clusters[i].medoidIndex )+ 1) );
	}
	fprintf(fpOutput, "clustering_time: %f seconds\n", ((end.tv_sec * 1000000 + end.tv_usec)- (start.tv_sec * 1000000 + start.tv_usec))/1000000.00);
	if(complete == 1){
		for(i=0; i<k; i++){
			fprintf(fpOutput, "\nCLUSTER-%d {", i+1);
			for(j=0; j<clusters[i].size; j++){
				fprintf(fpOutput, "item%d, ", clusters[i].elementsIndexes[j]);
			}
			fprintf(fpOutput, "}\n");
		}
	}
}

int stoppingCondition(
	double ** distance_matrix, 
	int *medoids, 
	int *newMedoids, 
	int k)
{
	int stop = 0, i;
	for(i=0; i<k; i++){
		if( distance_matrix[medoids[i]][newMedoids[i]] < 3 ){
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