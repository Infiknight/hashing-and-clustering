#include "assign_to_clusters_p.h"
#include <stdlib.h>

/**
 * Used exclusively by assign_to_clusters to enforce parity between the outputs
 * of 1) PAM and 2) reverse_assignment.
 * @param clusters array of clusters
 * @param k number of clusters
 * @return (int*) assignment used by the function that updates the medoids
 */
int * clusterToArray(cluster * clusters, int k){
    int *array;
    int i, j, totalSize;
 
    for(i=0; i<k; i++){
        totalSize+=clusters[i].size;
    }
 
    array = malloc(sizeof(int)*totalSize );
 
    for(i=0; i<k; i++){
        for(j=0; j<clusters[i].size; j++){
            array[clusters[i].elementsIndexes[j]] = i;
        }
    }
	for(i= 0; i < k; i++){
		if(clusters[i].elementsIndexes != NULL)
			free(clusters[i].elementsIndexes);
	}
	free(clusters);
    return array;
 
}

int * assign_to_clusters(
	void ** seeds_h_tables,
	int choice,
	int * medoids,
	int k,
	element ** data_table,
	double ** distance_matrix,
	int dt_size,
	int number_of_hash_functions,
	int number_of_hash_tables,
	metric_space current_space)
{
	if(choice == 1){
		cluster * clusters;
		clusters= PAM(distance_matrix, medoids, dt_size, k);
		return clusterToArray(clusters, k);
	}
	else if(choice == 2)
		return reverse_assignment(seeds_h_tables, medoids, k, distance_matrix, data_table, dt_size, number_of_hash_functions, number_of_hash_tables, current_space);
}