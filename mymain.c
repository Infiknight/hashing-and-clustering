#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//#include "hamming2.h"
//#include "euclidean_p.h"
#include "euclidean.h"
//#include "PAM.h"
//#include "update_Improved_PAM.h"
#include "k-medoids.h"


int main(int argc, char *argv[]){


	int  i;
	double curtime;
	int datasetArrSize=0, size=0;
	int * medoids, *newMedoids;
	cluster * clusters;
	struct hamming_element * datasetArr;
	element ** data_table;
	char inputFile[100]={0};
	char confFile[100]={0};
	char outputFile[100]={0};
	char variable[100]={0};
	char a[100], metricSpace[100];
	FILE *fpInput, *fpConf, *fpOutput;
	int k, numOfHashFunctions = 4, L = 5;
	int claransSetFraction = -1;
	int claransIterations = 2;
	int value;
	int complete = 0;


	printf("ARG = %d\n", argc);

	if(argc==7){
		strcpy(inputFile ,argv[2]);
		strcpy(confFile, argv[4]);
		strcpy(outputFile, argv[6]);
	}
	else if((argc==8) && (strcmp(argv[7], "–complete") == 0)) {
		strcpy(inputFile ,argv[2]);
		strcpy(confFile, argv[4]);
		strcpy(outputFile, argv[6]);
		complete = 1;
	}
	else{
		printf("Please run again with the correct parameters\n");
		return -1;
	}

	curtime = time(NULL); 
	srand((unsigned int) curtime); 

	printf("input = %s conf = %s out = %s\n", inputFile, confFile, outputFile );

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
	
	
	if (strcmp(metricSpace, "hamming")==0){
		datasetArr = hammingParser(fpInput, &datasetArrSize);
	}
	else if (strcmp(metricSpace, "vector")==0){
		data_table = euc_parser(fpInput, &datasetArrSize);
	}
	

	if(claransSetFraction == -1){
		if( (int)(0.12 *k*(datasetArrSize-k)) > 250){
			claransSetFraction = (int)(0.12 *k*(datasetArrSize-k));
		}
		else{
			claransSetFraction = 250;
		}
	}

	




	kmedoids(datasetArr, datasetArrSize, k, numOfHashFunctions, L, claransSetFraction, claransIterations, fpOutput, complete);
	

	return 0;
}
