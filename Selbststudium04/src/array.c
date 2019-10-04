/*
 * title: Selbststudium 04 - Pointer, Arrays, Strings
 * created by Nils Mathys
 * date: 25.09.2019
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"

void initialize_array_to_zero(char array[], size_t size) {
    for(size_t i = 0; i < size; i++) {
        array[i] = 0;
    }
}

boolean array_contains_entry(char *wordlist[], size_t size, char word[]) {
    boolean contains_word = false;
    for(size_t i = 0; i < size; i++) {
        if(strcmp(wordlist[i], word) == 0) {
            contains_word = true;
            break;
        }
    }
    return contains_word;
}

boolean save_word_in_array(char *wordlist[], size_t *size, char word[]) {
    boolean word_added = false;
    if(!array_contains_entry(wordlist, *size, word)) {
        size_t length = strlen(word);
        char *entry = malloc(length+1);
        strcpy(entry, word);
        wordlist[*size] = entry;
        word_added = true;
        (*size)++;
    }
    return word_added;
}

size_t get_compare_length(char word1[], char word2[]) {
    size_t len_w1 = strlen(word1);
    size_t len_w2 = strlen(word2);
    size_t return_vaulue = 0;
    if(len_w1 > len_w2) {
        return_vaulue = len_w2;
    } else {
        return_vaulue = len_w1;
    }
    return  return_vaulue;
}

void sort_word_array(char *wordlist[], size_t size) {
    boolean had_change = true;
    while (had_change) {
        had_change = false;
        for(size_t word_i = 0; word_i < size-1; word_i++) {
            size_t cmp_len = get_compare_length(wordlist[word_i], wordlist[word_i+1]);
            int result = strncmp(wordlist[word_i], wordlist[word_i+1], cmp_len);
            if(result > 0) {
                char *tmp = wordlist[word_i];
                wordlist[word_i] = wordlist[word_i+1];
                wordlist[word_i+1] = tmp;
                had_change = true;
            }
        }
    }
}
