#include <stdio.h>
#include <stdlib.h>
#include "json_formatter.h"
#include "analyzer.h"

int format_json(const char *filename, AnalysisResult result) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error opening JSON file");
        return -1;
    }

    fprintf(file, "{\n");
    fprintf(file, "  \"total_issues\": %d,\n", result.total_issues);
    fprintf(file, "  \"issues\": [\n");

    for (int i = 0; i < result.total_issues; i++) {
        fprintf(file, "    { \"line\": %d, \"message\": \"%s\" }%s\n",
                result.issues[i].line, result.issues[i].message,
                (i < result.total_issues - 1) ? "," : "");
    }

    fprintf(file, "  ]\n");
    fprintf(file, "}\n");

    fclose(file);
    return 0;
}
