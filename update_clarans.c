#include <stdlib.h>
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
	int * assignment,
	int n,
	int clarans_set_fraction,
	int clarans_iterations)
{
	int * current_node= malloc(k*sizeof(int));
	int * neighbor= malloc(k*sizeof(int));
	int * bestNode= NULL;
	int numLocal= clarans_iterations,
		maxNeighbors= clarans_set_fraction,
		temp, j, i, i_2, x, m, t;
	double total_cost_current,
		total_cost_neighbor,
		minCost= -1;
	for(i= 0; i < numLocal; i++){
		for(i_2= 0; i_2 < k; i_2++){
			current_node[i_2]= uniform_distr(0, n-1);
		}
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
			j++;
			total_cost_neighbor= total_cost(distance_matrix, n, neighbor, assignment);
			if(total_cost_current > total_cost_neighbor){
				current_node[m]= t;
				total_cost_current= total_cost_neighbor;
				j= 0;
			}
		}
		if( minCost > total_cost_current || minCost == -1){
			minCost= total_cost_current;
			bestNode= current_node;
		}
	}
	free(neighbor);
	return bestNode;
}