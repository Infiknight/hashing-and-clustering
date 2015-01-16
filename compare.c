#include "compare.h"

int comp_int(
	const void * elem1,
	const void * elem2)
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

int comp_double(
	const void * elem1,
	const void * elem2)
{
    double f = *((double*)elem1);
    double s = *((double*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

int comp_tagged_double(
	const void * elem1,
	const void * elem2)
{
	tagged_double f= *((tagged_double*)elem1);
	tagged_double s= *((tagged_double*)elem2);
	if( f.value > s.value )
		return 1;
	if( f.value < s.value )
		return -1;
	return 0;
}