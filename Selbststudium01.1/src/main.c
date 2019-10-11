/* ----------------------------------------------------------------------------
 * --  _____       ______  _____                                              -
 * -- |_   _|     |  ____|/ ____|                                             -
 * --   | |  _ __ | |__  | (___    Institute of Embedded Systems              -
 * --   | | | '_ \|  __|  \___ \   Zuercher Hochschule Winterthur             -
 * --  _| |_| | | | |____ ____) |  (University of Applied Sciences)           -
 * -- |_____|_| |_|______|_____/   8401 Winterthur, Switzerland               -
 * ----------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

int main (int argc, char* argv[]) {
	
	if(argc == 2) {
		int erstezahl;
		int check = sscanf(argv[1], "%d", &erstezahl);
		if(check == 1 && erstezahl >= 0 && erstezahl <= 255) {
			uint8_t num = (uint8_t) erstezahl;
			printf("unsigned: %4d (%#04x)\n", num, num);
			uint8_t sinum = (int8_t)num;
			printf("  signed: %4d (%#04x)\n", sinum, sinum);
			uint8_t add = (uint8_t)(num + 255);
			printf("    +255: %4d (%#04x)\n", add, add);
			int8_t onekomp = ~num;
			printf("   one's: %4d (%#04x)\n", onekomp, onekomp );
			int8_t twokomp = ~num+1;
			printf("   two's: %4d (%#04x)\n", twokomp, twokomp);
			return EXIT_SUCCESS;
			
		} else{
			(void)printf("Bitte eine Zahlen im Bereich von 0 bis 255 angeben.\n");
			return EXIT_FAILURE;
		}		
	} else if(argc == 3) {
		int zweitezahl;
		int test = sscanf(argv[2], "%d", &zweitezahl);
		if(test == 1 && zweitezahl >=	0 && zweitezahl <= 7) {
			int erstes_argument;
			int check = sscanf(argv[1], "%d", &erstes_argument);
			if(check == 1 && erstes_argument >= 0 && erstes_argument <= 255) {
				uint8_t first_argu = (uint8_t) erstes_argument;
				uint8_t second_argu = (uint8_t) zweitezahl;
				printf("               dec   hex   oct\n");
				printf("Your input   : %3d  %#04x  %.4o\n", first_argu, first_argu, first_argu);
				
				int bit_set = (first_argu >> second_argu) & 1u;	
				if(bit_set == 1) {
					printf("bit %d is set.\n", second_argu);
						
				} else {
					printf("bit %d is not set.\n", second_argu);
				}
				uint8_t cleared_bit = first_argu & ~(1u << second_argu);
				printf("bit %d cleared: %3d  %#04x  %.4o\n", second_argu, cleared_bit, cleared_bit, cleared_bit);
				uint8_t add_bit = first_argu | 1u << second_argu;
				printf("bit %d set    : %3d  %#04x  %.4o\n", second_argu, add_bit, add_bit, add_bit);
				uint8_t flipped = first_argu ^ 1u << second_argu;
				printf("bit %d flipped: %3d  %#04x  %.4o\n", second_argu, flipped, flipped, flipped);
				return EXIT_SUCCESS;
			
			} else{
				(void)printf("Bitte eine Zahlen im Bereich von 0 bis 255 angeben.\n");

			}	
			
		} else {
			(void)printf("Bitte eine Zahl im Bereich von 0 bis 7 angeben.\n");

		}
	} else {
		(void)printf("Bitte als erstes Arrgument eine Zahl im Berreich 0 bis 255 angeben und als zweites Arrgument eine Zahl vom Berreich 0 bis 7.\n");

	}
    return EXIT_FAILURE;
}


