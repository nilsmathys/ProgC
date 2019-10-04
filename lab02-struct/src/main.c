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
// begin students to add code for task 4.1
typedef struct {
		double x;
		double y;	
	} Point;
// end students to add code


/**
 * @brief Main entry point.
 * @param[in] argc  The size of the argv array.
 * @param[in] argv  The command line arguments,
 *                  with argv[0] being the command call,
 *                  argv[1] the 1st argument,
 *                  argv[argc-1] the last argument.
 * @returns Returns EXIT_SUCCESS (=0) on success.
 */
int main(int argc, char* argv[])
{
	double distance = 0.0;

	// begin students to add code for task 4.1
	if(argc != 5) {
		return EXIT_FAILURE;
	
	} 
	Point p1 = {0.0, 0.0};
	Point p2 = {0.0, 0.0};
	// parse arguments with error handling
	int check1 = sscanf(argv[1], "%lf", &p1.x);
	int check2 = sscanf(argv[2], "%lf", &p1.y);
	int check3 = sscanf(argv[3], "%lf", &p2.x);
	int check4 = sscanf(argv[4], "%lf", &p2.y);
	if(check1 != 1 || check2 != 1 || check3 != 1 || check4 != 1) {
		return EXIT_FAILURE;
	}

	// make two point variable p1 and p2 from the parsed arguments
	
	// calcuate the dx and dy values

	// calculate distance form dx and dy values
	double lengthx;
	double lengthy;
	if(p1.x > p2.x) {
	lengthx = p1.x - p2.x;
	} else {
	lengthx = p2.x - p1.x;
	}
	if(p1.y > p2.x) {
	lengthy = p1.y - p2.y;
	} else {
	lengthy = p2.y - p1.y;
	}

	distance = sqrt(lengthx * lengthx + lengthy * lengthy);
	// end students to add code

	(void)printf("distance = %g\n", distance);
	
	return EXIT_SUCCESS;
}
