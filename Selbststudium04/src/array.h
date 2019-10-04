/*
 * title: Selbststudium 04 - Pointer, Arrays, Strings
 * created by Nils Mathys
 * date: 25.09.2019
 */

#ifndef ARRAY_H
#define ARRAY_H

typedef enum{false, true} boolean;

void initialize_array_to_zero(char array[], size_t size);
boolean array_contains_entry(char *wordlist[], size_t size, char word[]);
boolean save_word_in_array(char *wordlist[], size_t *size, char word[]);
size_t get_compare_length(char word1[], char word2[]);
void sort_word_array(char *wordlist[], size_t size);

#endif