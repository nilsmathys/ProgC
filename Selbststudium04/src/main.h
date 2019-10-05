/** @file main.h
 *  @brief Main header to declare multiple function.
 *
 *  @authors Mika Ruch, Carlo Field, Tobias Zischler
 */
#ifndef DEV_MAIN_H
#define DEV_MAIN_H

/// @brief size of words
#define WORDLIST_COUNT 100


int already_exist(char *word, char *words[], int size);

void sort_strings(char *arr[], int n);

void print_names(char *names[]);

int get_count(char *list[]);

char *get_word();

char *get_correct_size_ptr(char *word);

#endif