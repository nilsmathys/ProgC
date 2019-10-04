/* ------------------------------------------------------------------------------
 * title: 		selbstStudium02						-	
 * author: 		Egli Daniela, Iten Fabian				-
 * date:		23/09/2018						-
 * description: 	main Folgetag						-
 --------------------------------------------------------------------------------
 */
 
#include <stdio.h>
#include <stdlib.h>
enum months {
    Jan=1,
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

int is_year_leap_year(int year) {
    if (year >= 1583 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))){
        return 1;
    } else {
        return 0;
    }
}

Date next_Date(Date date) {
    Date next_date = date;
    if (is_year_leap_year(date.year)) {
        if (date.day == 29 && date.month == Feb){
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
    if (date.day == 30 && (date.month == Apr || date.month == Jun || date.month == Sep || date.month == Nov)) {
        next_date.day = 1;
        next_date.month = date.month + 1;
        return next_date;
    }
    if (date.day == 31 && (date.month == Jan|| date.month == Mar || date.month == May || date.month == Jul || date.month == Aug || date.month == Oct || date.month == Dec)) {
        if (date.month == 12) {
            next_date.day = 1;
            next_date.month = 1;
            next_date.year = date.year + 1;
            return next_date;
        } else {
            next_date.day = 1;
            next_date.month = date.month + 1;
            return next_date;
        }
    }
    next_date.day++;
    return next_date;
}

int date_is_Valid(Date date) {
    if ((date.month < 1|| date.month > 12) ||(date.day > 31 && (date.month == Apr || date.month == Jun || date.month == Sep || date.month == Nov)) || (date.day > 30 && (date.month == Apr || date.month == Jun || date.month == Sep || date.month == Nov))||(is_year_leap_year(date.year) && (date.day > 29 && date.month == Feb))|| (is_year_leap_year(date.year) && (date.day > 28 && date.month == Feb))) {
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
    int res = 0;
    if (argc != 4) {
        (void) printf("Please give the date in the form: dd mm yyyy !\n");
        return EXIT_FAILURE;
    }
    res = sscanf(argv[1], "%d", &day);
    if (res != 1) {
        (void) printf("Please give as the first argument the day!\n");
        return EXIT_FAILURE;
    }
    res = sscanf(argv[2], "%d", &month);
    if (res != 1) {
        (void) printf("Please give as the second argument the month!\n");
        return EXIT_FAILURE;
    }
    res = sscanf(argv[3], "%d", &year);
    if (res != 1) {
        (void) printf("Please give as the third argument the year!\n");
        return EXIT_FAILURE;
    }
    Date start_date= {day, month, year};
    if(date_is_Valid(start_date) == 0) {
        Date next_date = next_Date(start_date);
        (void) printf("Date provided:\n");
        (void) printf("%2i %2i %2i\n", start_date.day, start_date.month, start_date.year);
        (void) printf("Next Date:\n");
        (void) printf("%2i %2i %2i\n", next_date.day, next_date.month, next_date.year);
        return EXIT_SUCCESS;
    } else {
        (void) printf("Please give a valid date in the form: dd mm yyyy !\n");
        return EXIT_FAILURE;
    }
}
