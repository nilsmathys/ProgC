/* ------------------------------------------------------------------------------
 * title: 	test selbststudium03			                	-
 * author:  Nils Mathys				      	-
 * date:    29.09.2019				                        -
 * description: test for selbststudium03		                -
 --------------------------------------------------------------------------------
 */

/**
 * @file
 * @brief Test suite for the given package.
 */
#include <stdio.h>
#include <stdlib.h>
#include "CUnit/Basic.h"
#include "test_utils.h"

/*
* @brief must be given by the make file --> see test target
*/
#ifndef TARGET 
#error missing TARGET define
#endif


/*
* @brief The name of the STDOUT and STDERROR text file.
*/
#define OUTFILE "stdout.txt"
#define ERRFILE "stderr.txt"

/*
* @brief setup & cleanup, deletes the outfile
*/
static int setup(void)
{
	remove_file_if_exists(OUTFILE);
	remove_file_if_exists(ERRFILE);
	return 0; // success
}

/*
* @brief is executed at the end of all tests. currently no implementation
*/
static int teardown(void)
{
	return 0; // success
}


/*
* #########################################################################
* Test section
* #########################################################################
*/

//units under test
double get_average(int numbers[], int length);
int get_highest_number(int numbers[], int length);
int get_lowest_number(int numbers[], int length);
int amount_same_element_in_array(int marks[], int length, int element);
int amount_above_delimeter(int marks[], int length, int delimeter);
int *points_to_mark(int points[], int length, int maxPoints);
void calculate_statistic(int marks[], int length, int maxPoints);

static const int LENGTH = 3;

/*
* @brief test average function
*/
static void test_get_average(void)
{
	//arrange
	int numbers[] = { 3,6,9 };
	int expResult = 6;
	int result = 0;
	
	//act
	result = get_average(numbers, LENGTH);

	//assert
	CU_ASSERT_EQUAL(result, expResult);
}

/*
* @brief test highest value in array function
*/
static void test_get_highest_value(void)
{
	//arrange
	int numbers[] = { 3,6,9 };
	int expResult = 9;
	int result = 0;
	
	//act
	result = get_highest_number(numbers, LENGTH);

	//assert
	CU_ASSERT_EQUAL(result, expResult);
}

/*
* @brief test highest value in array function
*/
static void test_get_lowest_value(void)
{
	//arrange
	int numbers[] = { 3,6,9 };
	int expResult = 3;
	int result = 0;
	
	//act
	result = get_lowest_number(numbers, LENGTH);

	//assert
	CU_ASSERT_EQUAL(result, expResult);
}

/*
* @brief test amount of elements the same value
*/
static void test_amount_same_element_in_array(void)
{
	//arrange
	int numbers[] = { 3,3,9 };
	int expResult = 2;
	int result = 0;
	
	//act
    result = amount_same_element_in_array(numbers, LENGTH, 3);

	//assert
	CU_ASSERT_EQUAL(result, expResult);
}

/*
* @brief test amount of elements above a delimeter
*/
static void test_amount_above_delimeter(void)
{
	//arrange
	int numbers[] = { 3,6,9 };
	int expResult = 2;
	int result = 0;
	
	//act
	result = amount_above_delimeter(numbers, LENGTH, 6);

	//assert
	CU_ASSERT_EQUAL(result, expResult);
}

/*
* @brief test amount of elements above a delimeter
*/
static void test_points_to_mark(void)
{
	//arrange
	int numbers[] = { 3,6,9 };
	int expResult[] = {3,4,6};
	int *result;
	
	//act
	result = points_to_mark(numbers, LENGTH, 10);

	//assert
	CU_ASSERT_EQUAL(result[0], expResult[0]);
	CU_ASSERT_EQUAL(result[1], expResult[1]);
	CU_ASSERT_EQUAL(result[2], expResult[2]);
}

/**
 * @brief Registers and runs the tests.
 */
int main(void)
{
	// setup, run, teardown
	TestMainBasic("Wordcount", setup
					, teardown
					, test_get_average
					, test_amount_above_delimeter
					, test_amount_same_element_in_array
					, test_get_highest_value
					, test_get_lowest_value
					, test_points_to_mark
				  );
}
