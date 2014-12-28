
double silhouette(
	double ** distance_matrix,
	int * assignment,
	int dt_size,
	int * medoids,
	int medoids_size)
{
	int i, j;
	double sum_of_distances, distances_count;
	double a[dt_size];
	double b[dt_size];
	double s[dt_size];
	double sum_of_distances_to_alien[medoids_size];
	double distances_count_to_alien[medoids_size];
	for(i =0; i < dt_size; i++){
		sum_of_distances= 0;
		distances_count= 0;
		for(j= 0; j < medoids_size; j++){
			sum_of_distances_to_alien[j]= 0;
			distances_count_to_alien[j]= 0;
		}
		for(j =0; j < dt_size; j++){
			if(assignment[i] == assignment[j]){
				sum_of_distances+= distance_matrix[i][j];
				distances_count++;
			}
			else{
				sum_of_distances_to_alien[assignment[j]]+= distance_matrix[i][j];
				distances_count_to_alien[assignment[j]]++;
			}
		}
		a[i]= sum_of_distances/distances_count;
		if(medoids[assignment[i]] != 0)
			b[i]= sum_of_distances_to_alien[0]/distances_count_to_alien[0];
		else
			b[i]= sum_of_distances_to_alien[1]/distances_count_to_alien[1];
		for(j= 0; j < medoids_size; j++){
			if(medoids[j] != medoids[assignment[i]]){
				if(b[i] > sum_of_distances_to_alien[j]/distances_count_to_alien[j])
					b[i]= sum_of_distances_to_alien[j]/distances_count_to_alien[j];
			}
		}
		if( a[i] < b[i] && b[i] != 0)
			s[i]= 1 - a[i]/b[i];
		else if( a[i] == b[i] || a[i] == 0 || b[i] == 0)
			s[i]= 0;
		else
			s[i]= b[i]/a[i] - 1;
	}
	double sum= 0;
	for(i= 0; i < dt_size; i++){
		sum+= s[i];
	}
	return sum / (double) dt_size;
}