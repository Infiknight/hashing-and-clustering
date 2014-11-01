#include "vector.h"
#include "euclidean_p.h"
#include <string.h>
#include <stdlib.h>


#define NAME_SIZE 15
#define LINE_SIZE 10000



int euc_parser(
	FILE * stream,
	element ** data_table)
{
	char name[NAME_SIZE];
	char line[LINE_SIZE];
	char * str;
	int size= 0, iter= 0;
	while(fscanf(stream, "%s", name) != EOF){
		*data_table= realloc(*data_table, size+sizeof(element));
		size+= sizeof(element);
		(*data_table)[iter].vector0= vector_construct();
		(*data_table)[iter].name= malloc(NAME_SIZE*sizeof(char));
		strcpy( (*data_table)[iter].name, name);
		memset(line, 0, LINE_SIZE);
		fgets(line, LINE_SIZE, stream);
		vector_add_dimension( (*data_table)[iter].vector0, strtod(strtok(line, "	"),NULL) );
		while( (str= strtok(NULL, "	")) != NULL){
			vector_add_dimension( (*data_table)[iter].vector0, strtod(str,NULL));
		}
		iter++;
	}
	return iter;
}

int euc_parser_clean(
	element * data_table,
	int size)
{
	int i;
	for(i= 0; i < size; i++){
		free(data_table[i].name);
		vector_destruct(data_table[i].vector0);
	}
	free(data_table);
}