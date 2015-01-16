#include <stdlib.h>
#include <math.h>
#include "probability_distr.h"
#include "compare.h"

double normal_distr()
{
    double U, V, S;
    do{
        U= ( (double) (rand()+1) / (double) (RAND_MAX+2.0) )*2 - 1;
        V= ( (double) (rand()+1) / (double) (RAND_MAX+2.0) )*2 - 1;
        S= U*U + V*V;
    }while(S >= 1);
	return U*sqrt( -2*log(S)/S );
}

int uniform_distr(
	int min,
	int max)
{
	return (int) floor( (max-min+1) * (rand()/(RAND_MAX+1.0)) + min );
}

int * random_combination(
	int N,
	int M)
{
	int * combination= malloc(M*sizeof(int));
	int chosen[N];
	int i, random_num;
	for(i= 0; i < N; i++){
		chosen[i]= 0;
	}
	for(i= N-M; i < N; i++){
		random_num= uniform_distr(0, i);
		if(chosen[random_num] == 0){
			combination[i-(N-M)]= random_num;
			chosen[random_num]= 1;
		}
		else{
			combination[i-(N-M)]= i;
			chosen[i]= 1;
		}
	}
	qsort(combination, M, sizeof(int), comp_int);
	return combination;
}