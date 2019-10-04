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
// begin students to add code for task 4.1
#include "read.h"
#include <stdio.h>
#include "trace.h"

int getInt(int maxResult) {
	TRACE("getInt(%i)\n", maxResult);
	char buffer[BUFFERSIZE];
	int result = 0;
	int bytes = 0;
	int input = getchar();
	while ((input != EOL) && (input != EOF)) {
		if(bytes < BUFFERSIZE) {
			buffer[bytes] = (char)input;
			bytes++;
		} else {
			result = PARSE_ERROR;
		}
		input = getchar();
	}
	if (input == EOF) {
		result = READ_ERROR;
	}
	int pos = 0;
	while((pos < bytes) && (buffer[pos] <= ASCII_SPACE)) pos++;
	int posOfFirstDigit = pos;
	int posOfLastDigit = NO_POS;
	while ((pos < bytes) && (buffer[pos] >= ASCII_DIGIT_0) && (buffer[pos] <= ASCII_DIGIT_9)) {
		posOfLastDigit = pos;
		pos++;
	}
	while((pos < bytes) && (buffer[pos] <= ASCII_SPACE)) pos++;
	if (result != 0) {
	
	} else if((pos != bytes) || (posOfLastDigit == NO_POS)) {
		result = PARSE_ERROR;
	} else {
		for(int i = posOfFirstDigit; i <= posOfLastDigit; i++) {
			result = result * 10 + (buffer[i] - ASCII_DIGIT_0);
			if (result > maxResult) {
				result = PARSE_ERROR;
				break;
			}
		}
	}

return result;
}

// end students to add code
