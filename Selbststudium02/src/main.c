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
enum months {
    Jan = 1,
    Feb,
    Mar,
    Apr,
    May,
    Jun,
    Jul,
    Aug,
    Sep,
    Oct,
    Nov,
    Dec
};

typedef struct {
    int day;
    int month;
    int year;
} Date;

int schaltjahr(int year) {
    if(year >= 1583 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))) {
        return 1;
    } else {
        return 0;
    };
}

Date next_Date(Date date) {
    Date next_date = date;
    if(schaltjahr(date.year)) {
        if(date.day == 29 && date.month == Feb) {
            next_date.day = 1;
            next_date.month = date.month + 1;
            return next_date;
        }
    } else {
        if (date.day == 28 && date.month == Feb) {
            next_date.day = 1;
            next_date.month = date.month + 1;
            return next_date;
        }
    }
    if(date.day == 30 && (date.month == Apr || date.month == Jun || date.month == Sep || date.month == Nov)) {
        next_date.day = 1;
        next_date.month = date.month +1;
        return next_date;
    }
    if (date.day == 31 && (date.month == Jan || date.month == Mar || date.month == May || date.month == Jul || date.month == Aug || date.month == Oct || date.month == Dec)) {
        if(date.month == 12) {
            next_date.day = 1;
            next_date.month = 1;
            next_date.year = date.year + 1;
            return next_date;
        } else {
            next_date.day = 1;
            next_date.month = date.month +1;
            return next_date;
        }
    }
    next_date.day++;
    return next_date;
}

int valid_date(Date date) {
    if ((date.month < 1|| date.month > 12) ||(date.day > 31 && (date.month == Apr || date.month == Jun || date.month == Sep || date.month == Nov)) || (date.day > 30 && (date.month == Apr || date.month == Jun || date.month == Sep || date.month == Nov))||(schaltjahr(date.year) && (date.day > 29 && date.month == Feb))|| (schaltjahr(date.year) && (date.day > 28 && date.month == Feb))) {
        return 1;
    } else {
        return 0;
    }
}

int main(int argc, char* argv[])
{
    int day = 0;
    int month = 0;
    int year = 0;
    int result = 0;
    if(argc != 4) {
        (void) printf("Bitte gebe das Datum in der Form: \"dd mm yyyy\" ein.\n");
        return EXIT_FAILURE;
    }
    result = sscanf(argv[1], "%d", &day);
    if(result != 1) {
        (void) printf("Bitte gebe als erstes Argument den Tag in der Form \"dd\" mit.\n");
        return EXIT_FAILURE;
    }
    result = sscanf(argv[2], "%d", &month);
    if(result != 1) {
        (void)printf("Bitte gebe als zweites Argument den Monat in der Form \"mm\" mit.\n");
        return EXIT_FAILURE;
    }
    result = sscanf(argv[3], "%d", &year);
    if(result != 1) {
        (void)printf("Bitte gebe als drittes Argument das Jahr in der Form \"yyyy\" mit.\n");
        return EXIT_FAILURE;
    }
    Date start_date = {day, month, year};
    if(valid_date(start_date) == 0) {
        Date next_date = next_Date(start_date);
        (void) printf("Eingegebenes Datum:\n");
        (void) printf("%2i %2i %2i\n", start_date.day, start_date.month, start_date.year);
        (void) printf("Folgetag:\n");
        (void) printf("%2i %2i %2i\n", next_date.day, next_date.month, next_date.year);
        return EXIT_SUCCESS;
    } else {
        (void) printf("Bitte gebe ein gültiges Datum in der Form: \"dd mm yyyy\" ein.\n");
        return EXIT_FAILURE;
    }
}



