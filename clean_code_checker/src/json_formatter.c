#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "json_formatter.h"

void format_json(const char *filename, const char *data) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file for writing: %s\n", filename);
        return;
    }

    fprintf(file, "{\n");
    fprintf(file, "  \"analysis\": \"%s\"\n", data);
    fprintf(file, "}\n");

    fclose(file);
}