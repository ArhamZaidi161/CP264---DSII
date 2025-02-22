#include "mystring.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int str_words(char *s) {
    int count = 0;
    int in_word = 0;
    while (*s) {
        if ((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z')) {
            if (!in_word) {
                count++;
                in_word = 1;
            }
        } else if (*s == ' ' || *s == '\t' || *s == ',' || *s == '.') {
            in_word = 0;
        }
        s++;
    }
    return count;
}

int str_lower(char *s) {
    int count = 0;
    while (*s) {
        if (*s >= 'A' && *s <= 'Z') {
            *s = *s + ('a' - 'A');
            count++;
        }
        s++;
    }
    return count;
}

void str_trim(char *s) {
    char *dst = s;
    int in_space = 1;

    // Skip leading spaces
    while (*s == ' ') s++;

    while (*s) {
        if (*s != ' ' || !in_space) {
            *dst++ = *s;
            in_space = (*s == ' ');
        }
        s++;
    }

    // Remove trailing space properly
    if (dst > s && *(dst - 1) == ' ') {
        *(dst - 1) = '\0';
    } else {
        *dst = '\0';
    }
}