/*
 * title: Selbststudium 04 - Pointer, Arrays, Strings
 * created by Nils Mathys
 * date: 25.09.2019
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"

#define INPUT_BUFFER 100
#define WORD_LENGTH_BUFFER 20
#define ABORT_KEY "ZZZ"



static size_t read_input_line(char word[]) {
    initialize_array_to_zero(word, WORD_LENGTH_BUFFER);
    size_t index = 0;
    char input = 0;
    while (input != '\n') {
        input = getchar();
        if(input != '\n' && index < WORD_LENGTH_BUFFER-1) {
            word[index] = input;
        }
        index++;
    }
    return index-1;
}

static size_t read_input(char *wordlist[]) {
    char word[WORD_LENGTH_BUFFER];
    size_t word_count = 0;
    boolean cont = true;
    char abort_key[] = ABORT_KEY;

    while(cont) {
        int word_size = read_input_line(word);

        if(word_size >= WORD_LENGTH_BUFFER) {
            (void)printf("Bitte geben Sie maximal %d Zeichen pro Wort ein \n", WORD_LENGTH_BUFFER -1);
        } else {
            if(strcmp(word, abort_key) == 0) {
                cont = false;
            } else {
                (void)save_word_in_array(wordlist, &word_count, word);
            }
        }
    }
    return word_count;
}

static void print_wordlist(char *wordlist[], size_t size) {
    (void)printf("-------------------------------------\n");
    (void)printf("Wörter in sortierter Reihenfolge:\n\n");
    for(size_t i = 0; i < size; i++) {
        (void)printf("%s\n", wordlist[i]);
    }
    (void)printf("-------------------------------------\n");
}

int main(void) {
    char *wordlist[INPUT_BUFFER];
    size_t word_count = read_input(wordlist);
    (void)sort_word_array(wordlist, word_count);
    (void)print_wordlist(wordlist, word_count);
    return EXIT_SUCCESS;
}

