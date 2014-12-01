#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LSH.h"
#include "LSH_structs.h"
#include "initialize.h"
#include "reverse_assignment.h"
#include "update_step.h"


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


		fseek(fpInput, 0, SEEK_SET);
		element ** data_table= NULL;
		double ** distance_matrix_2;
		int dt_size, k=5;
		int * medoids, * assignment;
		//euclidean_LSH(fpInput, L,k); return 0;
		metric_space current_space;
		if(strcmp(metricSpace , "vector") == 0)
			current_space= euclidean;
		else if(strcmp(metricSpace , "matrix") == 0){
			current_space= distance_matrix;
		}
		else if(strcmp(metricSpace , "hamming") == 0)
			current_space= hamming;
		//if(strcmp(metricSpace , "vector") == 0){
			//euclidean_LSH(fpInput, L,k);
			//fscanf(fpInput, "%s %s ", a, metricSpace);
			data_table= generic_parser(fpInput, &dt_size, current_space);
			distance_matrix_2= general_generate_distance_matrix((void*)data_table, dt_size, current_space);
			printf("%d\n", dt_size);
			//for(i= 0; i < dt_size; i++){
				//for(j= 0; j < dt_size; j++){
					//printf("%f	", distance_matrix_2[i][j]);
				//}
				//printf("\n");
			//}
			medoids= initialize(distance_matrix_2, dt_size, k, 2);
			for(i= 0; i < k ; i++){
				fprintf(out, "%d\n", medoids[i]);
			}
			fflush(out);
			assignment= reverse_assignment(
				medoids,
				k,
				distance_matrix_2,
				data_table,
				dt_size,
				current_space);
			//fflush(out);
			//euc_clean_distance_matrix(distance_matrix, dt_size);
			medoids= clarans(
				k,
				distance_matrix_2,
				data_table,
				assignment,
				dt_size,
				current_space);
			fprintf(out, "----------------\n");
			for(i= 0; i < k; i++){
				fprintf(out, "%d\n", medoids[i]);
			}
			fclose(out);
		//}
		//else if(strcmp(metricSpace , "hamming") == 0){
		//	 hammingLHS(fpInput, L, k);
		//}
		//else if(strcmp(metricSpace , "matrix") == 0){
		//	distance_matrix_LSH(fpInput, L, k);
		//}
		if(strcmp(metricSpace , "function") == 0){
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
