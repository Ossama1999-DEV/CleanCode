/**
 * @file file_reader.c
 * @brief Implementation of file reading functions
 * @version 0.1
 * @date 2025-02-05
 * @author DBIBIH OUSSAMA
 */

#include "file_reader.h"
#include <stdlib.h>

/**
 * @brief Open a file with the specified mode
 * @param filename The name of the file to open
 * @param mode The mode to open the file in
 * @return FILE* Pointer to the opened file, or NULL if an error occurred
 */
FILE* open_file(const char* filename, const char* mode) {
    return fopen(filename, mode);
}

/**
 * @brief Read the content of a file
 * @param filename The name of the file to read
 * @return char* Pointer to the content of the file, or NULL if an error occurred
 */
char* read_file(const char* filename) {
    FILE* file = open_file(filename, "r");
    if (!file) return NULL;

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    rewind(file);

    char* buffer = (char*)malloc(length + 1);
    if (!buffer) return NULL;

    fread(buffer, 1, length, file);
    buffer[length] = '\0';

    fclose(file);
    return buffer;
}
