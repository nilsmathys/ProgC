/**
 * @file person.c
 * @brief File for handling struct person
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "flusher.c"
#include "person.h"

int persondb_compare_person(Person p1, Person p2) {
    int res = strcmp(p2.name, p1.name);
    if (res == 0) {
        res = strcmp(p2.firstname, p1.firstname);
    }
    if (res == 0) {
        res = p2.age - p1.age;
    }
    return res;
}

void persondb_format_person(char buf[57], int index, Person person) {
    sprintf(buf, "[%6d]\t%19s\t%19s\t%6d\n", index, person.name, person.firstname, person.age);
}

int persondb_read_safe_int() {
    int num = 0;
    while (scanf("%d", &num) != 1) {
        printf("Error: Expected a number. Please try again: ");
        flush_stdin();
    }
    return num;
}

void persondb_prompt_person(Person *person) {
    printf("Please enter a first name: ");
    scanf("%19s", person->firstname);
    flush_stdin();

    printf("Please enter a name: ");
    scanf("%19s", person->name);
    flush_stdin();

    printf("Please enter an age: ");
    person->age = persondb_read_safe_int();
    while (person->age < 1) {
        printf("Please enter a positive number: ");
        flush_stdin();
        person->age = persondb_read_safe_int();
    }

}