#include <gsl/gsl_linalg.h>
#include <math.h>
#include "proteins_p.h"

/* Frobenius norm */
inline static double
normF (gsl_matrix * A)
{
  size_t i, j, M = A->size1, N = A->size2;
  double sum = 0.0, scale = 0.0, ssq = 1.0;

  for (i = 0; i < M; i++)
    {
      for (j = 0; j < N; j++)
        {
          double Aij = gsl_matrix_get (A, i, j);

          if (Aij != 0.0)
            {
              double ax = fabs (Aij);

              if (scale < ax)
                {
                  ssq = 1.0 + ssq * (scale / ax) * (scale / ax);
                  scale = ax;
                }
              else
                {
                  ssq += (ax / scale) * (ax / scale);
                }
            }

        }
    }

  sum = scale * sqrt (ssq);

  return sum;
}

element ** protein_parser_c(
	FILE * stream,
	int * dt_size)
{
	gsl_matrix ** protein_table= protein_parser(stream, dt_size);
	int i, j;
	for(i= 0; i < *dt_size; i++){
		translate_to_origin(protein_table[i]);
	}
	element ** data_table= malloc( (*dt_size)*sizeof(element*) );
	for(i= 0; i < *dt_size; i++){
		data_table[i]= malloc(sizeof(element));
		data_table[i]->position_in_dt= i;
		data_table[i]->array= (double*) malloc((*dt_size)*sizeof(double));
		data_table[i]->name= (char*) malloc(20*sizeof(char));
		for(j= 0; j < *dt_size; j++){
			if( j > i )
				data_table[i]->array[j]= protein_distance_c(protein_table[i], protein_table[j]);
			else if( j == i)
				data_table[i]->array[j]= 0;
			else
				data_table[i]->array[j]= data_table[j]->array[i];
		}
	}
	for(i= 0; i < *dt_size; i++){
		gsl_matrix_free(protein_table[i]);
	}
	free(protein_table);
	return data_table;
}

gsl_matrix ** protein_parser(
	FILE * stream,
	int * numConform)
{
	int i, numOfPoints;
	fscanf(stream, "%d %d", numConform, &numOfPoints);
	gsl_matrix ** protein_table= malloc((*numConform)*sizeof(gsl_matrix *));
	for(i= 0; i < *numConform; i++){
		protein_table[i]= gsl_matrix_alloc(numOfPoints, 3);
		gsl_matrix_fscanf(stream, protein_table[i]);
	}
	return protein_table;
}

int translate_to_origin(
	gsl_matrix * protein)
{
	double median[3]= {0,0,0};
	unsigned int i, j;
	for(i= 0; i< protein->size1; i++){
		for(j= 0; j < protein->size2; j++){
			median[j]+= gsl_matrix_get(protein, i, j);
		}
	}
	for(j= 0; j < protein->size2; j++){
		median[j]/= protein->size1;
	}
	for(i= 0; i < protein->size1; i++){
		for(j= 0; j < protein->size2; j++){
			gsl_matrix_set(protein, i, j, gsl_matrix_get(protein, i, j) - median[j]);
		}
	}
	return 0;
}

double protein_distance_c(
	gsl_matrix * X,
	gsl_matrix * Y)
{
	gsl_matrix * U= gsl_matrix_alloc(X->size2, Y->size2);
	gsl_linalg_matmult_mod(X, GSL_LINALG_MOD_TRANSPOSE, Y, GSL_LINALG_MOD_NONE, U);
	gsl_vector * workspace= gsl_vector_alloc(X->size2); //malloc(X->size2*sizeof(gsl_vector));
	gsl_vector * S= gsl_vector_alloc(X->size2);
	gsl_matrix * V= gsl_matrix_alloc(X->size2, Y->size2);
	gsl_matrix * Q= gsl_matrix_alloc(X->size2, Y->size2);
	gsl_linalg_SV_decomp(U, V, S, workspace);
	free(workspace);
	gsl_linalg_matmult_mod(U, GSL_LINALG_MOD_NONE, V, GSL_LINALG_MOD_TRANSPOSE, Q);
	gsl_matrix * LU= gsl_matrix_alloc(X->size2, Y->size2);
	gsl_matrix_memcpy(LU, Q);
	gsl_permutation * gsl_p= gsl_permutation_alloc(X->size2);
	int signum;
	gsl_linalg_LU_decomp(LU, gsl_p, &signum);
	int i;
	if( gsl_linalg_LU_det(LU, signum) < 0){
		for(i= 0; i < 3; i++){
			gsl_matrix_set(U, i, 2, (-1)*gsl_matrix_get(U, i, 2));
		}
		gsl_linalg_matmult_mod(U, GSL_LINALG_MOD_NONE, V, GSL_LINALG_MOD_TRANSPOSE, Q);
	}
	gsl_matrix_free(LU);
	gsl_vector_free(S);
	gsl_matrix_free(V);
	gsl_matrix * Final= gsl_matrix_alloc(X->size1, Q->size2);
	gsl_linalg_matmult(X, Q, Final);
	gsl_matrix_free(Q);
	gsl_matrix_sub(Final, Y);
	double result= normF(Final)/sqrt((double) X->size1);
	gsl_matrix_free(U);
	gsl_matrix_free(Final);
	return result;
}