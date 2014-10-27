#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <errno.h>
#include "hamming.h"


struct hamming * parser(FILE *fp, int *arrSize){

	struct hamming * arr;
	char  name[100], str[100];

	arr = (struct hamming *) malloc(sizeof(struct hamming));


	while(fscanf(fp, "%s%s", name, str) != EOF){
		arr = (struct hamming *) realloc(arr, ((*arrSize) +1) * sizeof(struct hamming));
		if(arr==NULL){
			perror("realloc");
		}


		if((*arrSize)>=1){
			arr[(*arrSize) - 1].name = (char *) malloc(sizeof(name));
			strcpy(arr[(*arrSize)-1].name, name);
			arr[(*arrSize)-1].str = (char *) malloc(sizeof(str));
			strcpy(arr[(*arrSize)-1].str, str);
		}


		(*arrSize)++;

	}

	(*arrSize)--;
	return arr;
}


struct hash_table_t * hamming_hash_table_constructor(struct hamming* data_table, int data_table_size, int k){
	
	struct hash_table_t * hash_table;
	int  d, i, bucketIndex=0, j, error;
	char x[100];


	d = strlen(data_table[1].str);


	if( ( hash_table = malloc( sizeof(struct hash_table_t ) ) ) == NULL ) {
		perror("hashtable malloc");
		exit(1);
	}



    hash_table->size = pow(2,k);
    hash_table->k = k;
    hash_table->hIndexes = (int *) malloc(k*sizeof(int));

    for(i=0; i<hash_table->size; i++){
		hash_table->table[i] = bucket_construct();
    }


	for(i=0; i<k; i++){
			hash_table->hIndexes[i] = uniform_distribution(0, d);
	}

	printf("d = %d, k = %d\n", d, k);
	for(i=0; i<k; i++){
		printf("%d, ", hash_table->hIndexes[i]);
	}
	printf("\n");


    for(i=0; i<data_table_size; i++){

	
		strcpy(x,data_table[i].str);

		bucketIndex = g(x, hash_table->hIndexes, k);
		

		printf("bucketIndex = %d\n",bucketIndex );

		error = bucket_add_data(hash_table->table[bucketIndex],&data_table[i]);
		//printf("ERROR = %d\n",error );

	}

	return hash_table;

}




int g(char* str, int * hIndexes, int k) {



	int j, bucketIndex;
	char g[100] = {0};
	
	for(j=0; j<k; j++){
		g[j] = str[hIndexes[j]];
	}


	bucketIndex = binaryStringToDecimal(g);
	
	return bucketIndex;
	
}

int uniform_distribution(int low, int high) {
    double rand2 = rand()/(1.0 + RAND_MAX); 
    int range = high - low + 1;
    int rand3 = (rand2 * range) + low;
    return rand3;
}

int binaryStringToDecimal(char *str){
	int i, dec=0;
	for(i=0; i<strlen(str); i++){
		if(str[i] =='1'){
		dec += 1 * pow(2,strlen(str)-1-i);
		}
	}

	return dec;
}

int hammingDistance(char *str1, char *str2){
	int i=0, dist=0;

	for(i=0; i<strlen(str1); i++){
		if (str1[i]!=str2[i]){
			dist++;
		}
	}
	return dist;
}

