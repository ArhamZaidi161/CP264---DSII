/**
 * -------------------------------------
 * @file  strings_length.c
 * Lab 4 Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "functions.h"
/**
 * Traverses every string in strings and copies all strings shorter than length to the short_lines file,
 * and allstrings equal to or longer than length to the long_lines file.
 *
 * @param data - the strings_array struct to traverse
 * @param fp_short - output file pointer
 * @param fp_long - output file pointer
 * @param length - comparison length for strings
 */
void strings_length(strings_array *data, FILE *fp_short, FILE *fp_long, int length) {

    for (int i = 0; i < data->lines; i++) {
        if (strlen(data->strings[i]) >= length) {
            fprintf(fp_long, "%s\n", data->strings[i]);
        } 
        else if ((strlen(data->strings[i]) < length)) {
            fprintf(fp_short, "%s\n", data->strings[i]);
        }
    }
}
