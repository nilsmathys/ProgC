/*
 * title: Selbststudium 04 - Pointer, Arrays, Strings
 * created by Nils Mathys
 * date: 25.09.2019
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"

///@brief Die Grösse des Input Arrays
#define INPUT_BUFFER 100
///@brief Die Grösse die ein Input maximal haben kann
#define WORD_LENGTH_BUFFER 20
///@brief der Schlüssel um die Eingabe zu beenden
#define ABORT_KEY "ZZZ"

/**
 * @brief Liest ein Wort von der input line. Speichert nur die Wörter
 *      die in der Range des WORD_LENGTH_BUFFER liegen.
 * @param word der Array bei dem die Inputs gespeichert werden sollen. \0 wird automatisch immer mitgespeichert
 * @return Die Grösse des ganzen Inputs auch wenn nicht das ganze Wort gespeichert wurde
 */
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
    return index-1; //-1 wegen des line break
}

/**
 * @brief Liest den Input vom Terminal und speichert diese im gegebenen Array
 *      bis der Benutzer den ABORT_KEY benützt falls ein Wort mehr als 20 Zeichen hat gibt es einen Fehler aus
 * @param wordlist Array der mit den Inputs gefüllt wird
 * @return die Anzahl von Einträgern im Array wordlist
 */
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

/**
 * @brief gibt die Liste der Wörter aus
 * @param wordlist die Liste die ausgegeben werden soll
 * @param size die Grösse der wordlist
 */
static void print_wordlist(char *wordlist[], size_t size) {
    (void)printf("-------------------------------------\n");
    (void)printf("Wörter in sortierter Reihenfolge:\n\n");
    for(size_t i = 0; i < size; i++) {
        (void)printf("%s\n", wordlist[i]);
    }
    (void)printf("-------------------------------------\n");
}

/**
 * @brief Main entry point
 * @return Gibt EXISS_SUCCESS (=0) zurück bei success
 */
int main(void) {
    char *wordlist[INPUT_BUFFER];
    size_t word_count = read_input(wordlist);
    (void)sort_word_array(wordlist, word_count);
    (void)print_wordlist(wordlist, word_count);
    return EXIT_SUCCESS;
}

