/**
 * title: Selbststudium 04 - Pointer, Arrays, Strings
 * created by Nils Mathys
 * date: 05.10.2019
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"

#define ABORT_KEY "ZZZ"

/**
 * @brief Main entry point.
 * @details ermöglicht das Lesen der Wörter, auswerten der Wörter, das Überprüfen, ob sie bereits vorhanden sind
 * überprüft ob beendet wurde sortiert der array und druckt den array
 * @returns Returns EXIT_SUCCESS (=0) bei success,
 *                  EXIT_FAILURE (=1) wenn mer als ein Argument gegeben ist.
 */
int main(int argc, char *argv[]) {
    int size = 0;
    char *wordlist[WORDLIST_COUNT] = {0};

    while (size < WORDLIST_COUNT) {
        char *word = get_word();
        if (word == NULL) {
            return EXIT_FAILURE;
        }

        if (already_exist(word, wordlist, size)) {
            free(word);
            continue;
        }

        if (!strcmp(ABORT_KEY, word) || !strcmp("\n", word)) {
            free(word);
            break;
        }

        char *ptr = get_correct_size_ptr(word);
        if (ptr == NULL) {
            return EXIT_FAILURE;
        }
        wordlist[size] = ptr;
        size++;
    }
    int count = get_count(wordlist);
    sort_strings(wordlist, count - 1);
    print_names(wordlist);
    return EXIT_SUCCESS;
}

/**
 * @brief Liest ein maximal 20 Zeichen langes Wort von stdin ein und löscht alle Zeichen nach dem 20 Zeichen
 * @return string of stdin
 */
char *get_word() {
    char *word = malloc(20 * sizeof(char));
    if (word == NULL || scanf("%19s", word) != 1) {
        return NULL;
    }
    int c;
    while ((c = getchar()) != '\n' && c != EOF && c != ' ');
    return word;
}

/**
 * @brief Überprüft ob das letzte Wort von stdin bereits existiert
 * @param word read input überprüft ob es bereits existiert
 * @param words array bereits gelesene Wörter
 * @param grösse des arrays
 * @return 1 wenn es bereits existiert
 *         0 wenn es ein neues Wort ist
 */
int already_exist(char *word, char *words[], int size) {
    int i = 0;
    while (i < size) {
        if (!strcmp(words[i], word)) {
            return 1;
        }
        i++;
    }
    return 0;
}

/**
 * @brief kopiert eine 20 Zeichen langen String zu einem passenden String
 * @param word das auf die richtige Grösse gebracht werden soll
 * @return pointer zeigt auf grösse angepassten string
 */
char *get_correct_size_ptr(char *word) {
    size_t n = strlen(word);
    char *ptr = malloc((n + 1) * sizeof(char));
    if (ptr == NULL) {
        return NULL;
    }
    strcpy(ptr, word);
    free(word);
    return ptr;
}

/**
 * @brief gibt anzahl gelesene Wörter
 * @param liste mit gelesenen Wörtern
 * @return anzahl von Wörtern
 */
int get_count(char *list[]) {
    int count = 0;
    for (int i = 0; i < WORDLIST_COUNT; i++) {
        if (list[i] == NULL) {
            break;
        }
        count++;
    }
    return count;
}

/**
 * @brief sortiert den Array alphabetisch
 * @param arr zu sortierender Array
 * @param n länge des Arrays
 */
void sort_strings(char *arr[], int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n - i; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                char *temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/**
 * @brief gibt die Wörter der Liste aus
 * @param names Array der ausgegeben werden soll
 */
void print_names(char *names[]) {
    int i;
    printf("\nSortierte Liste:\n");
    printf("---------------------------\n");
    for (i = 0; i < WORDLIST_COUNT; ++i) {
        char *word = names[i];
        if (word == NULL) {
            break;
        }
        printf("%s\n", word);
    }
    printf("---------------------------\n");
}