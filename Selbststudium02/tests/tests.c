/* ------------------------------------------------------------------------------
 * title: 	test selbststudium02			                	-
 * author:  Nils Mathys				      	-
 * date:    29.09.2019				                        -
 * description: test for selbststudium02		                -
 --------------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include "CUnit/Basic.h"
#include "test_utils.h"

#ifndef TARGET 
#error missing TARGET define
#endif

#define OUTFILE "stdout.txt"
#define ERRFILE "stderr.txt"


static int setup(void) {
    remove_file_if_exists(OUTFILE);
    remove_file_if_exists(ERRFILE);
    return 0;
}

static int teardown(void) {
    return 0;
}

typedef struct {
    int day;
    int month;
    int year;
} Date;


Date next_Date(Date date);
int schaltjahr(int year);


static void test_main_with_no_arg(void) {
    const char *out_txt[] = { "Bitte gebe das Datum in der Form: \"dd mm yyyy\" ein.\n" };
    int exit_code = system(XSTR(TARGET) " 1>" OUTFILE " 2>" ERRFILE);
    CU_ASSERT_EQUAL(exit_code, 1 << 8);
    assert_lines(OUTFILE, out_txt, sizeof(out_txt)/sizeof(*out_txt));
}

static void test_main_to_many_arg(void) {
    const char *out_txt[] = { "Bitte gebe das Datum in der Form: \"dd mm yyyy\" ein.\n" };
    int exit_code = system(XSTR(TARGET) " 22 1 22 22 1>" OUTFILE " 2>" ERRFILE);
    CU_ASSERT_EQUAL(exit_code, 1 << 8);
        assert_lines(OUTFILE, out_txt, sizeof(out_txt)/sizeof(*out_txt));
}


static void test_FebOnALeapYear(void) {
    Date date = {28, 2, 2020};
    Date date_result = {29, 2, 2020};
    Date nextDate;
    nextDate = next_Date(date);
    CU_ASSERT_EQUAL(date_result.day, nextDate.day);
    CU_ASSERT_EQUAL(date_result.month, nextDate.month);
    CU_ASSERT_EQUAL(date_result.year, nextDate.year);
}

static void test_FebOnALeapYear_before_1583(void) {
    Date date = {28, 2, 400};
    Date date_result = {1, 3, 400};
    Date nextDate;
    nextDate = next_Date(date);
    CU_ASSERT_EQUAL(date_result.day, nextDate.day);
    CU_ASSERT_EQUAL(date_result.month, nextDate.month);
    CU_ASSERT_EQUAL(date_result.year, nextDate.year);
}

static void test_FebOnANotLeapYear(void) {
    Date date = {28, 2, 2019};
    Date date_result = {1, 3, 2019};
    Date nextDate;
    nextDate = next_Date(date);
    CU_ASSERT_EQUAL(date_result.day, nextDate.day);
    CU_ASSERT_EQUAL(date_result.month, nextDate.month);
    CU_ASSERT_EQUAL(date_result.year, nextDate.year);
}

static void test_ChangeYear(void) {
    Date date = {31, 12, 2019};
    Date date_result = {1, 1, 2020};
    Date nextDate;
    nextDate = next_Date(date);
    CU_ASSERT_EQUAL(date_result.day, nextDate.day);
    CU_ASSERT_EQUAL(date_result.month, nextDate.month);
    CU_ASSERT_EQUAL(date_result.year, nextDate.year);
}

static void test_Month30(void) {
    Date date = {30, 11, 2019};
    Date date_result = {1, 12, 2019};
    Date nextDate;
    nextDate = next_Date(date);
    CU_ASSERT_EQUAL(date_result.day, nextDate.day);
    CU_ASSERT_EQUAL(date_result.month, nextDate.month);
    CU_ASSERT_EQUAL(date_result.year, nextDate.year);
}

static void test_Month31(void) {
    Date date = {31, 8, 2019};
    Date date_result = {1, 9, 2019};
    Date nextDate;
    nextDate = next_Date(date);
    CU_ASSERT_EQUAL(date_result.day, nextDate.day);
    CU_ASSERT_EQUAL(date_result.month, nextDate.month);
    CU_ASSERT_EQUAL(date_result.year, nextDate.year);
}

static void test_leapYearTrue(void) {
    int year = 2019;
    int result =  schaltjahr(year);
    CU_ASSERT_EQUAL(result, 0);
}


static void test_leapYearFalse(void) {
    int year = 2020;
    int result = schaltjahr(year);
    CU_ASSERT_EQUAL(result, 1);
}



int main(void) {
    TestMainBasic (
            "Folgetag",
            setup,
            teardown,
            test_main_with_no_arg,
            test_main_to_many_arg,
            test_FebOnALeapYear,
            test_FebOnANotLeapYear,
            test_ChangeYear,
            test_Month30,
            test_Month31,
            test_leapYearTrue,
            test_leapYearFalse,
            test_FebOnALeapYear_before_1583
    );
}
