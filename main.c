/* 
 * File:   main.c
 * Author: Infiknight
 *
 * Created on October 10, 2014, 10:38 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "plchlder.h"

/*
 * 
 */
int main(int argc, char** argv) {
	srand(time(NULL));
	int i;
	for(i= 0; i<10; i++){
		printf("%f\n", normal_distr());
	}
    return (EXIT_SUCCESS);
}

