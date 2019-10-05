/**
 * @file person.h
 * @brief Declarations for person.c
 */
#ifndef PERSON_H
#define PERSON_H
/// @brief max length of name
#define PERSON_STRING_LENGTH 20

/**
 * Struct which represents an Person
 */
typedef struct {
    /**
    * @name Person information
    */
    /*@{*/
    char name[PERSON_STRING_LENGTH];/**< Name */
    char firstname[PERSON_STRING_LENGTH];/**< Firstname */
    unsigned age;/**< Age */
    /*@}*/
} Person;

/**
 *  @brief compares two person structs
 * @param p1 person 1
 * @param p2 person 2
 * @return if person 1 and person 2 are the same
 */
int persondb_compare_person(Person p1, Person p2);

/**
 * @brief format variables to output
 * @param buf pointer to string
 * @param index number of list entry
 * @param person person get data from
 */
void persondb_format_person(char buf[57], int index, Person person);

/**
 * @brief lets you read a number
 * @return read number
 */
int persondb_read_safe_int();

/**
 * @brief asks about all details to create a Person struct List Entry
 * @param person pointer to where values will be saved
 */
void persondb_prompt_person(Person *person);

#endif