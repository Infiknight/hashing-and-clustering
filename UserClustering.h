#ifndef _UC_
#define _UC_

#include "LSH_structs.h"

struct Rating{
	double rating;
	int item;
};

typedef struct Rating rating;	

rating**  recom( FILE * fpInput, metric_space current_space, vector_metric vector_metric_0,int k, int numOfHashFunctions,
			int L, int claransSetFraction, int claransIterations, FILE *fpOutput, int choice_1, int choice_2, int choice_3 , 
			double ** ratingsArray, int users, int items);


#endif
