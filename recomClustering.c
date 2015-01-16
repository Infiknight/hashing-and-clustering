#include <stdio.h>
#include <stdlib.h>
#include "recomClustering.h"

double * averageRatings(FILE* fp){

	int user, item, rating, user0, item0, rating0, sumRating=0, numOfUsers=0, numOfRatingItems=0, i;
	double *avgRatings;

	avgRatings = (double*) malloc(sizeof(double));

	fscanf(fp, "%d%d%d", &user0, &item0, &rating0);
	sumRating+=rating0;
	numOfRatingItems++;
	while(fscanf(fp, "%d%d%d", &user, &item, &rating) != EOF){
		if(user == user0){
			sumRating+=rating;
			numOfRatingItems++;
		}
		else{
			avgRatings[numOfUsers] = (double)sumRating/(double)numOfRatingItems;
			//printf("avg %d/%d = %lf\n",sumRating, numOfRatingItems,(double)sumRating/(double)numOfRatingItems );
			user0=user;
			sumRating=0;
			numOfRatingItems=0;
			sumRating+=rating;
			numOfRatingItems++;
			numOfUsers++;
			avgRatings = (double *) realloc(avgRatings, (numOfUsers+1) * sizeof(double));

		}
	}
	//printf("avg %d/%d = %lf\n",sumRating, numOfRatingItems,(double)sumRating/(double)numOfRatingItems );
	avgRatings[numOfUsers] = (double)sumRating/(double)numOfRatingItems;

	for ( i = 0; i <=numOfUsers; i++)
	{
		//printf("%f\n", avgRatings[i]);
	}

	return avgRatings;

}

void createDataset(FILE *fp, double *avgRatings, char* filename){
	
	int user, item, rating, user0, item0, rating0, users=1, i;
	FILE* fp2;


	fp2 = fopen(filename, "w");

	fseek (fp , 0 , SEEK_SET );

	fprintf(fp2, "@metric_space vector\n@metric euclidean\n");

	fscanf(fp, "%d%d%d", &user0, &item0, &rating0);

	fprintf(fp2, "user%d\t", users);
	
	printf("user = %d, item0 = %d, rating0 = %d\n",user0, item0, rating0);

	for(i=0; i<item0-1; i++){
		fprintf(fp2, "0\t");
	}
	fprintf(fp2, "%f\t", rating0- avgRatings[users-1]);

	while(fscanf(fp, "%d%d%d", &user, &item, &rating) != EOF){
		if(user == user0){
			for(i=0; i<item -item0 -1; i++){
				fprintf(fp2, "0\t");
			}
			fprintf(fp2, "%f\t", rating- avgRatings[users-1]);
			item0=item;
		}
		else{
			printf("item0 = %d\n", item0);
			for(i=0; i<1000-item0; i++){
				fprintf(fp2, "0\t");
			}
			users++;
			fprintf(fp2, "\nuser%d\t", users);
			user0 = user;
			item0 = item;
			rating0 = rating;

			for(i=0; i<item0-1; i++){
				fprintf(fp2, "0\t");
			}
			fprintf(fp2, "%f\t", rating0- avgRatings[users-1]);

		}
	}

	for(i=0; i<1000-item0; i++){
		fprintf(fp2, "0\t");
	}

}

double ** createRatingsArray(FILE* fp, int users, int items){
	int user, item, rating, user0, item0, rating0, sumRating=0, numOfUsers=0, numOfRatingItems=0, i, j;
	double ** ratingsArray;

	ratingsArray = (double**) malloc(users*sizeof(double));
	for(i=0; i<users; i++){
		ratingsArray[i] = (double *)malloc(items * sizeof(double));
	}


	for(i=0; i<users; i++){
		for(j=0; j<items; j++){
			ratingsArray[i][j] = 0;
		}
	}

	//fscanf(fp, "%d%d%d", &user0, &item0, &rating0);
	//ratingsArray[user0-1][item0-1] = rating0;
	while(fscanf(fp, "%d%d%d", &user, &item, &rating) != EOF){
		ratingsArray[user-1][item-1] = (double)rating;
	}
	
	for(i=0; i<users; i++){
		for(j=0; j<items; j++){
			if(ratingsArray[i][j]!=0){
				printf("user:%d, item:%d,  rating = %lf\n", i+1, j+1,ratingsArray[i][j]);
			}
		}
		printf("\n");
	}

	return ratingsArray;
}