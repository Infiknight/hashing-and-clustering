#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LSH.h"
#include "euclidean_p.h"
#include "general_distance_matrix.h"
#include "initialize.h"


int LSH(int L, int k){
	char a[100], metricSpace[100], inputFile[100]={0}, library[100]={0}, function[100]={0};
	int lines = 0, repeat = 1;
	int i, j;
	char c;
	FILE *fpInput;

	/*While user wants searches*/
	while(repeat==1){

		printf("Enter the path of the input file: ");
		fscanf(stdin, "%s", inputFile);

	    //printf("file = %s", queryFile);

	    fpInput = fopen(inputFile, "r");
		FILE * out= fopen("outnow.txt", "w");
	    while(fpInput==NULL){
	    	printf("Error in fopen\n");
	    	printf("Enter again the path of the inputfile: ");
	    	fscanf(stdin, "%s", inputFile);
	    	fpInput = fopen(inputFile, "r");
	    }


		fscanf(fpInput, "%s %s ", a, metricSpace);


		//fseek(fpInput, 0, SEEK_SET);
		element * data_table= 0;
		double ** distance_matrix;
		int dt_size, k=5;
		int * medoids;
		if(strcmp(metricSpace , "vector") == 0){
			//euclidean_LSH(fpInput, L,k);
			fscanf(fpInput, "%s %s ", a, metricSpace);
			dt_size= euc_parser(fpInput, &data_table);
			distance_matrix= generate_distance_matrix(euc_distance, data_table, dt_size);
			/*for(i= 0; i < dt_size; i++){
				for(j= 0; j < dt_size; j++){
					fprintf(out, "%lf	", distance_matrix[i][j]);
				}
				fprintf(out, "\n");
			}*/
			medoids= initialize(distance_matrix, dt_size, k, 2);
			for(i= 0; i < k ; i++){
				fprintf(out, "%d\n", medoids[i]);
			}
			//fflush(out);
			//euc_clean_distance_matrix(distance_matrix, dt_size);
			fclose(out);
		}
		//else if(strcmp(metricSpace , "hamming") == 0){
		//	 hammingLHS(fpInput, L, k);
		//}
		else if(strcmp(metricSpace , "matrix") == 0){
			distance_matrix_LSH(fpInput, L, k);
		}
		else if(strcmp(metricSpace , "function") == 0){
			while(lines != 2){
				c = getc(fpInput);
				if (c=='\n')
					lines ++;

			}
			if(lines==2)
				fscanf(fpInput, "%s%s", a, library);

			while(lines != 3){
				c = getc(fpInput);
				if (c=='\n')
					lines ++;

			}
			if(lines==3)
				fscanf(fpInput, "%s%s", a, function);
		}
/*
			
			void* sdl_library = dlopen(library, RTLD_LAZY);
			if (sdl_library == NULL) {
				printf("Error in loadind dynamically the library\n");
				return -1;
			} 
			else {// use the result in a call to dlsym
				//cosine = (double (*)(double)) dlsym(handle, "cos");
			}
			void* initializer = dlsym(sdl_library,function);
			if (initializer == NULL) {
			// report error ...
			} else { // cast initializer to its proper type and use
			}
			typedef void (*sdl_init_function_type)(void);
			sdl_init_function_type init_func = (sdl_init_function_type)
			initializer;
			dlclose(sdl_library);
		}
		else{
			printf("Error in the reading of 1st line\n");
		}
*/
		fclose(fpInput);

		printf("DONE!!!\nFor Another search enter 1 else enter 0: ");
		scanf("%d", &repeat);

	}


}
