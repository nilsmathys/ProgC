/**
 * title: Selbststudium 04 - Pointer, Arrays, Strings
 * created by Nils Mathys
 * date: 05.10.2019
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