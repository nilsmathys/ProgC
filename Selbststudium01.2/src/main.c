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
	

	printf("Eingabe: ");
	int input = getchar();
	char letztes_zeichen = ' ';
	int anzahl_zeichen = 0;
	int anzahl_woerter = 0;
	while (input != '\n') {
		anzahl_zeichen++;
		if((letztes_zeichen == ' ' || letztes_zeichen == '\t') && input != ' ' && input != '\t' ) {
			anzahl_woerter++;
		}
		letztes_zeichen = input;
		input = getchar();
	}


	
	printf("Anzahl Zeichen: %i\n", anzahl_zeichen);
	printf("Anzahl Wörter: %i\n", anzahl_woerter);

}


