/**
 * @file list.h
 * @brief Definitions for list.c
 */
#ifndef LIST_H
#define LIST_H

#include <person.h>

/**
 * @brief a struct representing an list element
 */
typedef struct LE ListElement; // ListElement anstelle von struct LE verwendbar.
/**
 * @brief a struct representing an list element
 */
struct LE {
    /**
    * @name LE content
    */
    /*@{*/
    Person content;/**< this list element persists a person */
    ListElement *next; /**< next list element */
    /*@}*/

};

/**
 * @brief creats with the content a new list element inserts it and returns it
 * @param list pointer to where the content has to be inserted
 * @param content to be inserted
 * @return created ListElement
 */
ListElement *persondb_list_insert(ListElement *list, Person *content);

/**
 * @brief try to delete content of the list
 * @param list from where to remove the content
 * @param content which has to be removed from the list
 * @return if content was deleted
 */
int persondb_list_remove(ListElement *list, Person *content);

/**
 *  @brief removes all elements of the list
 * @param list pointer of pointer of the list
 */
void persondb_list_clear(ListElement **list);

/**
 * @brief prints the list in a nice way
 * @param list to print
 * @return number of elements
 */
int persondb_list_show(ListElement *list);

/**
 * @brief create new list
 * @param list pointer to where list will be in memory
 */
void persondb_list_create(ListElement *list);

#endif
