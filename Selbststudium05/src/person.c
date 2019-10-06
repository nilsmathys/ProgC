/**
 * @file person.c
 * @brief Datei für den Umgang mit struct person
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "flusher.c"
#include "person.h"

/**
 *  @brief vergleicht zwei person structs
 * @param p1 person 1
 * @param p2 person 2
 * @return 0, falls p1 und p2 gleich ansonsten != 0
 */
int persondb_compare_person(Person p1, Person p2) {
    int res = strcasecmp(p2.name, p1.name); //strcasecmp ignoriert gross/kleinschreibung
    if (res == 0) {
        res = strcasecmp(p2.firstname, p1.firstname);
    }
    if (res == 0) {
        res = p2.age - p1.age;
    }
    return res;
}

/**
 * @brief Formatiert die auszugebende Variablen
 * @param buf pointer zum string
 * @param index Nummer des listeneintrags
 * @param person Person von der man die Daten will
 */
void persondb_format_person(char buf[57], int index, Person person) {
    sprintf(buf, "[%6d]\t%19s\t%19s\t%6d\n", index, person.name, person.firstname, person.age);
}

/**
 * @brief überprüft ob eine Zahl eingegeben wird
 * @return eingegebene Nummer
 */
int persondb_read_safe_int() {
    int num = 0;
    while (scanf("%d", &num) != 1) {
        printf("Error: Expected a number. Please try again: ");
        flush_stdin();
    }
    return num;
}

/**
 * @brief Fragt nach allen Details die es braucht um eine Person einzutragen
 * @param person pointer auf den Speicherort der Werte
 */
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