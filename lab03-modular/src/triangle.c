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
#include "read.h"
#include "rectang.h"
#include "trace.h"

/// max side length
#define READ_ERROR -2
#define MAX_NUMBER 1000


/**
 * @brief Main entry point.
 * @returns Returns EXIT_SUCCESS (=0) on success, EXIT_FAILURE (=1) on failure.
 */
int main(void)
{
	TRACE("main()\n");
	// begin students to add code for task 4.1
	while (1) {
	(void)printf("\nDreiecksbestimmung (CTRL-C: Abbruch)\n\n");

	int word = 0;
	int a = 0;
	int b = 0;
	int c = 0;

	do {
		(void)printf("Seite a: ");
		word = getInt(MAX_NUMBER);
	}
	while ((word < 0) && (word != READ_ERROR));
	if (word >= 0)
		a = word;
	else
		break;
	do {
		(void)printf("Seite b: ");
		word = getInt(MAX_NUMBER);
	}
	while ((word < 0) && (word != READ_ERROR));
	if (word >= 0)
		b = word;
	else
		break;

	do {
		(void)printf("Seite c: ");
		word = getInt(MAX_NUMBER);
	}
	while ((word < 0) && (word != READ_ERROR));
	if(word >= 0)
		c = word;
	else
		break;
	if (rectangular(a, b, c) == 1)
		(void)printf("-> Dreieck %i-%i-%i ist rechtwinklig\n", a,b,c);
	else 
		(void)printf("-> Dreieck %i-%i-%i ist nicht rechtwinklig\n", a,b,c);
	(void)printf("\n\n");
	}
	(void)printf("\n\nbye bye\n\n");	
	// end students to add code
    return EXIT_SUCCESS;
}
