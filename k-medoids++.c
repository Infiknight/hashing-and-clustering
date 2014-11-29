#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <errno.h>
#include "k-medoids++.h"

int * hammingSpreadout(struct hamming_element * datasetArr,int size, int k){
	int k2=1, medoidIndex, i, j, r, randNum, clu;
	int *D, *P;
	
	int * medoidsIndex = malloc(k*sizeof(int));
	D = malloc(size * sizeof(int));
	P = malloc(size * sizeof(int));

	//medoidIndex = uniform_distribution(0, size-1);

	medoidsIndex[k2-1] = uniform_distribution(0, size-1);

	while(k2!=k){
		
		for(i=0; i<size; i++){

			D[i]=hammingDistance(datasetArr[medoidsIndex[0]].str, datasetArr[i].str);
			//printf("str: %s and medoid %s have dist = %d\n",datasetArr[i].str, datasetArr[medoidsIndex[0]].str, D[i]);
			for(j=1; j<k2; j++){
				if(D[i] > hammingDistance(datasetArr[medoidsIndex[j]].str, datasetArr[i].str)) {
					D[i] = hammingDistance(datasetArr[medoidsIndex[j]].str, datasetArr[i].str);
				}
			}
		}

		for(i=0; i<size; i++){

			//printf("dist = %d\n",D[i]);
		}



		for(r=0; r<size; r++){
			P[r]=0;
		}
		for(r=0; r<size; r++){
			for(j=0; j<r; j++){
				P[r] += pow(D[j],2);
			}
		}
		for(r=0; r<size; r++){
		
			//printf("%d\n",P[r] ); 
			
		}
		randNum = uniform_distribution(0, P[size-1]);

		//printf("random = %d\n", randNum);

		medoidsIndex[k2] = binarysearch(randNum, P, 0, size);

		k2++;
		//printf("clu = %d , index = %d\n", P[clu], clu);

	}
	for(i=0; i<k; i++){
		printf("clusterIndex = %d\n", medoidsIndex[i]);
	}

	return medoidsIndex;
}

int * distanceMatrixSpreadout(struct hamming_element * datasetArr, int size, int k){
	
}

int * euclideanSpreadout(element ** datasetArr, int size, int k){
	int k2=1, medoidIndex, i, j, r, clu;
	double *D, *P, randNum;
	
	int * medoidsIndex = malloc(k*sizeof(int));
	D = malloc(size * sizeof(double));
	P = malloc(size * sizeof(double));

	//medoidIndex = uniform_distribution(0, size-1);

	medoidsIndex[k2-1] = uniform_distribution(0, size-1);

	while(k2!=k){
		//printf("HELLO\n");
		for(i=0; i<size; i++){

			D[i]=vector_euclidean_distance(datasetArr[medoidsIndex[0]]->vector0, datasetArr[i]->vector0);
		//	printf("HELLO2\n");
			//printf("str: %s and medoid %s have dist = %d\n",datasetArr[i].str, datasetArr[medoidsIndex[0]].str, D[i]);
			for(j=1; j<k2; j++){
				if(D[i] > vector_euclidean_distance(datasetArr[medoidsIndex[j]]->vector0, datasetArr[i]->vector0)) {
					D[i] = vector_euclidean_distance(datasetArr[medoidsIndex[j]]->vector0, datasetArr[i]->vector0);
				}
			}
		}


		for(i=0; i<size; i++){

			
			//printf("dist = %lf\n",D[i]);
		}


		
		for(r=0; r<size; r++){
			P[r]=0;
		}
		
		for(r=0; r<size; r++){
			for(j=0; j<r; j++){
				P[r] += pow(D[j],2);
			}
		}

		for(r=0; r<size; r++){
		
			//printf("%lf\n",P[r] ); 
			
		}
		randNum = uniform_distribution(0, P[size-1]);

		//printf("HELLO4\n");

		//printf("random = %lf size  = %d\n", randNum, size);

		medoidsIndex[k2] = doublebinarysearch(randNum, P, 0, size);

		printf("k22222222222222222222222222222222222222 = %d\n",k2 );

		//printf("HELLO5\n");

		k2++;
		//printf("clu = %d , index = %d\n", P[clu], clu);

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
