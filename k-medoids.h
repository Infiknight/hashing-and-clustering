#include "update_Improved_PAM.h"


int kmedoids(struct hamming_element * datasetArr, int size, int k, int numOfHashFunctions, int L, int claransSetFraction, int claransIterations);

int stoppingCondition(struct hamming_element * datasetArr, int *medoids, int *newMedoids, int k);