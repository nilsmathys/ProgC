/**
 * @file flusher.c
 * @brief Code share for flushing stdin
 */
#include <stdio.h>
/**
 * @brief flushes stdin
 */
void flush_stdin() {
    while (getchar() != '\n');
}