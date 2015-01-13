
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vector.h"
#include "bucket.h"
#include "euclidean.h"
#include "euclidean_p.h"
#include "compare.h"

int * concentrate(
	double ** distance_matrix,
	int size,
	int k)
{
	tagged_double v_table[size];
	double sum1, sum2;
	int i, j, t, count= 0;
	for(i= 0; i < size; i++){
		sum1= 0;
		for(j= 0; j < size; j++){
			sum2= 0;
			for(t= 0; t < size; t++){
				sum2+= distance_matrix[j][t];
			}
			sum1+= distance_matrix[i][j] / sum2;
		}
		v_table[i].value= sum1;
		v_table[i].tag= i;
	}
	qsort(v_table, size, sizeof(tagged_double), comp_tagged_double);
	int * medoids= malloc(k*sizeof(int));
	int skip= 0;
	for(i= 0; i < size; i++){
		for(j= 0; j < count; j++){
			if(distance_matrix[v_table[i].tag][medoids[j]] == 0){
				skip= 1;
				break;
			}
		}
		if(skip == 1){
			skip= 0;
			continue;
		}
		medoids[count]= v_table[i].tag;
		count++;
		if(count == k)
			break;
		
	}
	return medoids;
}