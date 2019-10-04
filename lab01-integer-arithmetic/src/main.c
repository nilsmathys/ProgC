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

/**
 * @brief Main entry point.
 * @param[in] argc  The size of the argv array.
 * @param[in] argv  The command line arguments
 *                  with argv[0] being the command call
 *                  argv[1] the 1st argument, ...
 *                  argv[argc-1] the last argument.
 * @returns Returns the rest of the calculation or
 *                  255 on failure
 */
int main(int argc, char* argv[])
{
	int rappen = 0;
	// begin students to add code for task 4.2
	if(argc == 2) {
		int eingabe_ok = sscanf(argv[1], "%d", &rappen);
		if(eingabe_ok == 1 && rappen > 0) {
			double franken = rappen / 100.0;
			(void)printf ("CHF %.2f:\n", franken);
			int fuenf_franken = rappen / 500;
			double zwischenstand = rappen - fuenf_franken * 500;
			int zwei_franken = zwischenstand / 200;
			zwischenstand = zwischenstand - zwei_franken*200;
			int ein_franken = zwischenstand / 100;
			zwischenstand = zwischenstand - ein_franken * 100;
			int fuenfzig_rappen = zwischenstand /50;
			zwischenstand = zwischenstand - fuenfzig_rappen * 50;
			int zwanzig_rappen = zwischenstand /20;
			zwischenstand = zwischenstand - zwanzig_rappen * 20;
			int zehn_rappen = zwischenstand /10;
			zwischenstand = zwischenstand - zehn_rappen * 10;
			int fuenf_rappen = zwischenstand /5;
			double rest = (zwischenstand - fuenf_rappen*5)/100.0;

			(void)printf("- %d x 5.00\n", fuenf_franken);
			(void)printf("- %d x 2.00\n", zwei_franken);
			(void)printf("- %d x 1.00\n", ein_franken);
			(void)printf("- %d x 0.50\n", fuenfzig_rappen);
			(void)printf("- %d x 0.20\n", zwanzig_rappen);
			(void)printf("- %d x 0.10\n", zehn_rappen);
			(void)printf("- %d x 0.05\n", fuenf_rappen);
			if(rest == 0) {
				(void)printf("Kein Rest\n");
			} else {
				(void)printf("Rest = %.2f\n", rest);
			}
			int rest_in_rappen = rest*100;
			return rest_in_rappen;

			
		} else {
			(void)printf("Bitte Eingabe überprüfen!\n");
			return 255;
		}			
	}
	else {
		(void)printf("Bitte gültigen Betrag angeben\n");
		return 255;
	}
	
	// end students to add code
	return rappen; // rest = 0 = success
}
