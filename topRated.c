#include <stdio.h>
#include <stdlib.h>
#include "topRated.h"

void topRated(double ** ratings, int users, int items, rating** newRatings){
	int i, j, k, l=0;
	int ** topRatedItemsIndexes;
	double temp;
	int temp2;


	topRatedItemsIndexes = (int**) malloc(users*sizeof(int));
	for(i=0; i<users; i++){
		topRatedItemsIndexes[i] = (int *)malloc(items * sizeof(int));
	}

	//for(i=0; i<users; i++){
	//	for(j=0; j<items; j++){
	//		topRatedItemsIndexes[i][j]
	//	}
	//}



	for(i=0; i<users; i++){
		l=0;
		for(j=items-2; j>=0; j--){
      		for(k=0; k<=j; k++){
           		if(newRatings[i][k].rating < newRatings[i][k+1].rating){
               		temp = newRatings[i][k].rating;
               		temp2 = newRatings[i][k].item;
              		newRatings[i][k].rating = newRatings[i][k+1].rating;
              		newRatings[i][k].item = newRatings[i][k+1].item;
              		newRatings[i][k+1].rating = temp;
              		newRatings[i][k+1].item = temp2;
              		
           		}
      		}
      		//printf("l = %d\n", l);
      		//l++;
  		}
		

	}

	for(i=0; i<2; i++){
		printf("RATEDUser%d\n", i+1);
		for(j=0; j<10; j++){
				printf("RATING = %lf, ITEM = %d\n",newRatings[i][j].rating, newRatings[i][j].item);
		}
		printf("\n");
	}



	//for(i=0; i<items; i++){
		//printf("%d ", topRatedItemsIndexes[0][i]);	
	//}

}


