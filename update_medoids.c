#include "update_medoids_p.h"
#include <stdlib.h>

cluster * assignmentToCluster(
	int * assignment, 
	double ** distance_matrix,
	int dt_size, 
	int * medoids,
	int k)
{
    cluster * clusters;
	clusters= (cluster*) malloc(k*sizeof(cluster));
	int i;
	for(i= 0; i < k; i++){
		clusters[i].elementsIndexes= NULL;
		clusters[i].cost= 0;
		clusters[i].size= 0;
		clusters[i].medoidIndex= medoids[i];
	}
	for(i= 0; i < dt_size; i++){
		clusters[assignment[i]].cost+= distance_matrix[medoids[assignment[i]]][i];
		clusters[assignment[i]].size++;
		clusters[assignment[i]].elementsIndexes= realloc(clusters[assignment[i]].elementsIndexes, clusters[assignment[i]].size * sizeof(int));
		clusters[assignment[i]].elementsIndexes[ clusters[assignment[i]].size-1 ]= i;
	}
	//free(assignment);
	return clusters;
}

int * update_medoids(
	int choice,
	int * assignment,
	double ** distance_matrix,
	element ** data_table,
	int dt_size,
	int * old_medoids,
	int k,
	int clarans_set_fraction,
	int clarans_iterations)
{
	if(choice == 1){
		cluster * clusters= assignmentToCluster(
			assignment, 
			distance_matrix,
			dt_size, 
			old_medoids,
			k);
		return UpdateAlaLloyd(clusters, distance_matrix, k);
	}
	else if(choice == 2){
		return clarans(
			k,
			distance_matrix,
			data_table,
			assignment,
			dt_size,
			clarans_set_fraction,
			clarans_iterations);
	}
}
