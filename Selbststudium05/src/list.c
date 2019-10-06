/**
 * @file list.c
 * @brief Definiert verschiedene Funktionen wie Insert, Remove, Show, Clear oder Create
 */
#include <stdlib.h>
#include <stdio.h>
#include "person.h"
#include "list.h"

/**
 * @brief Erstellt mit dem Inhalt ein neues Listenelement, fügt es ein und gibt es zurück
 * @param list zeigt auf die Stelle, an der der Inhalt eingefügt werden soll
 * @param content Inhalt der eingefügt werden soll
 * @return erstelltes ListElementer
 */
// Nimmt eine Liste, eine neue Person zum Einfügen und eine Vergleichsfunktion
// Gibt einen Pointer auf das neue Listenelement zurück
ListElement *persondb_list_insert(ListElement *list, Person *content) {
    // speichert zwei Elemente zur bearbeitung, das aktuelle und das nächste der Liste
    // fügen das neue Element zwische ihnen ein, sobald man mit der compare function die richtige Stelle gefunden hat
    ListElement *current = list;
    ListElement *next = list->next;
    while (list != next && persondb_compare_person(next->content, *content) > 0) {
        ListElement *n = next->next;
        current = next;
        next = n;
    }
    // Übereinstimmung gefunden, Person wir vor der nächsten platziert
    ListElement *new = malloc(sizeof(ListElement));
    if (!new) {
        // Speicher konnte nicht zugeordnet werden.
        return NULL;
    }
    *new = (ListElement){
            .content = *content,
            .next = next
    };
    current->next = new;
    return new;
}

//// Nimmt eine Liste, eine neue Person zum Einfügen und eine Vergleichsfunktion
//// Gibt einen Pointer auf das neue Listenelement zurück
//ListElement *persondb_list_insert(ListElement *list, Person *content, int *size) {
//    // speichert zwei Elemente zur bearbeitung, das aktuelle und das nächste der Liste
//    // fügen das neue Element zwische ihnen ein, sobald man mit der compare function die richtige Stelle gefunden hat
//    ListElement *current = list;
//    ListElement *next = list->next;
//    while (list != next && persondb_compare_person(next->content, *content) > 0) {
//        ListElement *n = next->next;
//        current = next;
//        next = n;
//    }
//    // Übereinstimmung gefunden, Person wir vor der nächsten platziert
//    ListElement *new = malloc(sizeof(ListElement));
//    if (!new) {
//        // Speicher konnte nicht zugeordnet werden.
//        return NULL;
//    }
//    *new = (ListElement){
//            .content = *content,
//            .next = next
//    };
//    *size++;
//    //printf("Grösse der Liste : %d\n", *size);
//
//    current->next = new;
//    return new;
//}

/**
 * @brief erntfertn eine Person von der Liste
 * @param list Person die entfernt werden soll
 * @param content Inhalt der aus der Liste entfernt werden soll
 * @return wenn der Inhalt gelöscht wurde
 */
int persondb_list_remove(ListElement *list, Person *content) {
    int ndeleted = 0;
    ListElement *current = list;
    ListElement *next = list->next;
    int res = persondb_compare_person(next->content, *content);
    while (res != 0) {
        ListElement *n = next->next;
        current = next;
        next = n;
        res = persondb_compare_person(next->content, *content);
        printf("Schleife 1, res: %i\n", res);
    }
    while (res == 0) {
        // remove next
        ListElement *n = next->next;
        current->next = n;
        free(next);
        ndeleted++;
        next = n;
        res = persondb_compare_person(next->content, *content);
    }
    return ndeleted;
}

//int persondb_list_remove(ListElement *list, Person *content, int *size) {
//    int ndeleted = 0;
//    ListElement *current = list;
//    ListElement *next = list->next;
//    int res = persondb_compare_person(next->content, *content);
//    while (res != 0) {
//        ListElement *n = next->next;
//        current = next;
//        next = n;
//        res = persondb_compare_person(next->content, *content);
//        printf("Schleife 1, res: %i\n", res);
//    }
//    while (res == 0) {
//        // remove next
//        ListElement *n = next->next;
//        current->next = n;
//        free(next);
//        ndeleted++;
//        next = n;
//        res = persondb_compare_person(next->content, *content);
//        size--;
//    }
//    return ndeleted;
//}



/**
 * @brief gibt die Liste aus
 * @param list Liste die ausgegeben werden soll
 * @return Anzahl der Elemente
 */
int persondb_list_show(ListElement *list) {

    printf("[  ID  ]\t[             name]\t[       first name]\t[ age]\n");

    int i = 0;
    if (list == list->next) {
        return i;
    }
    // überspringe das erste Element (Sentinel)
    ListElement *current = list->next;
    ListElement *next = current->next;
    do {
        char output[57];
        persondb_format_person(output, ++i, current->content);
        printf(output);
        current = next;
        next = current->next;
    } while (list != current);
    return i;
}

/**
 *  @brief erntfernt alle Elemente der Liste
 * @param list pointer of pointer von der Liste
 */
void persondb_list_clear(ListElement **list) {
    // wirft die gesamte Liste weg und gibt ein neues leeres sentinel Element zurück
    if (*list == (*list)->next) {
        // nur Sentinel in der Liste
        return;
    }
    // entfernt jedes Listenelement manuell um Speicherverwaltung zu verbessern
    ListElement *current = (*list)->next;
    ListElement *next = current->next;
    do {
        ListElement *delete = current;
        current = next;
        next = current->next;
        // gibt das gelöscte Element frei, um es dem System zur Verfügung zu stellen
        free(delete);
        // delete 'delete'
    } while (*list != current);
    free(*list);
    *list = malloc(sizeof(ListElement));
    **list = (ListElement){
            .content = (Person){"", "", 0},
            .next = *list
    };
    return;
}

/**
 * @brief generiert eine neue Liste
 * @param list pointer auf den Speicherort der Liste
 */
void persondb_list_create(ListElement *list) {
    *list = (ListElement){
            .content = (Person){"","",0},
            .next = list
    };
}

