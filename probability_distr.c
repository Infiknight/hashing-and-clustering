#include <stdlib.h>
#include <math.h>
#include "probability_distr.h"

double normal_distr()
{
    double U, V, S;
    do{
        U= ( (double) (rand()+1) / (double) (RAND_MAX+2) )*2 - 1;
        V= ( (double) (rand()+1) / (double) (RAND_MAX+2) )*2 - 1;
        S= U*U + V*V;
    }while(S >= 1);
	return U*sqrt( -2*log(S)/S );
}