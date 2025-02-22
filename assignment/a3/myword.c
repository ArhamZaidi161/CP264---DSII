#include "myword.h"
#include "mystring.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int create_dictionary(FILE *fp, char *dictionary) {
    int count = 0;
    char line[1024];  // Increased buffer size to handle long input
    char *token;

    dictionary[0] = '\0'; // Ensure dictionary starts empty

    while (fgets(line, sizeof(line), fp)) { // Read each line
        token = strtok(line, " ,\n"); // Tokenize by spaces, commas, and newlines

        while (token != NULL) {
            if (count > 0) strcat(dictionary, " "); // Ensure proper spacing
            strcat(dictionary, token);
            count++;

            token = strtok(NULL, " ,\n"); // Get next word
        }
    }

    printf("Final word count: %d\n", count); // Debug output to confirm words read
    return count;
}

BOOLEAN contain_word(char *dictionary, char *word) {
    return strstr(dictionary, word) != NULL ? TRUE : FALSE;
}

WORDSTATS process_words(FILE *fp, WORD *words, char *dictionary) {
    WORDSTATS stats = {0, 0, 0};
    char line[256];

    while (fgets(line, sizeof(line), fp)) {
        stats.line_count++;
        str_trim(line);
        str_lower(line);

        char *token = strtok(line, " ,.\n");
        while (token) {
            stats.word_count++;
            if (!contain_word(dictionary, token)) {
                int found = 0;
                for (int i = 0; i < stats.keyword_count; i++) {
                    if (strcmp(words[i].word, token) == 0) {
                        words[i].count++;
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    strcpy(words[stats.keyword_count].word, token);
                    words[stats.keyword_count].count = 1;
                    stats.keyword_count++;
                }
            }
            token = strtok(NULL, " ,.\n");
        }
    }

    return stats;
}
