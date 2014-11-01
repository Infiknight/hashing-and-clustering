#include "array_manip.h"

int array_include(
	int * array_size,
	void ** array,
	int cell_size,
	void * item)
{
	int i;
	for(i= 0; i < *array_size; i++){
		if( (*array)+i*cell_size == item)
			return 1;
	}
	(*array_size)++;
	*array= realloc( *array, (*array_size)*cell_size);
	(*array)[(*array_size)-1]= item;
	return 0;
}