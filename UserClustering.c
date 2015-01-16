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
#include "UserClustering.h"

double total_cost2(
	double ** distance_matrix,
	int n, 
	int * medoids,
	int * assignment)
{
	double sum= 0;
	int i;
	for(i= 0; i < n; i++){
		sum+= distance_matrix[i][medoids[assignment[i]]];
	}
	return sum;
}

int stoppingCondition(
	double ** distance_matrix, 
	int *medoids, 
	int *newMedoids, 
	int k);

rating** recom( FILE * fpInput, metric_space current_space, vector_metric vector_metric_0,int k, int numOfHashFunctions,
			int L, int claransSetFraction, int claransIterations, FILE *fpOutput, int choice_1, int choice_2, int choice_3 , 
			double ** ratingsArray, int users, int items){
	
	int i, j;
	int *newMedoids, *oldMedoids, dt_size, * assignment;
	struct timeval start, end;
	void * seeds_and_htables= NULL;
	cluster* clusters;
	element ** data_table= NULL;
	double ** distance_matrix_2;
	gettimeofday(&start, NULL);
	data_table= generic_parser(fpInput, &dt_size, current_space, 1000);
	distance_matrix_2= general_generate_distance_matrix((void*)data_table, dt_size, current_space, vector_metric_0);
	newMedoids = initialize(distance_matrix_2, dt_size, k, choice_1);
	int counter= 0;
	double simSum, z;
	rating **newRatings;


	printf("HELLLLLLLLLLLOOO0000000000000000000000000000000000000000000000000000000000000000000000000\n");

	newRatings = (rating**) malloc(users*sizeof(rating));
	for(i=0; i<users; i++){
		newRatings[i] = (rating *)malloc(items * sizeof(rating));
	}

	for(i=0; i<users; i++){
		for(j=0; j<items; j++){
			newRatings[i][j].rating = 0;
			newRatings[i][j].item = j;
		}
	}

	do{	
		//printf("COUNTER = %d\n", counter);
		counter++;
		assignment= assign_to_clusters(&seeds_and_htables, choice_2, newMedoids, k, data_table, distance_matrix_2, dt_size, numOfHashFunctions, L, current_space, vector_metric_0);
		oldMedoids = newMedoids;
		newMedoids = update_medoids(choice_3, assignment, distance_matrix_2, data_table, dt_size, oldMedoids, k, claransSetFraction, claransIterations);
		printf("cost after assignment %f\n", total_cost2(
			distance_matrix_2,
			dt_size, 
			newMedoids,
			assignment));
		for(i= 0; i < k; i++){
			printf("medoid %d: %d\n", i, newMedoids[i]);
		}
		//seeds_and_htables= NULL;
	}while(stoppingCondition(distance_matrix_2, oldMedoids, newMedoids, k)==0 && (counter != -1));

	gettimeofday(&end, NULL);


	double sil= silhouette(
		distance_matrix_2,
		assignment,
		dt_size,
		newMedoids,
		k);
	printf("%lf\n", sil);
	clusters= assignmentToCluster(
		assignment, 
		distance_matrix_2,
		dt_size, 
		newMedoids,
		k);
    

	for(i=0; i<dt_size; i++){
		simSum=0;

		for(j=0; j<clusters[assignment[i]].size; j++){
			simSum += distance_matrix_2[i][clusters[assignment[i]].elementsIndexes[j]];
		}
		z=1/simSum;

		for(j=0; j<items; j++){
			for(k=0; k<clusters[assignment[i]].size; k++){
				if(i!=clusters[assignment[i]].elementsIndexes[k]){
					newRatings[i][j].rating += simSum * ratingsArray[clusters[assignment[i]].elementsIndexes[k]][j];
				}
			}
			newRatings[i][j].rating = z*newRatings[i][j].rating;
		}
		
	}

	for(i=0; i<100; i++){
		fprintf(fpOutput, "User%d\n", i+1);
		for(j=0; j<items; j++){
				fprintf(fpOutput, "%lf ",newRatings[i][j].rating);
		}
		fprintf(fpOutput,"\n");
	}

	return newRatings;
}

int stoppingCondition(
	double ** distance_matrix, 
	int *medoids, 
	int *newMedoids, 
	int k)
{
	int stop = 0, i;
	for(i=0; i<k; i++){
		if( distance_matrix[medoids[i]][newMedoids[i]] < 0.1 ){
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