/**
 * @file list.h
 * @brief DDefinition der list.c
 */
#ifndef LIST_H
#define LIST_H

#include <person.h>


typedef struct LE ListElement; // ListElement anstelle von struct LE verwendbar.

struct LE {
    /**
    * @name LE content
    */
    Person content;/**< Dieses Listenelement enthält eine Person */
    ListElement *next; /**< nächstes Listenelement */


};

/**
 * @brief Erstellt mit dem Inhalt ein neues Listenelement, fügt es ein und gibt es zurück
 * @param list zeigt auf die Stelle, an der der Inhalt eingefügt werden soll
 * @param content Inhalt der eingefügt werden soll
 * @return erstelltes ListElementer
 */
ListElement *persondb_list_insert(ListElement *list, Person *content);

//ListElement *persondb_list_insert(ListElement *list, Person *content, int *size);

/**
 * @brief erntfertn eine Person von der Liste
 * @param list Person die entfernt werden soll
 * @param content Inhalt der aus der Liste entfernt werden soll
 * @return wenn der Inhalt gelöscht wurde
 */
int persondb_list_remove(ListElement *list, Person *content);

//int persondb_list_remove(ListElement *list, Person *content, int *size);

/**
 * @brief gibt die Liste aus
 * @param list Liste die ausgegeben werden soll
 * @return Anzahl der Elemente
 */
int persondb_list_show(ListElement *list);

/**
 *  @brief erntfernt alle Elemente der Liste
 * @param list pointer of pointer von der Liste
 */
void persondb_list_clear(ListElement **list);

/**
 * @brief generiert eine neue Liste
 * @param list pointer auf den Speicherort der Liste
 */
void persondb_list_create(ListElement *list);

#endif
