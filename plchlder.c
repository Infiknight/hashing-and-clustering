
#include <stdlib.h>
#include <math.h>
#include "plchlder.h"

float normal_distr(){
    float U, V, S;
    do{
        U= ( (float) (rand()+1) / (float) (RAND_MAX+2) )*2 - 1;
        V= ( (float) (rand()+1) / (float) (RAND_MAX+2) )*2 - 1;
        S= U*U + V*V;
    }while(S >= 1);
	return U*sqrt( -2*log(S)/S );
}