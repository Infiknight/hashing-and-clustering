#include <stdlib.h>

double ** generate_distance_matrix(
	double (*distance_function)(void*, int, int),
	void * data_table,
	int dt_size)
{
	double ** distance_matrix_2= (double**) malloc(dt_size * sizeof(double*));
	int i, j;
	for(i= 0; i < dt_size; i++){
		distance_matrix_2[i]= (double*) malloc(dt_size * sizeof(double));
		for(j= 0; j < dt_size; j++){
			if( i < j )
				distance_matrix_2[i][j]= (*distance_function)( data_table, i, j);
			else if( i == j )
				distance_matrix_2[i][j]= 0;
			else
				distance_matrix_2[i][j]= distance_matrix_2[j][i];
		}
	}
	return distance_matrix_2;
}

int clean_distance_matrix(
	double ** distance_matrix_2,
	int size)
{
	int i;
	for(i= 0; i < size; i++){
		free(distance_matrix_2[i]);
	}
	free(distance_matrix_2);
	return 0;
}