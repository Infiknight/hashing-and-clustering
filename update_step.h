/* 
 * File:   update_step.h
 * Author: Infiknight
 *
 * Created on November 30, 2014, 1:35 PM
 */

#ifndef UPDATE_STEP_H
#define	UPDATE_STEP_H

#ifdef	__cplusplus
extern "C" {
#endif

int * clarans(
	int k,
	double ** distance_matrix,
	element ** data_table,
	int * assignment,
	int n,
	metric_space current_metric_space);


#ifdef	__cplusplus
}
#endif

#endif	/* UPDATE_STEP_H */

