#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "probability_distr.h"
#include "LSH_structs.h"

double total_cost(
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

int * clarans(
	int k,
	double ** distance_matrix,
	element ** data_table,
	int * medoids,
	int * assignment,
	int n,
	int clarans_set_fraction,
	int clarans_iterations)
{
	int * current_node= malloc(k*sizeof(int));
	int * neighbor= malloc(k*sizeof(int));
	int * bestNode= malloc(k*sizeof(int));
	int numLocal= clarans_iterations,
		maxNeighbors= clarans_set_fraction,
		temp, j, i, i_2, x, m, t, skip;
	double total_cost_current,
		total_cost_neighbor,
		minCost= -1;
	memcpy(current_node, medoids, k*sizeof(int));
	for(i= 0; i < numLocal+1; i++){
		total_cost_current= total_cost(distance_matrix, n, current_node, assignment);
		j= 0;
		while(j < maxNeighbors){
			x= uniform_distr(0, k*n - 1);
			m= x % k;
			t= x / k;
			for(i_2= 0; i_2 < k; i_2++){
				neighbor[i_2]= current_node[i_2];
			}
			neighbor[m]= t;
			skip= 0;
			for(i_2= 0; i_2 < k; i_2++){
				if((i_2 != m) && (distance_matrix[t][neighbor[i_2]] == 0)){
					skip= 1;
					break;
				}
			}
			if(skip == 1)
				continue;
			//for(i_2= 0; i_2 < k; i_2++){
			//	printf("neighbor medoid %d: %d\n", i_2,neighbor[i_2]);
			//}
			j++;
			total_cost_neighbor= total_cost(distance_matrix, n, neighbor, assignment);
			if(total_cost_current > total_cost_neighbor){
				current_node[m]= t;
				total_cost_current= total_cost_neighbor;
				j= 0;
			}
		}
		//printf("cost of current node %f\n", total_cost_current);
		if( minCost > total_cost_current || minCost == -1){
			minCost= total_cost_current;
			memcpy(bestNode, current_node, k*sizeof(int));
		}
		//printf("min cost %f\n", minCost);
		for(i_2= 0; i_2 < k; i_2++){
			skip= 1;
			while(skip == 1){
				skip= 0;
				m= uniform_distr(0, n-1);
				for(j= 0; j < i_2; j++){
					if(distance_matrix[m][current_node[j]] == 0){
						skip= 1;
						break;
					}
				}
			}
			current_node[i_2]= m;
		}
	}
	//printf("cost %f\n", total_cost(distance_matrix, n, bestNode, assignment));
	free(current_node);
	free(neighbor);
	return bestNode;
}