/* 
 * File:   list.h
 * Author: Infiknight
 *
 * Created on October 18, 2014, 11:10 AM
 */

#ifndef LIST_H
#define	LIST_H

#ifdef	__cplusplus
extern "C" {
#endif

/**
 * A list structure
 */
typedef struct List list;

/**
 * Constructs a new list.
 * @return A pointer to the newly created list;
 */
list * list_construct();

/**
 * Adds data to the last node without data or creates a new one, if no such node
 * exists, at the end of the list.
 * @param node This should be the first node of the list.
 * @param data The data in question to be pointed to by the last node in the list.
 * @return 0 if everything 's fine, 1 otherwise.
 */
int list_add(
	list * node,
	void * data);

/**
 * Get a pointer to the data of the node given as parameter.
 * @param node The node whose data we want to get.
 * @return Pointer to the data.
 */
void * list_get_currnode_data(
	list * node);

/**
 * Get a pointer to the node which is next to the node given as a parameter.
 * @param node Current node.
 * @return Next node.
 */
list * list_next_node(
	list * node);

/**
 * Destructs and deallocates the memory reserved by the "head" node and all
 * the nodes following it. Therefore if the whole list is to be destructed, the
 * "head" node should be the very first node of the list.
 * @param head The first (or possibly not) node of the list.
 * @return 0 if all went according to plan, 1 otherwise.
 */
int list_destruct(
	list * head);

#ifdef	__cplusplus
}
#endif

#endif	/* LIST_H */

