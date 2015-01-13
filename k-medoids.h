#include "LSH_structs.h"

int kmedoids( FILE * fpInput, metric_space current_space, vector_metric vector_metric_0, int k, int numOfHashFunctions,
			int L, int claransSetFraction, int claransIterations, FILE *fpOutput, int choice_1, int choice_2, int choice_3, int complete);