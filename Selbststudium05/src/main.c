/* ------------------------------------------------------------------------------
 * title: 	SelbstStudium05				                	-
 * author:  Nils Mathys				      	-
 * date:    29.09.2019				                        -
 * description: main for LinkedList			                -
 --------------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "listNode.c"

Person* read_person() {
    char *name = (char *) malloc(sizeof(char) * 8);
    char *firstname = (char *) malloc(sizeof(char) * 8);
    unsigned age = 0;
    (void) printf("Please give a name: ");
    if(scanf("%s", name) > 0){
        (void) printf("\nPlease give a firstname: ");
        if (scanf("%s", firstname) > 0) {
            (void) printf("\nPlease give an age: ");
            if(scanf("%u", &age) > 0) {
                Person *person = (Person *) malloc(sizeof(Person));
                if(person) {
                    person->name = name;
                    person->firstname = firstname;
                    person->age = age;
                    return person;
                }
            } else {
                (void) printf("\nThe value from the age is not correct\n");
            }
        } else {
            printf("\nA not correct firstname has been given\n");}
    } else {
        printf("\nA not correct name has been given\n");
    }
    return NULL;
}

int main(int argc, char* argv[]) {
    ListNode *listNode;
    char command = '\0';
    listNode = new_list();
    do {
        (void) printf("Enter a command: I(nsert), R(emove), S(how), C(lear), E(nd)\n");
        if (scanf(" %c", &command) > 0) {
            switch (command) {
                case 'I':
                    if(insert_person(read_person(), listNode) == 1) {
                        (void) printf("Person added\n");
                    } else {
                        (void) printf("Person not added\n");
                    }
                    break;
                case 'R':
                    if(delete_person(read_person(), listNode) == 1) {
                        (void) printf("Person removed\n");
                    } else {
                        (void) printf("Person not found\n");
                    }
                    break;
                case 'S':
                    (void) printf("Show List:\n");
                    output_list(listNode);
                    break;
                case 'C':
                    (void) printf("Cleaning up\n");
                    clear_list(listNode);
                    listNode = new_list();
                    break;
                case 'E':
                    (void) printf("Good bye\n");
                    break;
                default:
                    (void)printf("Please enter a command\n");
                    break;
            }
        }
    } while (command != 'E');
}