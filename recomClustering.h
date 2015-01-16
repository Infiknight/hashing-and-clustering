#ifndef _RC_
#define _RC_


double * averageRatings(FILE* fp);
void createDataset(FILE *fp, double *avgRatings, char* filename);
double ** createRatingsArray(FILE* fp, int users, int items);


#endif