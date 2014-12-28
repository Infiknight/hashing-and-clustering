#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//#include "hamming2.h"
//#include "euclidean_p.h"
//#include "PAM.h"
//#include "update_Improved_PAM.h"
#include "k-medoids.h"
#include "LSH_structs.h"


int main(int argc, char *argv[]){


	int  i;
	double curtime;
	int datasetArrSize=0, size=0;
	int * medoids, *newMedoids;
	//cluster * clusters;
	//struct hamming_element * datasetArr;
	element ** data_table;
	char inputFile[100]={0};
	char confFile[100]={0};
	char outputFile[100]={0};
	char variable[100]={0};
	char a[100], metricSpace[100];
	FILE *fpInput, *fpConf, *fpOutput;
	int k= 5, numOfHashFunctions = 4, L = 5;
	int claransSetFraction = -1;
	int claransIterations = 2;
	int value;
	int choice_1, choice_2, choice_3;
	int complete = 0;


	printf("ARG = %d\n", argc);
		//strcpy(inputFile ,"DataEuclidean.csv");
		//strcpy(confFile, "random.txt");
		//strcpy(outputFile, "output.txt");
		//complete = 1;
	if(argc==7){
		strcpy(inputFile ,argv[2]);
		strcpy(confFile, argv[4]);
		strcpy(outputFile, argv[6]);
	}
	else if((argc==8) && ((strcmp(argv[7], "–complete") == 0) || (strcmp(argv[7], "-complete"))== 0)) {
		strcpy(inputFile ,argv[2]);
		strcpy(confFile, argv[4]);
		strcpy(outputFile, argv[6]);
		complete = 1;
	}
	else{
            strcpy(inputFile ,"DataHamming.csv");
            strcpy(confFile, "random.txt");
            strcpy(outputFile, "output.txt");
            complete = 1;
		//printf("Please run again with the correct parameters\n");
		//return -1;
	}

	curtime = time(NULL); 
	srand((unsigned int) curtime); 

	//printf("input = %s conf = %s out = %s\n", inputFile, confFile, outputFile );

	//printf("Enter the path of the input file: ");
	//fscanf(stdin, "%s", inputFile);


	fpInput = fopen(inputFile, "r");
	if(fpInput==NULL){
	    printf("Error in fopen\n");
	   	return -1;
	}

	fpOutput = fopen(outputFile , "w");
	if(fpInput==NULL){
	    printf("Error in fopen\n");
	   	return -1;
	}

	fpConf = fopen(confFile, "r");
	if(fpConf == NULL){
	    printf("Error in fopen\n");
	    return -1;
	}


	fscanf(fpInput, "%s%s", a, metricSpace);
	printf("Metric = %s\n",metricSpace );

	fseek(fpInput, 0, SEEK_SET);

	while(fscanf(fpConf, "%s%d", variable, &value) != EOF){
		if(strcmp(variable, "number_of_clusters:") == 0 ){
			k=value;
		}
		else if(strcmp(variable, "number_of_hash_functions:") == 0 ){
			numOfHashFunctions=value;
		}
		else if(strcmp(variable, "number_of_hash_tables:") == 0 ){
			L=value;
		}
		else if(strcmp(variable, "clarans_set_fraction:") == 0 ){
			claransSetFraction=value;
		}
		else if(strcmp(variable, "clarans_iterations:") == 0 ){
			claransIterations=value;
		}
		else{
			printf("Wrong Data in Conf. File\n");
			return -1;
		}

	}

	printf("%d %d %d %d %d\n", k , numOfHashFunctions, L, claransSetFraction, claransIterations);
	
	metric_space current_space;
	if (strcmp(metricSpace, "hamming")==0){
		current_space= hamming;
	}
	else if (strcmp(metricSpace, "vector")==0){
		current_space= euclidean;
	}
	else if(strcmp(metricSpace , "matrix") == 0)
			current_space= distance_matrix;
	if(claransSetFraction == -1){
		if( (int)(0.12 *k*(datasetArrSize-k)) > 250){
			claransSetFraction = (int)(0.12 *k*(datasetArrSize-k));
		}
		else{
			claransSetFraction = 250;
		}
	}

	


	//for(choice_1=1; choice_1<=2; choice_1++){
	//	for(choice_2=1; choice_2<=2; choice_2++){
	//		for(choice_3=1; choice_3<=2; choice_3++){
	//			
					kmedoids( fpInput, current_space, k, numOfHashFunctions, L, claransSetFraction, claransIterations, fpOutput, 1, 2 ,1, complete);
	//			
	//		}
	//	}
	//}

	return 0;
}
