/* ----------------------------------------------------------------------------
 * --  _____       ______  _____                                              -
 * -- |_   _|     |  ____|/ ____|                                             -
 * --   | |  _ __ | |__  | (___    Institute of Embedded Systems              -
 * --   | | | '_ \|  __|  \___ \   Zuercher Hochschule Winterthur             -
 * --  _| |_| | | | |____ ____) |  (University of Applied Sciences)           -
 * -- |_____|_| |_|______|_____/   8401 Winterthur, Switzerland               -
 * ----------------------------------------------------------------------------
 */
/**
 * @file
 * @brief Test suite for the given package.
 */
#include <stdio.h>
#include <stdlib.h>
#include "CUnit/Basic.h"
#include "test_utils.h"
#include "list.h"
#include "person.h"

/// @brief needed to test
#ifndef EXPECTED_FAILURE
#define EXPECTED_FAILURE (1 << 8)
#endif

#ifndef TARGET // must be given by the make file --> see test target
#error missing TARGET define
#endif

/// @brief The name of the STDOUT text file.
#define OUTFILE "stdout.txt"
/// @brief The name of the STDERR text file.
#define ERRFILE "stderr.txt"
/// @brief The name of the temp file for STDIN.
#define INFILE "stdin.txt"

// setup & cleanup
static int setup(void) {
    remove_file_if_exists(OUTFILE);
    remove_file_if_exists(ERRFILE);
    remove_file_if_exists(INFILE);
    return 0; // success
}

static int teardown(void) {
    // Do nothing.
    // Especially: do not remove result files - they are removed in int setup(void) *before* running a test.
    return 0; // success
}

static void test_person_compare(void) {
    Person p1 = (Person) {"a", "", 0};
    Person p2 = (Person) {"b", "", 0};
    CU_ASSERT_EQUAL(persondb_compare_person(p1, p2), 1);

    p1 = (Person) {"a", "", 0};
    p2 = (Person) {"a", "", 0};
    CU_ASSERT_EQUAL(persondb_compare_person(p1, p2), 0);

    p1 = (Person) {"a", "a", 0};
    p2 = (Person) {"a", "b", 0};
    CU_ASSERT_EQUAL(persondb_compare_person(p1, p2), 1);

    p1 = (Person) {"a", "b", 0};
    p2 = (Person) {"a", "a", 0};
    CU_ASSERT_EQUAL(persondb_compare_person(p1, p2), -1);

    p1 = (Person) {"b", "a", 0};
    p2 = (Person) {"a", "b", 0};
    CU_ASSERT_EQUAL(persondb_compare_person(p1, p2), -1);

    p1 = (Person) {"a", "a", 1};
    p2 = (Person) {"a", "a", 0};
    CU_ASSERT_EQUAL(persondb_compare_person(p1, p2), -1);

    p1 = (Person) {"a", "a", 0};
    p2 = (Person) {"a", "a", 1};
    CU_ASSERT_EQUAL(persondb_compare_person(p1, p2), 1);
}

static void test_list_add(void) {
    Person person = (Person) {"aname", "firstname", 0};
    ListElement *list = malloc(sizeof(ListElement));
    persondb_list_create(list);
    ListElement *el = persondb_list_insert(list, &person);
    CU_ASSERT_PTR_NOT_NULL(el);
    Person person2 = (Person) {"bname", "firstname", 0};
    ListElement *el2 = persondb_list_insert(list, &person2);
    CU_ASSERT_PTR_EQUAL(el->next, el2);
}

static void test_list_remove(void) {
    Person person = (Person) {"aname", "firstname", 0};
    ListElement *list = malloc(sizeof(ListElement));
    persondb_list_create(list);
    ListElement *el = persondb_list_insert(list, &person);
    CU_ASSERT_PTR_NOT_NULL(el);
    Person person2 = (Person) {"bname", "firstname", 0};
    ListElement *el2 = persondb_list_insert(list, &person2);
    CU_ASSERT_PTR_EQUAL(el->next, el2);
    int del_count = persondb_list_remove(list, &(Person) {"aname", "firstname", 0});
    CU_ASSERT_EQUAL(del_count, 1);
    int count = persondb_list_show(list);
    CU_ASSERT_EQUAL(count, 1);
}

static void test_remove_multiple(void) {
    Person person = (Person) {"aname", "firstname", 0};
    ListElement *list = malloc(sizeof(ListElement));
    persondb_list_create(list);
    ListElement *el = persondb_list_insert(list, &person);
    persondb_list_insert(list, &(Person) {"cname", "firstname", 0});
    CU_ASSERT_PTR_NOT_NULL(el);
    Person person2 = (Person) {"bname", "firstname", 0};
    persondb_list_insert(list, &person2);
    persondb_list_insert(list, &person2);
    persondb_list_insert(list, &person2);
    persondb_list_insert(list, &person2);
    int del_count = persondb_list_remove(list, &(Person) {"bname", "firstname", 0});
    CU_ASSERT_EQUAL(del_count, 4);
    int count = persondb_list_show(list);
    CU_ASSERT_EQUAL(count, 2);
}

static void test_list_clear(void) {
    ListElement *list = malloc(sizeof(ListElement));
    persondb_list_create(list);
    persondb_list_insert(list, &(Person) {"aname", "firstname", 0});
    persondb_list_insert(list, &(Person) {"bname", "firstname", 0});
    persondb_list_insert(list, &(Person) {"cname", "firstname", 0});
    persondb_list_insert(list, &(Person) {"dname", "firstname", 0});
    persondb_list_insert(list, &(Person) {"ename", "firstname", 0});
    CU_ASSERT_EQUAL(persondb_list_show(list), 5);
    persondb_list_clear(&list);
    CU_ASSERT_EQUAL(persondb_list_show(list), 0);
}

static void test_list_show(void) {
    ListElement *list = malloc(sizeof(ListElement));
    persondb_list_create(list);
    CU_ASSERT_EQUAL(persondb_list_show(list), 0);
    persondb_list_insert(list, &(Person) {"aname", "firstname", 0});
    persondb_list_insert(list, &(Person) {"bname", "firstname", 0});
    persondb_list_insert(list, &(Person) {"cname", "firstname", 0});
    persondb_list_insert(list, &(Person) {"dname", "firstname", 0});
    persondb_list_insert(list, &(Person) {"ename", "firstname", 0});
    CU_ASSERT_EQUAL(persondb_list_show(list), 5);
}

/**
 * @brief Registers and runs the tests.
 * @returns Returns EXIT_SUCCESS (=0) on success,
 *                  EXIT_FAILURE (=1) if more than one argument is given.
 */
int main(void) {
    // setup, run, teardown
    TestMainBasic("03-01-notenstatistik", setup, teardown, test_person_compare, test_list_add, test_list_remove,
                  test_remove_multiple, test_list_show, test_list_clear);
}