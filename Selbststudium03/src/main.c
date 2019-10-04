/*
 * title: Selbststudium 03 - Arrays
 * created by Nils Mathys
 * date: 18.09.2019
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "main.h"

int main(int argc, char *argv[]) {
    int points[MAX_LENGTH];
    int userinput = 0;
    int max_points = 0;
    int amount_of_students = 0;

    //liest Noten in einen Array
    while (userinput != -1 && amount_of_students < MAX_LENGTH) {
        (void) printf("Bitte geben Sie eine Punktzahl an. Anzahl bissher eingegebeben Studenten: %d \n",
                      amount_of_students);
        if (scanf("%i", &userinput) == 1) {
            if (userinput < -1) {
                (void) printf("Bitte geben Sie eine positive Punktzahl an.\n");
            } else if (userinput > 0) {
                points[amount_of_students] = userinput;
                amount_of_students++;
            }
        } else {
            (void) printf("Fehler beim lesen des Inputs.\n");
            empty_stdin();
        }
    }
    (void) printf("Bitte geben Sie die Mindestpunktzahl für die Note 6 ein. \n");
    if (scanf("%i", &max_points) != 1) {
        (void) printf("Fehler beim lesen des Inputs.\n");
        return EXIT_FAILURE;
    }
    int *marks = points_to_mark(points, amount_of_students, max_points);
    calculate_statistic(marks, amount_of_students, max_points);
    return EXIT_SUCCESS;
}

/**
 *
 */
void empty_stdin(void) {
    int c = getchar();
    while(c != '\n' && c != EOF) {
        c = getchar();
    }
}

/**
 * @param numbers, array with entered points
 * @param length from array numbers
 * @return average value
 */
double get_average(int numbers[], int length) {
    double sum = 0.0;
    for(int count = 0; count < length; count++) {
        sum += numbers[count];
    }
    return sum / length;
}

/**
 * @param numbers, array with entered points
 * @param length from array numbers
 * @return highest value
 */
int get_highest_number(int numbers[], int length) {
    int highest_value = 0;
    for(int count = 0; count < length; count++) {
        if (numbers[count] > highest_value) {
            highest_value = numbers[count];
        }
    }
    return highest_value;
}

/**
 * @param numbers, array with entered points
 * @param length from array numbers
 * @return lowest value
 */
int get_lowest_number(int numbers[], int length) {
    int lowest_number = 100000;
    for(int count = 0; count < length; count++) {
        if (numbers[count] < lowest_number) {
            lowest_number = numbers[count];
        }
    }
    return lowest_number;
}

/**
 *
 * @param marks, array with marks
 * @param length, length from array marks
 * @param element, element to be compared
 * @return number of identical elements
 */
int amount_same_element_in_array(int marks[], int length, int element) {
    int amount_found = 0;
    for(int count = 0; count < length; count++) {
        if (marks[count] == element) {
            amount_found++;
        }
    }
    return amount_found;
}

/**
 *
 * @param marks, array with marks
 * @param length, length from array marks
 * @param delimeter (Trennzeichen)
 * @return amount of elements above the given delimeter
 */
int amount_above_delimeter(int marks[], int length, int delimeter) {
    int amount_above = 0;
    for(int count = 0; count < length; count++) {
        if (marks[count] >= delimeter) {
            amount_above++;
        }
    }
    return amount_above;
}

/**
 * calculate marks
 * @param points
 * @param length, amount_of_students
 * @param max_points
 * @return marks
 */
int *points_to_mark(int points[], int length, int max_points) {
    int *marks = (int*) malloc(length);
    for(int count = 0; count < length; count++) {
        marks[count] = 1.0 + (5.0 * points[count]) / max_points + 0.5;
        if (marks[count] > 6) {
            marks[count] = 6;
        } else if (marks[count] < 1) {
            marks[count] = 1;
        }
    }
    return marks;
}

/**
 *
* @param marks, array with marks
 * @param length, length from array marks
 * @param max_points
 */
void calculate_statistic(int marks[], int length, int max_points) {
    (void) printf("\n--------------------------------------------------------\n");
    (void) printf("Statistics (%i students, %i points needed for mark 6):\n", length, max_points);
    for (int count = 6; count >= LOWEST_MARK; count--) {
        (void) printf("   Mark %i: %i\n", count, amount_same_element_in_array(marks, length, count));
    }
    (void) printf("\n");
    (void) printf("Best mark:    %5i\n", get_highest_number(marks, length));
    (void) printf("Worst mark:   %5i\n", get_lowest_number(marks, length));
    (void) printf("Average mark: %8.2f\n", get_average(marks, length));
    (void) printf("Mark >= 4: %8i students out of %i (%.2f %%)\n", amount_above_delimeter(marks, length, 4), length,
                  100.0 / length * amount_above_delimeter(marks, length, 4));
    (void) printf("--------------------------------------------------------\n");
}
