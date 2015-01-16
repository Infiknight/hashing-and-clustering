#include "probability_distr.h"
#include <stdlib.h>
#include <gsl/gsl_matrix_double.h>
#include <math.h>
#include "proteins_p.h"

int ** random_edge_selection(
	int no_points,
	int no_pairs)
{
	int * combination= random_combination((no_points*(no_points-1))/2, no_pairs);
	int i, j,
		iterator_1= 0,
		iterator_2= 0;
	int ** pairs= malloc(no_pairs*sizeof(int*));
	for(i= 0; i < no_points; i++){
		for(j= i+1; j < no_points; j++){
			if(iterator_1 == combination[iterator_2]){
				pairs[iterator_2]= malloc(2*sizeof(int));
				pairs[iterator_2][0]= i;
				pairs[iterator_2][1]= j;
				iterator_2++;
			}
			if(iterator_2 == no_pairs){
				free(combination);
				return pairs;
			}
			iterator_1++;
		}
	}
	return 0;
}

double * protein_distance_pairs(
	gsl_matrix * X,
	int ** pairs,
	int r)
{
	double * protein_pairs= malloc(r*sizeof(double));
	double sum;
	int i, j;
	for(i= 0; i < r; i++){
		sum= 0;
		for(j= 0; j < 3; j++){
			sum+= pow(gsl_matrix_get(X, pairs[i][0], j) - gsl_matrix_get(X, pairs[i][1], j), 2);
		}
		protein_pairs[i]= sqrt(sum);
	}
	//gsl_matrix_free(X);
	return protein_pairs;
}

element ** protein_parser_d(
	FILE * stream,
	int * dt_size,
	int no_pairs)
{
	gsl_matrix ** protein_table= protein_parser(stream, dt_size);
	int i, j, k;
	double sum;
	int ** pairs= random_edge_selection( protein_table[0]->size1, no_pairs);
	double ** protein_inter_distance_table= (double**) malloc((*dt_size)*sizeof(double*));
	for(i= 0; i < *dt_size; i++){
		protein_inter_distance_table[i]= protein_distance_pairs( protein_table[i], pairs, no_pairs);
		gsl_matrix_free(protein_table[i]);
	}
	element ** data_table= malloc( (*dt_size)*sizeof(element*) );
	for(i= 0; i < *dt_size; i++){
		data_table[i]= malloc(sizeof(element));
		data_table[i]->position_in_dt= i;
		data_table[i]->array= (double*) malloc((*dt_size)*sizeof(double));
		data_table[i]->name= (char*) malloc(20*sizeof(char));
		for(j= 0; j < *dt_size; j++){
			if( j > i ){
				sum= 0;
				for(k= 0; k < no_pairs; k++){
					sum+= pow(protein_inter_distance_table[i][k] - protein_inter_distance_table[j][k], 2);
				}
				data_table[i]->array[j]= sqrt(sum / no_pairs);
			}
			else if( j == i)
				data_table[i]->array[j]= 0;
			else
				data_table[i]->array[j]= data_table[j]->array[i];
		}
	}
	for(i= 0; i < *dt_size; i++){
		free(protein_inter_distance_table[i]);
		free(pairs[i]);
	}
	free(protein_inter_distance_table);
	free(protein_table);
	return data_table;
}