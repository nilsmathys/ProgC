/*
 * title: Selbststudium 04 - Pointer, Arrays, Strings
 * created by Nils Mathys
 * date: 25.09.2019
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"

/**
 * @brief Initialisiert jedes Element des Arrays auf 0
 * @param array der initialisiert werden soll
 * @param size Grösse des Arrays
 */
void initialize_array_to_zero(char array[], size_t size) {
    for(size_t i = 0; i < size; i++) {
        array[i] = 0;
    }
}

/**
 * @brief Überprüft, ob der Array ein gegebenes Wort enthält
 * @param wordlist Der Array mit Wörtern der überprüft werden soll
 * @param size die Grösse des wordlist arrays
 * @param word das Wort das im wordlist gesucht werden soll
 * @return true(1) wenn das Wort im Array vorkommt, ansonsten false(0)
 */
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

/**
 * @brief Speichert ein Wort im Array falls es noch nicht existiert
 * @param wordlist Der Array indem die Wörter gespeichert werden sollen
 * @param size Aktuelle Grösse des Arrays wordlist
 * @param word Das Wort das gespeichert werden soll
 * @return true(1) wenn das Wort gespeichert wurde, ansonsten false(0) wenn das Wort bereits im Array existiert
 */
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

/**
 * @brief Gibt die Länge des kürzeren Wortes zurück bei zwei zu überprüfenden Wörtern
 * @param word1 erstes Wort
 * @param word2 zweites Wort
 * @return die länge des kürzeren Wortes
 */
size_t get_compare_length(char word1[], char word2[]) {
    size_t len_w1 = strlen(word1);
    size_t len_w2 = strlen(word2);
    size_t return_value = 0;
    if(len_w1 > len_w2) {
        return_vaulue = len_w2;
    } else {
        return_vaulue = len_w1;
    }
    return  return_value;
}

/**
 * @brief Sortiert einen Array mit Wörtern in alphabetischer Reihenfolge
 * @param wordlist Array der sortiert werden soll
 * @param size die Grösse des Array wordlist
 */
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
