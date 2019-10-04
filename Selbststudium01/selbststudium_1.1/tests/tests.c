/* ------------------------------------------------------------------------------
 * title: 	test selbststudium_1.1			                	-
 * author:  Nils Mathys				      	-
 * date:    29.09.2019				                        -
 * description: test for selbststudium_1.1		                -
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


static int setup(void)
{
remove_file_if_exists(OUTFILE);
remove_file_if_exists(ERRFILE);
return 0; 
}

static int teardown(void)
{
return 0; 
}


static void test_main_with_no_arg(void)
{
const char *out_txt[] = { "give only one or two arguments!\n" };
int exit_code = system(XSTR(TARGET) " 1>" OUTFILE " 2>" ERRFILE);
CU_ASSERT_EQUAL(exit_code, 1 << 8);
}

static void test_main_with_three_arg(void)
{
const char *out_txt[] = { "give only one or two arguments!\n" };
int exit_code = system(XSTR(TARGET) " 255 255 255 1>" OUTFILE " 2>" ERRFILE);
CU_ASSERT_EQUAL(exit_code, 1 << 8);
}
static void test_main_with_non_numeric_at_second_input_arg(void)
{
const char *out_txt[] = { "please give a number as second input!\n"};
int exit_code = system(XSTR(TARGET) " 1 test 1>" OUTFILE " 2>" ERRFILE);
CU_ASSERT_EQUAL(exit_code, 1 << 8);
}
static void test_main_with_non_numeric_arg(void)
{
const char *out_txt[] = { "please give a number!\n" };
int exit_code = system(XSTR(TARGET) " test 1>" OUTFILE " 2>" ERRFILE);
CU_ASSERT_EQUAL(exit_code, 1 << 8);
}
static void test_main_with_invalid_number_negativ_arg(void)
{
const char *out_txt[] = { "give a number between 0 and 255!\n" };
int exit_code = system(XSTR(TARGET) " -1 1>" OUTFILE " 2>" ERRFILE);
CU_ASSERT_EQUAL(exit_code, 1 << 8);
}
static void test_main_with_invalid_number_at_second_input_negativ_arg(void)
{
const char *out_txt[] = { "give a number between 0 and 7 as second input!\n" };
int exit_code = system(XSTR(TARGET) " 255 -1 1>" OUTFILE " 2>" ERRFILE);
CU_ASSERT_EQUAL(exit_code, 1 << 8);
}
static void test_main_with_invalid_number_high_arg(void)
{
const char *out_txt[] = { "give a number between 0 and 255!\n" };
int exit_code = system(XSTR(TARGET) " 256 1>" OUTFILE " 2>" ERRFILE);
CU_ASSERT_EQUAL(exit_code, 1 << 8);
}
static void test_main_with_invalid_number_at_second_input_high_arg(void)
{
const char *out_txt[] = { "give a number between 0 and 7 as second input!\n" };
int exit_code = system(XSTR(TARGET) " 255 8 1>" OUTFILE " 2>" ERRFILE);
CU_ASSERT_EQUAL(exit_code, 1 << 8);
}

static void test_main_with_13(void)
{
const char *out_txt[] = {
"Integer-Arithmetik\n",
"unsigned:   13 (0x0d)\n",
"  signed:   13 (0x0d)\n",
"    +255:   12 (0x0c)\n",
"   one's:  -14 (0xf2)\n",
"   two's:  -13 (0xf3)\n"};
int exit_code = system(XSTR(TARGET) " 13 1>" OUTFILE " 2>" ERRFILE);
CU_ASSERT_EQUAL(exit_code, 0);
assert_lines(OUTFILE, out_txt, sizeof(out_txt)/sizeof(*out_txt));
}

static void test_main_with_129(void)
{
const char *out_txt[] = {
"Integer-Arithmetik\n",
"unsigned:  129 (0x81)\n",
"  signed: -127 (0x81)\n",
"    +255: -128 (0x80)\n",
"   one's:  126 (0x7e)\n",
"   two's:  127 (0x7f)\n"};
int exit_code = system(XSTR(TARGET) " 129 1>" OUTFILE " 2>" ERRFILE);
CU_ASSERT_EQUAL(exit_code, 0);
assert_lines(OUTFILE, out_txt, sizeof(out_txt)/sizeof(*out_txt));
}

static void test_main_with_131_and_2(void)
{
const char *out_txt[] = {
"Integer-Arithmetik\n",
"unsigned:  131 (0x83)\n",
"  signed: -125 (0x83)\n",
"    +255: -126 (0x82)\n",
"   one's:  124 (0x7c)\n",
"   two's:  125 (0x7d)\n",
"Bit-Manipulation\n",
"                     dec  hex   oct\n",
"Your input        :  131  0x83  0203\n",
"bit 2 is not set.\n",
"bit 2 cleared     :  131  0x83  0203\n",
"bit 2 set         :  135  0x87  0207\n",
"bit 2 flipped     :  135  0x87  0207\n"};
int exit_code = system(XSTR(TARGET) " 131 2 1>" OUTFILE " 2>" ERRFILE);
CU_ASSERT_EQUAL(exit_code, 0);
assert_lines(OUTFILE, out_txt, sizeof(out_txt)/sizeof(*out_txt));
}

static void test_main_with_1_and_0(void)
{
const char *out_txt[] = {
"Integer-Arithmetik\n",
"unsigned:    1 (0x01)\n",
"  signed:    1 (0x01)\n",
"    +255:    0 (0x00)\n",
"   one's:   -2 (0xfe)\n",
"   two's:   -1 (0xff)\n",
"Bit-Manipulation\n",
"                     dec  hex   oct\n",
"Your input        :    1  0x01  0001\n",
"bit 0 is set.\n",
"bit 0 cleared     :    0  0x00  0000\n",
"bit 0 set         :    1  0x01  0001\n",
"bit 0 flipped     :    0  0x00  0000\n"};
int exit_code = system(XSTR(TARGET) " 1 0 1>" OUTFILE " 2>" ERRFILE);
CU_ASSERT_EQUAL(exit_code, 0);
assert_lines(OUTFILE, out_txt, sizeof(out_txt)/sizeof(*out_txt));
}

int main(void)
{
TestMainBasic("Integer Arithmetik", setup, teardown
,test_main_with_no_arg
,test_main_with_three_arg
,test_main_with_non_numeric_arg
,test_main_with_non_numeric_at_second_input_arg
,test_main_with_invalid_number_negativ_arg
,test_main_with_invalid_number_high_arg
,test_main_with_invalid_number_at_second_input_high_arg
,test_main_with_13
,test_main_with_129
,test_main_with_131_and_2
,test_main_with_1_and_0
);
}
