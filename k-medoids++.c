#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <errno.h>

int doublebinarysearch(double x, double a[], int m, int n);
int binarysearch(int x, int a[], int m, int n);

int * Spreadout(
	double ** distance_matrix, 
	int size, 
	int k)
{
	int k2=1, medoidIndex, i, j, r, clu;
	double *D, *P, randNum;
	int * medoidsIndex = malloc(k*sizeof(int));
	D = malloc(size * sizeof(double));
	P = malloc(size * sizeof(double));
	medoidsIndex[k2-1] = uniform_distribution(0, size-1);
	while(k2!=k){
		for(i=0; i<size; i++){
			D[i]= distance_matrix[medoidsIndex[0]][i];
			for(j=1; j<k2; j++){
				if(D[i] > distance_matrix[medoidsIndex[j]][i] ) {
					D[i] = distance_matrix[medoidsIndex[j]][i];
				}
			}
		}
		for(r=0; r<size; r++){
			P[r]=0;
		}
		for(r=0; r<size; r++){
			for(j=0; j<r; j++){
				P[r] += pow(D[j],2);
			}
		}
		randNum = uniform_distribution(0, P[size-1]);
		medoidsIndex[k2] = doublebinarysearch(randNum, P, 0, size);
		k2++;
	}
	for(i=0; i<k; i++){
		printf("clusterIndex = %d\n", medoidsIndex[i]);
	}
	return medoidsIndex;
}

 int binarysearch(int x, int a[], int m, int n)
{
    int middle=(m+n)/2;
    //printf("I AM IN m = %d n = %d middle = %d\n",m, n, middle );
    if((a[middle]>=x) && (a[middle-1]<x))
    {
        //printf("%d has been found at postion %d!\n", x, middle+1);
        return middle;
    }
    else
    if(x > a[middle])
        return binarysearch(x, a, middle, n);
    else
    if(x < a[middle])
        return binarysearch(x, a, m, middle);

   //if it is not found in the whole array
   return -1;


}

 int doublebinarysearch(double x, double a[], int m, int n)
{
	//printf("I AM IN m = %d n = %d\n", m, n);
    int middle=(m+n)/2;
    //printf("I AM IN 2 middle = %d\n", middle);
    if((a[middle]>=(double)x) && (a[middle-1]<(double)x))
    {
        //printf("%d has been found at postion %d!\n", x, middle+1);
      //  printf("I AM IN 3\n");
        return middle;
    }

    else
    if(x > a[middle])
        return doublebinarysearch(x, a, middle, n);
    else
    if(x < a[middle])
        return doublebinarysearch(x, a, m, middle);

   //if it is not found in the whole array
   return -1;


}
