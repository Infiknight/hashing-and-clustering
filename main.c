#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LSH.h"

int main(int argc, char *argv[]){


	int k, L;
	double curtime;

	curtime = time(NULL); 
	srand((unsigned int) curtime); 

	//if(strcmp(argv[5], "-k") == 0){
	//	k=atoi(argv[6]);
	//}

	//if(strcmp(argv[7], "-L") == 0){
	//	L=atoi(argv[8]);
	//}
	
	LSH(20,4);

	return 0;
}

