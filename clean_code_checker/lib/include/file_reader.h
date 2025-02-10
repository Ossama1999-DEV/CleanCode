/**
 * @file file_reader.h
 * @brief Header file for file reading functions
 * @version 0.1
 * @date 2025-02-05
 * @author DBIBIH OUSSAMA (oussama.dbibih@viacesi.fr)
 * 
 * 
 */
#ifndef FILE_READER_H
#define FILE_READER_H

#include <stdio.h>

FILE* open_file(const char* filename, const char* mode);
char* read_file(const char* filename);

#endif
