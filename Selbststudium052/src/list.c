/**
 * @file list.c
 * @brief Defines multiple methods for list handling like insert, remove, show, clear or create.
 */
#include <stdlib.h>
#include <stdio.h>
#include "person.h"
#include "list.h"

// takes list, a new person to insert and a compare function
// returns a pointer to the new list element
ListElement *persondb_list_insert(ListElement *list, Person *content) {
    // we save two elements to work on, the current one, and the next one in the list.
    // we insert the new element between them once we found the right place using the compare function
    ListElement *current = list;
    ListElement *next = list->next;
    while (list != next && persondb_compare_person(next->content, *content) > 0) {
        ListElement *n = next->next;
        current = next;
        next = n;
    }
    // found our match, place person before next
    ListElement *new = malloc(sizeof(ListElement));
    if (!new) {
        // memory couldn't be allocated.
        // return NULL, let the user handle it. ideally, exit gracefully.
        return NULL;
    }
    *new = (ListElement){
            .content = *content,
            .next = next
    };
    current->next = new;
    return new;
}

int persondb_list_remove(ListElement *list, Person *content) {
    int ndeleted = 0;
    ListElement *current = list;
    ListElement *next = list->next;
    int res = persondb_compare_person(next->content, *content);
    while (res > 0) {
        ListElement *n = next->next;
        current = next;
        next = n;
        res = persondb_compare_person(next->content, *content);
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

int persondb_list_show(ListElement *list) {

    printf("[  ID  ]\t[             name]\t[       first name]\t[ age]\n");

    int i = 0;
    if (list == list->next) {
        return i;
    }
    // skip the first element (sentinel)
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

void persondb_list_clear(ListElement **list) {
    // throw away entire list, return new clear sentinel element
    if (*list == (*list)->next) {
        // only sentinel in list, return
        return;
    }
    // manually remove every list element for better memory management
    ListElement *current = (*list)->next;
    ListElement *next = current->next;
    do {
        ListElement *delete = current;
        current = next;
        next = current->next;
        // free the deleted element to make it available to the system
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

void persondb_list_create(ListElement *list) {
    *list = (ListElement){
            .content = (Person){"","",0},
            .next = list
    };
}

