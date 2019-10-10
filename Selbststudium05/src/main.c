/**
 * title: Selbststudium 05 - Linked-List
 * created by Nils Mathys
 * date: 05.10.2019
 * @file main.c
 * @brief Main file welches die Session abwickelt
 */
#include "person.h"
#include "list.h"
#include "flusher.c"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Main entry point.
 * @details Behandelt verschiedene Funktionen wie Insert, Remove, Show, Clear oder Create
 * @returns Returns EXIT_SUCCESS (=0) bei success,
 *                  EXIT_FAILURE (=1) wenn mehr als ein Argument gegeben ist.
 */
int main(int argc, char *argv[]) {
    ListElement *list = malloc(sizeof(ListElement));
    persondb_list_create(list);
    int critical_error = 0;
    char c = 0;
    while (critical_error == 0) {
        printf("I(nsert), R(emove), S(how), C(lear), E(nd): ");
        scanf("%c", &c);
        if (c == 'E' || c == 'e') {
            break;
        }
        switch (c) {
            case 'i':
            case 'I': {
                char name[19];
                char firstname[19];
                Person person = (Person) {
                        .name = {*name},
                        .firstname = {*firstname},
                        .age = 0
                };
                persondb_prompt_person(&person);
                ListElement *el = persondb_list_insert(list, &person);
                if (!el) {
                    critical_error = 1;
                }
                break;
            }
            case 'r':
            case 'R': {
                char name[19];
                char firstname[19];
                Person person = (Person) {
                        .name = {*name},
                        .firstname = {*firstname},
                        .age = 0
                };
                persondb_prompt_person(&person);
                int res = persondb_list_remove(list, &person);
                printf("%d entries removed.\n", res);
                break;

            }
            case 's':
            case 'S': {
                int res = persondb_list_show(list);
                printf("%d entries printed.\n", res);
                break;

            }
            case 'c':
            case 'C': {
                persondb_list_clear(list);
                printf("Cleared list.\n");
                break;

            }
            default:
                break;
        }
        flush_stdin();
    }
    if (critical_error == 1) {
        printf("Ran out of memory. Exiting.\n");
    }
}
