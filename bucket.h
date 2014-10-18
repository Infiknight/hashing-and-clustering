/* 
 * File:   bucket.h
 * Author: Infiknight
 *
 * Created on October 18, 2014, 3:40 PM
 */

#ifndef BUCKET_H
#define	BUCKET_H

#ifdef	__cplusplus
extern "C" {
#endif

/**
 * A bucket structure based on a singly linked list.
 */
typedef struct Bucket bucket;

/**
 * Constructs a bucket and returns a pointer to it.
 * @return Pointer to the new bucket.
 */
bucket * bucket_construct();

/**
 * Destructs the bucket pointed to by the parameter given.
 * @param bucket0 Bucket to be destructed.
 * @return 0 if it all went well, 1 otherwise.
 */
int bucket_destruct(
	bucket * bucket0);

/**
 * Adds (points to) a unit of data to the bucket.
 * @param bucket0 Pointer to the bucket to which we are going to add the data.
 * @param data Data to be added (pointed to).
 * @return 0 if it's all ok, 1 otherwise.
 */
int bucket_add_data(
	bucket * bucket0,
	void * data);

/**
 * Moves the bucket's iterator to the next element in the bucket;
 * @param bucket0 The bucket in question;
 * @return 1 if theres no next element or for errors and 0 if it's all ok.
 */
int bucket_next(
	bucket * bucket0);

/**
 * Sends the iterator of the bucket back to the beginning.
 * @param bucket0 The bucket whose iterator we want to reset.
 */
void bucket_reset_iterator(
	bucket * bucket0);

/**
 * Returns a pointer to the data pointed to by the iterator of a bucket.
 * @param bucket0 The bucket in question.
 * @return Pointer to the data.
 */
void * bucket_get_currnode_data(
	bucket * bucket0);

#ifdef	__cplusplus
}
#endif

#endif	/* BUCKET_H */

