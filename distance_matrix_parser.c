
#include "distance_matrix_p.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define NAME_SIZE 150
#define LINE_SIZE 100000

element ** dm_parser(
	FILE * stream,
	int * dt_size)
{
	dt_size= 0;
	char line[LINE_SIZE];
	char * word;
	fgets(line, LINE_SIZE, stream);
	strtok(line, " ");
	int size= 0, i= 0, j;
	element ** data_table= NULL;
	while( (word= strtok(NULL, ",")) != NULL){
		data_table= realloc(data_table, size+sizeof(element*));
		size+= sizeof(element);
		data_table[i]= malloc(sizeof(element));
		data_table[i]->name= malloc(NAME_SIZE*sizeof(char));
		strcpy( data_table[i]->name, word);
		i++;
	}
	i= 0;
	while( fgets(line, LINE_SIZE, stream) != NULL){
		j= 0;
		word= strtok(line, "	");
		data_table[i]->array= NULL;
		do{
			data_table[i]->array= realloc( data_table[i]->array, (j+1)*sizeof(int));
			if(j < i)
				data_table[i]->array[j]= data_table[j]->array[i];	//if the input is an upper triangular matrix
			else
				data_table[i]->array[j]= atoi(word);
			j++;
		}while( (word= strtok(NULL, "	")) != NULL);
		i++;
	}
	*dt_size= i;
	return data_table;	//data table ' s size
}
