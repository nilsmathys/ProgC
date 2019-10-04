/* ------------------------------------------------------------------------------
 * title: 	SelbstStudium05				                	-
 * author:  Nils Mathys				      	-
 * date:    29.09.2019				                        -
 * description: listNode for Linkedlist			                -
 --------------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listNode.h"

void* new_list() {
    ListNode *listNode = (ListNode *) malloc(sizeof(ListNode));
    if(listNode) {
        Person *person = (Person *) malloc(sizeof(Person));
        listNode->previous = listNode;
        listNode->content = person;
        listNode->next = listNode;
        return listNode;
    } else {
        return NULL;
    }
}

int insert_person(Person* person, ListNode* header) {
    ListNode *listNode = (ListNode *)malloc(sizeof(ListNode));
    if(listNode) {
        if(header->next == header) {
            header->next = listNode;
            header->previous = listNode;
            listNode->content = person;
            listNode->previous = header;
            listNode->next = header;
        } else {
            ListNode *tmp = header;
            if(person->name[0] < 'n') {
                while((tmp->next != header) && (compare_person(tmp->next, person) <=0)) {
                    tmp = tmp->next;
                }
                ListNode *tmp_next = tmp->next;
                tmp->next = listNode;
                tmp_next->previous = listNode;
                listNode->content = person;
                listNode->next = tmp_next;
                listNode->previous = tmp;
            } else {
                while((tmp->previous != header) && (compare_person(tmp->previous, person) >= 0)) {
                    tmp = tmp->previous;
                }
                ListNode *tmp_next = tmp->previous;
                tmp->previous = listNode;
                tmp_next->next = listNode;
                listNode->content = person;
                listNode->previous = tmp_next;
                listNode->next = tmp;
            }
        }
    }
    return 1;
}

int delete_person(Person* person, ListNode* header) {
    ListNode *last_element = header;
    ListNode *index = header;
    while (index->next != header) {
        index = index->next;
        last_element = index->previous;
        if(compare_person(index, person) == 0) {
            ListNode *tmp = index->next;
            last_element->next = tmp;
            tmp->previous = last_element;
            free(index->content);
            free(index->content->name);
            free(index->content->firstname);
            free(index);
            return 1;
        }
        last_element = index->next;
    }
    return 0;
}

void output_list(ListNode* header) {
    ListNode *index = header;
    while (index->next != header) {
        index = index->next;
        (void) printf("Name: %s, Firstname: %s, Age: %i\n", index->content->name, index->content->firstname, index->content->age);
    }
}

void clear_list(ListNode* header) {
    ListNode *index = header->next;
    ListNode *next_node = header->next;
    while (index->next != header) {
        next_node= index->next;
        free(index->content->name);
        free(index->content->firstname);
        free(index->content);
        free(index);
        index = next_node;
    }
    free(header);
}


int compare_person(ListNode* node, Person* person2) {
    Person *person1 = node->content;
    int name_comparsion = strcmp(person1->name, person2->name);
    if(name_comparsion == 0) {
        int firstname_comparsion = strcmp(person1->firstname, person2->firstname);
        if(firstname_comparsion == 0) {
            return person1->age-person2->age;
        } else {
            return firstname_comparsion;
        }
    } else {
        return name_comparsion;
    }
}














