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
#include "array.h"
#include "string.h"

#ifndef TARGET // must be given by the make file --> see test target
#error missing TARGET define
#endif

/// @brief The name of the STDOUT text file.
#define OUTFILE "stdout.txt"
/// @brief The name of the STDERR text file.
#define ERRFILE "stderr.txt"

/// @brief The Stimulus for a correct input
#define INFILE_CORRECT "stm_correct.input"

// setup & cleanup
static int setup(void)
{
	remove_file_if_exists(OUTFILE);
	remove_file_if_exists(ERRFILE);
	return 0; // success
}

static int teardown(void)
{
	// Do nothing.
	// Especially: do not remove result files - they are removed in int setup(void) *before* running a test.
	return 0; // success
}


// tests

static void test_initialize_array_to_zero(void) 
{
    char array[] = "Hallo";
    (void)initialize_array_to_zero(array, 6);
    CU_ASSERT_EQUAL(array[0], 0);
    CU_ASSERT_EQUAL(array[1], 0);
    CU_ASSERT_EQUAL(array[2], 0);
    CU_ASSERT_EQUAL(array[3], 0);
    CU_ASSERT_EQUAL(array[4], 0);
    CU_ASSERT_EQUAL(array[5], 0);
}

static void test_array_contains_entry(void) 
{
    char word1[] = "Hallo";
    char word2[] = "du";
    char *words[] = {&word1, &word2};
    
    char word3[] = "Hallo";
    boolean res = array_contains_entry(words, 2, word3);
    CU_ASSERT_TRUE(res);
}

static void test_save_word_in_array_new(void) 
{
    char word1[] = "Hallo";
    char word2[] = "du";
    char *words[] = {&word1, &word2, NULL};
    size_t size = 2;
    
    char word3[] = "wie";
    save_word_in_array(words, &size, word3);
    CU_ASSERT_EQUAL(strcmp(words[2], word3), 0);
}

static void test_save_word_in_array_existing(void) 
{
    char word1[] = "Hallo";
    char word2[] = "du";
    char *words[] = {&word1, &word2, NULL};
    size_t size = 2;
    
    char word3[] = "Hallo";
    save_word_in_array(words, &size, word3);
    CU_ASSERT_EQUAL(size, 2);
}

static void test_get_compare_length_first(void) 
{
    char word1[] = "Hallo";
    char word2[] = "du";
    size_t length = get_compare_length(word2, word1);
    CU_ASSERT_EQUAL(length, strlen(word2));
}

static void test_get_compare_length_second(void) 
{
    char word1[] = "Hallo";
    char word2[] = "du";
    size_t length = get_compare_length(word1, word2);
    CU_ASSERT_EQUAL(length, strlen(word2));
}

static void test_sort_word_array(void)
{
    char word1[] = "Zwiebel";
    char word2[] = "Banane";
    char word3[] = "Birne";
    char word4[] = "Apfel";
    char *wordlist[] = {&word1, &word2, &word3, &word4};
    
    sort_word_array(wordlist, 4);
    
    CU_ASSERT_EQUAL(wordlist[0], &word4);
    CU_ASSERT_EQUAL(wordlist[1], &word2);
    CU_ASSERT_EQUAL(wordlist[2], &word3);
    CU_ASSERT_EQUAL(wordlist[3], &word1);
}


static void test_main(void)
{
	// arrange
	const char *out_txt[] = { 
	    "---------------------------------\n",
	    "Woerter in sortierter Reihenfolge:\n",
	    "=================================\n",
	    "Apfel\n",
	    "Banane\n",
	    "Birne\n", 
	    "Zwiebel\n",
	    "----------------------------------\n"
	};
	const char *err_txt[] = { };
	// act
	int exit_code = system(XSTR(TARGET) " 1>" OUTFILE " 2>" ERRFILE " <" INFILE_CORRECT);
	// assert
	CU_ASSERT_EQUAL(exit_code, 0);
	assert_lines(OUTFILE, out_txt, sizeof(out_txt)/sizeof(*out_txt));
	assert_lines(ERRFILE, err_txt, sizeof(err_txt)/sizeof(*err_txt));
}

/**
 * @brief Registers and runs the tests.
 */
int main(void)
{
	// setup, run, teardown
	TestMainBasic("Selbststudium 4 - Pointer, Array, Strings", setup, teardown
				  , test_main
				  , test_initialize_array_to_zero
				  , test_array_contains_entry
				  , test_save_word_in_array_new
				  , test_save_word_in_array_existing
				  , test_get_compare_length_first
				  , test_get_compare_length_second
				  , test_sort_word_array
				  );
}
