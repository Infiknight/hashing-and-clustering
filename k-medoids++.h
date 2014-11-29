#include "list.h"
#include "bucket.h"
#include "hamming2.h"
#include "euclidean_p.h"


int * hammingSpreadout(struct hamming_element * datasetArr,int size, int k);

int * euclideanSpreadout(element ** datasetArr, int size, int k);

int binarysearch(int x, int a[], int m, int n);

int doublebinarysearch(double x, double a[], int m, int n);
