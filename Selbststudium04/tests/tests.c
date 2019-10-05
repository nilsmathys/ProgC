/**
 * title: Selbststudium 04 - Pointer, Arrays, Strings
 * created by Nils Mathys
 * date: 25.09.2019
 */
#include <stdio.h>
#include <stdlib.h>
#include "CUnit/Basic.h"
#include "test_utils.h"

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


static void input_output_assert(char input_line[], char output[]) {

    const char *out_lines[] = {output};

    char command[512];
    snprintf(command, 512, "echo '%s' | "
    XSTR(TARGET)
    " 1>" OUTFILE " 2>" ERRFILE, input_line);
    // act
    int exit_code = system(command);
    // assert
    CU_ASSERT_EQUAL(exit_code, 0);

    assert_lines(OUTFILE, out_lines, sizeof(out_lines) / sizeof(*out_lines));
}

// tests
static void test_one_word(void) {
    char input[] = "oneword\n"
                   "ZZZ\n";
    char output[] = "\nSortierte Liste:\n"
                    "---------------------------\n"
                    "oneword\n"
                    "---------------------------\n";
    input_output_assert(input, output);
}

static void test_multiple_words(void) {
    char input[] = "asdf\n"
                   "bsdf\n"
                   "c aasdff\n"
                   "ddasdf\n"
                   "eeadsf\n"
                   "ffasdf\n"
                   "ggasfd\n"
                   "hhadf\n"
                   "wetbjadfgj\n"
                   "ZZZ\n";
    char output[] = "\nSortierte Liste:\n"
                    "---------------------------\n"
                    "aasdff\n"
                    "asdf\n"
                    "bsdf\n"
                    "c\n"
                    "ddasdf\n"
                    "eeadsf\n"
                    "ffasdf\n"
                    "ggasfd\n"
                    "hhadf\n"
                    "wetbjadfgj\n"
                    "---------------------------\n";
    input_output_assert(input, output);
}

static void test_numbers(void) {
    char input[] = "03\n"
                   "05\n"
                   "01\n"
                   "1\n"
                   "001\n"
                   "ZZZ\n";
    char output[] = "\nSortierte Liste:\n"
                    "---------------------------\n"
                    "001\n"
                    "01\n"
                    "03\n"
                    "05\n"
                    "1\n"
                    "---------------------------\n";
    input_output_assert(input, output);
}

static void test_already_sorted(void) {
    char input[] = "a\n"
                   "b\n"
                   "c\n"
                   "ZZZ\n";
    char output[] =  "\nSortierte Liste:\n"
                     "---------------------------\n"
                     "a\n"
                     "b\n"
                     "c\n"
                     "---------------------------\n";
    input_output_assert(input, output);
}

static void test_input_validation(void) {
    int exit_code = system(XSTR(TARGET)
    "1>/dev/null 2>/dev/null </dev/null"); // no input
    // assert
    CU_ASSERT_NOT_EQUAL(exit_code, 0);
}

static void test_duplicates(void) {
    char input[] = "a\n"
                   "a\n"
                   "b\n"
                   "b\n"
                   "ZZZ\n";
    char output[] = "\nSortierte Liste:\n"
                    "---------------------------\n"
                    "a\n"
                    "b\n"
                    "---------------------------\n";
    input_output_assert(input, output);
}


/**
 * @brief Registers and runs the tests.
 * @returns Returns EXIT_SUCCESS (=0) on success,
 *                  EXIT_FAILURE (=1) if more than one argument is given.
 */
int main(void) {
    // setup, run, teardown
    TestMainBasic("SortWordsTest",
                  setup,
                  teardown,
                  test_one_word,
                  test_multiple_words,
                  test_numbers,
                  test_already_sorted,
                  test_input_validation,
                  test_duplicates
    );
}