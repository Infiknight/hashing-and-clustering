#include "distance_matrix.h"
#include "distance_matrix_p.h"

#define LINE_SIZE 10000
#define FILEN_NAME_SIZE 100

int distance_matrix_LSH(
	FILE * stream,
	int L,
	int k)
{
	FILE * qstream;
	FILE * outstream;
	int i;
	element * data_table;
	char queryFile[200];
	char outputFile[200];
	char item_name[100];
	int dimensions,
		radius= 15;
	char trash[LINE_SIZE];
	fgets(trash, LINE_SIZE, stream); //THIS LINE IGNORES THE FIRST LINE OF THE DATA_SAMPLE, REMOVE IT IF IT'S ALREADY BEEN READ
	int size= dm_parser(stream, &data_table, &dimensions);
	fclose(stream);
	//printf("Enter the path of the query file: ");
    //fscanf(stdin, "%s", queryFile);
	//qstream= fopen(queryFile, "r");
	//fscanf(qstream, "%d", &radius);
    //printf("Enter the path of the output file: ");
    //fscanf(stdin, "%s", outputFile);
	//outstream= fopen(outputFile, "w");
	outstream= fopen("output.txt", "w");
	int  hash_table_size[L];
	seed * seed_table[L];
	bucket ** hash_table[L];
	for(i= 0; i < L; i++){
		hash_table[i]= dm_hash_table_constructor(data_table, size, &(hash_table_size[i]), &(seed_table[i]), k);
	}
	//while( fscanf(qstream, "\n%s", item_name) > 4){
	//	for(i= 0; i < size; i++){
	//		if( strcmp(data_table[i].name, item_name) == 0 )
	//			break;
	//	}
	printf("Which item shall be our query?\nitem");
	fscanf(stdin, "%d", &i);
	printf("Which shall be the radius of our search? (0 for nearest-neighboor)\n");
	fscanf(stdin, "%d", &radius);
	int results_no;
	element * query= &(data_table[15]);
		dm_L_search(L, outstream, seed_table, hash_table, data_table, radius, query, &results_no);
		dm_exhaustive_search(data_table, dimensions, query, outstream);
	//}
	//fclose(qstream);
	fclose(outstream);
	return 0;
}
