#ifndef FILE_READER_H
#define FILE_READER_H

#include <stdio.h>

FILE* open_file(const char* filename, const char* mode);
char* read_file(const char* filename);

#endif
