#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "k-medoids.h"
#include "sys/time.h"
#include "assign_to_clusters.h"
#include "initialize_medoids.h"
#include "update_medoids.h"

int stoppingCondition(
	double ** distance_matrix, 
	int *medoids, 
	int *newMedoids, 
	int k);

int kmedoids( FILE * fpInput, metric_space current_space, int k, int numOfHashFunctions,
			int L, int claransSetFraction, int claransIterations, FILE *fpOutput, int complete){
	int choice_1=2 ,
		choice_2=2 ,
		choice_3=2 ;
	int i, j;
	int * medoids, *newMedoids, *oldMedoids, dt_size, * assignment;
	struct timeval start, end;
	element ** data_table= NULL;
	double ** distance_matrix_2;

	oldMedoids = malloc(sizeof(int) * k);
	newMedoids = malloc(sizeof(int) * k);


	gettimeofday(&start, NULL);
	data_table= generic_parser(fpInput, &dt_size, current_space);
	distance_matrix_2= general_generate_distance_matrix((void*)data_table, dt_size, current_space);
	newMedoids = initialize(distance_matrix_2, dt_size, k, choice_1);
	do{	
		assignment= assign_to_clusters(choice_2, newMedoids, k, data_table, distance_matrix_2, dt_size, numOfHashFunctions, L, current_space);	
		oldMedoids = newMedoids;
		newMedoids = update_medoids(choice_3, assignment, distance_matrix_2, data_table, dt_size, oldMedoids, k, claransSetFraction, claransIterations);
	}while(stoppingCondition(distance_matrix_2, oldMedoids, newMedoids, k)==0);

	gettimeofday(&end, NULL);

	//printf("SIZE %d\n",clusters[0].size );

	fprintf(fpOutput, "Algorithm: Ι1A1U1\n");

	//for(i=0; i<k; i++){
	//	fprintf(fpOutput, "CLUSTER-%d {size: %d, medoid: item%d}\n", i+1, clusters[i].size, ((clusters[i].medoidIndex )+ 1) );
	//}
	fprintf(fpOutput, "clustering_time: %f seconds\n", ((end.tv_sec * 1000000 + end.tv_usec)- (start.tv_sec * 1000000 + start.tv_usec))/1000000.00);

	//Silhouette

	/*if(complete == 1){
		for(i=1; i<k; i++){
			fprintf(fpOutput, "\nCLUSTER-%d {", i+1);
			for(j=0; j<clusters[i].size; j++){
				fprintf(fpOutput, "item%d, ", clusters[i].elementsIndexes[j]);
			}
			fprintf(fpOutput, "}\n");
		}
	}*/
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