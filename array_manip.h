/* 
 * File:   array_manip.h
 * Author: Infiknight
 *
 * Created on October 31, 2014, 6:15 PM
 */

#ifndef ARRAY_MANIP_H
#define	ARRAY_MANIP_H

#ifdef	__cplusplus
extern "C" {
#endif

/**
 * Include a new item in an array of pointers as long as there isn't already a
 * pointer to it in the array.
 * @param array_size Number of pointers in the array.
 * @param array
 * @param cell_size Size of each pointer.
 * @param item Pointer to the item to be added.
 * @return 1 if the item was already in the array, 0 otherwise.
 */
int array_include(
	int * array_size,
	void ** array,
	int cell_size,
	void * item);


#ifdef	__cplusplus
}
#endif

#endif	/* ARRAY_MANIP_H */

