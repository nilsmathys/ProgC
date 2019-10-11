/* ------------------------------------------------------------------------------
 * title: 	test Selbststudium01.2			                	-
 * author:  Nils Mathys				      	-
 * date:    29.09.2019				                        -
 * description: test for Selbststudium01.2		                -
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
#define INFILE_Test "stim-test.input"
#define INFILE_Test1 "stim-test1.input"
#define INFILE_Test_with_tab "stim-test-with-tab.input"
#define INFILE_Test_with_space "stim-test-with-space.input"

static int setup(void) {
    remove_file_if_exists(OUTFILE);
    remove_file_if_exists(ERRFILE);
    return 0;
}

static int teardown(void) {
    return 0;
}


static void test_main_with_test(void) {
    const char *out_txt[] = {
                                "Eingabe: ",
                                "Anzahl Zeichen: 4\n",
                                "Anzahl Woerter: 1\n",
                            };
    int exit_code = system(XSTR(TARGET) " 1>" OUTFILE " 2>" ERRFILE " <" INFILE_Test);
    CU_ASSERT_EQUAL(exit_code, 0);
    assert_lines(OUTFILE, out_txt, sizeof(out_txt)/sizeof(*out_txt));
}

static void test_main_with_test_test_test(void) {
    const char *out_txt[] = {
                                "Eingabe: ",
                                "Anzahl Zeichen: 14\n",
                                "Anzahl Woerter: 3\n",
                            };
    int exit_code = system(XSTR(TARGET) " 1>" OUTFILE " 2>" ERRFILE " <" INFILE_Test1);
    CU_ASSERT_EQUAL(exit_code, 0);
    assert_lines(OUTFILE, out_txt, sizeof(out_txt)/sizeof(*out_txt));
}

static void test_main_with_tab(void) {
    const char *out_txt[] = {
                                "Eingabe: ",
                                "Anzahl Zeichen: 5\n",
                                "Anzahl Woerter: 1\n",
                            };
    int exit_code = system(XSTR(TARGET) " 1>" OUTFILE " 2>" ERRFILE " <" INFILE_Test_with_tab);
    CU_ASSERT_EQUAL(exit_code, 0);
    assert_lines(OUTFILE, out_txt, sizeof(out_txt)/sizeof(*out_txt));
}

static void test_main_with_space(void) {
    const char *out_txt[] = {
                                "Eingabe: ",
                                "Anzahl Zeichen: 5\n",
                                "Anzahl Woerter: 1\n",
                            };
    int exit_code = system(XSTR(TARGET) " 1>" OUTFILE " 2>" ERRFILE " <" INFILE_Test_with_space);
    CU_ASSERT_EQUAL(exit_code, 0);
    assert_lines(OUTFILE, out_txt, sizeof(out_txt)/sizeof(*out_txt));
}




int main(void) {
    TestMainBasic("Zaehlen_von_Zeichen_und_Woertern",
            setup,
            teardown,
            test_main_with_test,
            test_main_with_test_test_test,
            test_main_with_tab,
            test_main_with_space
    );
}
