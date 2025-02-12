/**
 * @file file_reader.h
 * @brief Header file for file reading functions
 * @version 0.1
 * @date 2025-02-05
 * 
 * 
 */

#ifndef FILE_READER_H
#define FILE_READER_H

#include <stdio.h>

/**
 * @brief Open a file with the specified mode
 * @param filename The name of the file to open
 * @param mode The mode to open the file in
 * @return FILE* Pointer to the opened file, or NULL if an error occurred
 */
FILE* open_file(const char* filename, const char* mode);

/**
 * @brief Read the content of a file
 * @param filename The name of the file to read
 * @return char* Pointer to the content of the file, or NULL if an error occurred
 */
char* read_file(const char* filename);

#endif
