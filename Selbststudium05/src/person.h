/**
 * @file person.h
 * @brief Declarations for person.c
 */
#ifndef PERSON_H
#define PERSON_H
/// @brief maximale Länge des Namens
#define PERSON_STRING_LENGTH 20

typedef struct {


    char name[PERSON_STRING_LENGTH];/**< Nachname */
    char firstname[PERSON_STRING_LENGTH];/**< Vorname */
    unsigned age;/**< Alter */
} Person;

/**
 *  @brief vergleicht zwei person structs
 * @param p1 person 1
 * @param p2 person 2
 * @return 0, falls p1 und p2 gleich ansonsten != 0
 */
int persondb_compare_person(Person p1, Person p2);

/**
 * @brief Formatiet die auszugebende Variablen
 * @param buf pointer zum string
 * @param index nummer des listeneintrags
 * @param person Person von der man die Daten will
 */
void persondb_format_person(char buf[57], int index, Person person);

/**
 * @brief überprüft ob eine Zahl eingegeben wird
 * @return eingegebene Nummer
 */
int persondb_read_safe_int();

/**
 * @brief Fragt nach allen Details die es braucht um eine Person einzutragen
 * @param person pointer auf den Speicherort der Werte
 */
void persondb_prompt_person(Person *person);

#endif