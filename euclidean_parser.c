#include "vector.h"
#include "euclidean.h"
#include "euclidean_p.h"
#include <string.h>
#include <stdlib.h>


#define NAME_SIZE 15
#define LINE_SIZE 10000



int parser(
	FILE * stream,
	element ** data_table)
{
	char name[NAME_SIZE];
	char line[LINE_SIZE];
	char * str;
	int size= 0, iter= 0;
	while(fscanf(stream, "%s", name) != EOF){
		//printf("%s \n", name);
		*data_table= realloc(*data_table, size+sizeof(element));
		size+= sizeof(element);
		(*data_table)[iter].vector0= vector_construct();
		(*data_table)[iter].name= malloc(NAME_SIZE*sizeof(char));
		strcpy( (*data_table)[iter].name, name);
		memset(line, 0, LINE_SIZE);
		fgets(line, LINE_SIZE, stream);
		//printf("%s\n", line);
		vector_add_dimension( (*data_table)[iter].vector0, strtod(strtok(line, "	"),NULL) );
		while( (str= strtok(NULL, "	")) != NULL){
			vector_add_dimension( (*data_table)[iter].vector0, strtod(str,NULL));
		}
		iter++;
	}
	//vector_print(hash_table[3].vector0);
	return iter;
}

int parser_clean(
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