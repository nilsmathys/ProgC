/* ------------------------------------------------------------------------------
 * title: 	test Selbststudium01.1			                	-
 * author:  Nils Mathys				      	-
 * date:    29.09.2019				                        -
 * description: test for Selbststudium01.1		                -
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


static void test_main_with_no_arg(void) {
    const char *out_txt[] = { "Bitte als erstes Arrgument eine Zahl im Berreich 0 bis 255 angeben und als zweites Arrgument eine Zahl vom Berreich 0 bis 7.\n" };
    int exit_code = system(XSTR(TARGET) " 1>" OUTFILE " 2>" ERRFILE);
    CU_ASSERT_EQUAL(exit_code, 1 << 8);
}

static void test_main_with_three_arg(void) {
    const char *out_txt[] = { "Bitte als erstes Arrgument eine Zahl im Berreich 0 bis 255 angeben und als zweites Arrgument eine Zahl vom Berreich 0 bis 7.\n" };
    int exit_code = system(XSTR(TARGET) " 1 2 3 1>" OUTFILE " 2>" ERRFILE);
    CU_ASSERT_EQUAL(exit_code, 1 << 8);
}

static void test_main_with_non_numeric_at_second_input_arg(void) {
    const char *out_txt[] = { "Bitte eine Zahl im Bereich von 0 bis 7 angeben.\n"};
    int exit_code = system(XSTR(TARGET) " 1 a 1>" OUTFILE " 2>" ERRFILE);
    CU_ASSERT_EQUAL(exit_code, 1 << 8);
}

static void test_main_with_non_numeric_arg(void) {
    const char *out_txt[] = { "Bitte eine Zahlen im Bereich von 0 bis 255 angeben.\n" };
    int exit_code = system(XSTR(TARGET) " a 1>" OUTFILE " 2>" ERRFILE);
    CU_ASSERT_EQUAL(exit_code, 1 << 8);
}

static void test_main_with_invalid_number_negativ_arg(void) {
    const char *out_txt[] = { "Bitte eine Zahlen im Bereich von 0 bis 255 angeben.\n" };
    int exit_code = system(XSTR(TARGET) " -5 1>" OUTFILE " 2>" ERRFILE);
    CU_ASSERT_EQUAL(exit_code, 1 << 8);
}

static void test_main_with_invalid_number_at_second_input_negativ_arg(void) {
    const char *out_txt[] = { "Bitte eine Zahl im Bereich von 0 bis 7 angeben.\n" };
    int exit_code = system(XSTR(TARGET) " 1 -5 1>" OUTFILE " 2>" ERRFILE);
    CU_ASSERT_EQUAL(exit_code, 1 << 8);
}

static void test_main_with_invalid_number_high_arg(void) {
    const char *out_txt[] = { "Bitte eine Zahlen im Bereich von 0 bis 255 angeben.\n" };
    int exit_code = system(XSTR(TARGET) " 256 1>" OUTFILE " 2>" ERRFILE);
    CU_ASSERT_EQUAL(exit_code, 1 << 8);
}

static void test_main_with_invalid_number_at_second_input_high_arg(void) {
    const char *out_txt[] = { "Bitte eine Zahl im Bereich von 0 bis 7 angeben.\n" };
    int exit_code = system(XSTR(TARGET) " 1 8 1>" OUTFILE " 2>" ERRFILE);
    CU_ASSERT_EQUAL(exit_code, 1 << 8);
}

static void test_main_with_10(void) {
    const char *out_txt[] = {
                                "unsigned:   10 (0x0a)\n",
                                "  signed:   10 (0x0a)\n",
                                "    +255:    9 (0x09)\n",
                                "   one's:  -11 (0xfffffff5)\n",
                                "   two's:  -10 (0xfffffff6)\n"
                            };
    int exit_code = system(XSTR(TARGET) " 10 1>" OUTFILE " 2>" ERRFILE);
    CU_ASSERT_EQUAL(exit_code, 0);
    assert_lines(OUTFILE, out_txt, sizeof(out_txt)/sizeof(*out_txt));
}
static void test_main_with_139(void) {
    const char *out_txt[] = {
                                "unsigned:  139 (0x8b)\n",
                                "  signed:  139 (0x8b)\n",
                                "    +255:  138 (0x8a)\n",
                                "   one's:  116 (0x74)\n",
                                "   two's:  117 (0x75)\n"
                            };
    int exit_code = system(XSTR(TARGET) " 139 1>" OUTFILE " 2>" ERRFILE);
    CU_ASSERT_EQUAL(exit_code, 0);
    assert_lines(OUTFILE, out_txt, sizeof(out_txt)/sizeof(*out_txt));
}

static void test_main_with_112_and_5(void) {
    const char *out_txt[] = {
                                "               dec   hex   oct\n",
                                "Your input   : 112  0x70  0160\n",
                                "bit 5 is set.\n"
                                "bit 5 cleared:  80  0x50  0120\n",
                                "bit 5 set    : 112  0x70  0160\n",
                                "bit 5 flipped:  80  0x50  0120\n"
                             };
    int exit_code = system(XSTR(TARGET) " 112 5 1>" OUTFILE " 2>" ERRFILE);
    CU_ASSERT_EQUAL(exit_code, 0);
    assert_lines(OUTFILE, out_txt, sizeof(out_txt)/sizeof(*out_txt));
}

static void test_main_with_1_and_0(void) {
    const char *out_txt[] = {
                                "               dec   hex   oct\n",
                                "Your input   :   1  0x01  0001\n",
                                "bit 0 is set.\n",
                                "bit 0 cleared:   0  0000  0000\n",
                                "bit 0 set    :   1  0x01  0001\n",
                                "bit 0 flipped:   0  0000  0000\n"
                            };
    int exit_code = system(XSTR(TARGET) " 1 0 1>" OUTFILE " 2>" ERRFILE);
    CU_ASSERT_EQUAL(exit_code, 0);
    assert_lines(OUTFILE, out_txt, sizeof(out_txt)/sizeof(*out_txt));
}

int main(void)
{
    TestMainBasic("Integer Arithmetik",
            setup,
            teardown,
            test_main_with_no_arg,
            test_main_with_three_arg,
            test_main_with_non_numeric_at_second_input_arg,
            test_main_with_non_numeric_arg,
            test_main_with_invalid_number_negativ_arg,
            test_main_with_invalid_number_at_second_input_negativ_arg,
            test_main_with_invalid_number_high_arg,
            test_main_with_invalid_number_at_second_input_high_arg,
            test_main_with_10,
            test_main_with_139,
            test_main_with_112_and_5,
            test_main_with_1_and_0
    );
}

///**
// * title: test Selbststudium 01.1
// * created by Nils Mathys
// * date: 08.10.2019
// */
//#include <stdio.h>
//#include <stdlib.h>
//#include "CUnit/Basic.h"
//#include "test_utils.h"
//
//#ifndef TARGET // must be given by the make file --> see test target
//#error missing TARGET define
//#endif
//
///// @brief The name of the STDOUT text file.
//#define OUTFILE "stdout.txt"
///// @brief The name of the STDERR text file.
//#define ERRFILE "stderr.txt"
///// @brief The name of the temp file for STDIN.
//#define INFILE "stdin.txt"
//
//// setup & cleanup
//static int setup(void) {
//    remove_file_if_exists(OUTFILE);
//    remove_file_if_exists(ERRFILE);
//    remove_file_if_exists(INFILE);
//    return 0; // success
//}
//
//static int teardown(void) {
//    // Do nothing.
//    // Especially: do not remove result files - they are removed in int setup(void) *before* running a test.
//    return 0; // success
//}
//
//
//static void input_output_assert(char input_line[], char output[]) {
//
//    const char *out_lines[] = {output};
//
//    char command[512];
//    snprintf(command, 512, "echo '%s' | "
//    XSTR(TARGET)
//    " 1>" OUTFILE " 2>" ERRFILE, input_line);
//    // act
//    int exit_code = system(command);
//    // assert
//    CU_ASSERT_EQUAL(exit_code, 0);
//
//    assert_lines(OUTFILE, out_lines, sizeof(out_lines) / sizeof(*out_lines));
//}
//
//static void test_with_no_args(void) {
//    int exit_code = system(XSTR(TARGET)
//    "1>/dev/null 2>/dev/null </dev/null"); // no input
//    // assert
//    CU_ASSERT_NOT_EQUAL(exit_code, 0);
//}
//
//static void test_with_three_args(void) {
//    char input[] = "1 2 3\n";
//    char output[] = "Bitte als erstes Arrgument eine Zahl im Berreich 0 bis 255 angeben und als zweites Arrgument eine Zahl vom Berreich 0 bis 7.";
//    input_output_assert(input, output);
//}
//
//static void test_with_non_numeric_arg(void) {
//    char input[] = "a\n";
//    char output[] = "Bitte eine Zahlen im Bereich von 0 bis 255 angeben.";
//    input_output_assert(input, output);
//}
//
//static void test_main_with_non_numeric_at_second_input_arg(void) {
//    char input[] = "a b\n";
//    char output[] = "Bitte eine Zahl im Bereich von 0 bis 7 angeben.";
//    input_output_assert(input, output);
//}
//
//static void test_main_with_invalid_number_negativ_arg(void) {
//    char input[] = "-5\n";
//    char output[] = "Bitte eine Zahlen im Bereich von 0 bis 255 angeben.";
//    input_output_assert(input, output);
//}
//
//static void test_main_with_invalid_number_high_arg(void) {
//    char input[] = "256\n";
//    char output[] = "Bitte eine Zahlen im Bereich von 0 bis 255 angeben.";
//    input_output_assert(input, output);
//}
//
//static void test_main_with_10(void) {
//    char input[] = "10\n";
//    char output[] = "unsigned:   10 (0x0a)\n"
//                    "  signed:   10 (0x0a)\n"
//                    "    +255:    9 (0x09)\n"
//                    "   one's:  -11 (0xfffffff5)\n"
//                    "   two's:  -10 (0xfffffff6)\n";
//    input_output_assert(input, output);
//}
//
//
//static void test_main_with_139(void) {
//    char input[] = "139\n";
//    char output[] = "unsigned:  139 (0x8b)\n"
//                    "  signed:  139 (0x8b)\n"
//                    "    +255:  138 (0x8a)\n"
//                    "   one's:  116 (0x74)\n"
//                    "   two's:  117 (0x75)\n";
//    input_output_assert(input, output);
//}
//
//static void test_main_with_invalid_number_at_second_input_high_arg(void) {
//    char input[] = "10 8\n";
//    char output[] = "Bitte eine Zahl im Bereich von 0 bis 7 angeben.";
//    input_output_assert(input, output);
//}
//
//
//static void test_main_with_112_and_4(void) {
//    char input[] = "112 4\n";
//    char output[] = "               dec   hex   oct\n"
//                    "Your input   : 112  0x70  0160\n"
//                    "bit 4 is set.\n"
//                    "bit 4 cleared:  96  0x60  0140\n"
//                    "bit 4 set    : 112  0x70  0160\n"
//                    "bit 4 flipped:  96  0x60  0140\n";
//    input_output_assert(input, output);
//}
//
//static void test_main_with_1_and_0(void) {
//    char input[] = "1 0\n";
//    char output[] = "               dec   hex   oct\n"
//                    "Your input   :   1  0x01  0001\n"
//                    "bit 0 is set.\n"
//                    "bit 0 cleared:   0  0000  0000\n"
//                    "bit 0 set    :   1  0x01  0001\n"
//                    "bit 0 flipped:   0  0000  0000\n";
//    input_output_assert(input, output);
//}
//
///**
// * @brief Registers and runs the tests.
// * @returns Returns EXIT_SUCCESS (=0) on success,
// *                  EXIT_FAILURE (=1) if more than one argument is given.
// */
//int main(void) {
//    // setup, run, teardown
//    TestMainBasic("IntegerArithmetikTest",
//                  setup,
//                  teardown,
//                  test_with_no_args,
//                  test_with_three_args,
//                  test_with_non_numeric_arg,
//                  test_main_with_non_numeric_at_second_input_arg,
//                  test_main_with_invalid_number_negativ_arg,
//                  test_main_with_invalid_number_high_arg,
//                  test_main_with_10,
//                  test_main_with_139,
//                  test_main_with_invalid_number_at_second_input_high_arg,
//                  test_main_with_112_and_4,
//                  test_main_with_1_and_0
//    );
//}

