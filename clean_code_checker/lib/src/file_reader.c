/**
 * @file file_reader.c
 * @author DBIBIH OUSSAMA (oussama.dbibih@viacesi.fr)
 * @brief 
 * @version 0.1
 * @date 2025-02-05
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "file_reader.h"
#include <stdlib.h>

FILE* open_file(const char* filename, const char* mode) {
    return fopen(filename, mode);
}

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
