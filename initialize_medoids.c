#include "initialize_medoids_p.h"

int * initialize(
	double ** distance_matrix,
	int size,
	int k,
	int choice)
{
	if(choice == 1)
		return Spreadout( distance_matrix, size, k);
	if(choice == 2)
		return concentrate( distance_matrix, size, k);
}