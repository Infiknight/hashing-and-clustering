#include "k-medoids++.h"

struct Cluster{
	int medoidIndex;
	int * elementsIndexes;
	int size;
	double cost;
};

typedef struct Cluster cluster;	


cluster * hammingPAM(struct hamming_element * datasetArr, int * medoids, int size, int k);

