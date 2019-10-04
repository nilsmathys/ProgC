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
 * @brief Lab implementation
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief  point structure of double coordinates
 */
// begin students to add code for task 4.2
typedef struct {
		double x;
		double y;	
	} Point;
// end students to add code

/**
 * line structure of two points
 */
// begin students to add code for task 4.2
typedef struct {
		Point p1;
		Point p2;	
	} Line;
// end students to add code

/**
 * @brief Main entry point.
 * @param[in] argc  The size of the argv array.
 * @param[in] argv  The command line arguments,
 *                  with argv[0] being the command call,
 *                  argv[1] the 1st argument,
 *                  argv[argc-1] the last argument.
 * @returns Returns EXIT_SUCCESS (=0) on success and
 *                  EXIT_FAILURE (=1) on error.
 */
int main(int argc, char* argv[])
{
	// begin students to add code for task 4.2
	if(argc != 5) {
		return EXIT_FAILURE;
	
	} 
	Line l1 = {};
	// parse arguments with error handling
	int check1 = sscanf(argv[1], "%lf", &l1.p1.x);
	int check2 = sscanf(argv[2], "%lf", &l1.p1.y);
	int check3 = sscanf(argv[3], "%lf", &l1.p2.x);
	int check4 = sscanf(argv[4], "%lf", &l1.p2.y);
	if(check1 != 1 || check2 != 1 || check3 != 1 || check4 != 1) {
		return EXIT_FAILURE;
	}
	

	// parse arguments with error handling

	// make one line variable an initialize from the parsed arguments

	// print the line variable in the following format: 
		(void)printf("line %g/%g-%g/%g\n", l1.p1.x, l1.p1.y, l1.p2.x, l1.p2.y);


	// end students to add code
	
	return EXIT_SUCCESS;
}
