#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "analyzer.h"

#define MAX_ISSUES 100  // Limit of detected issues
#define MAX_FUNCTION_NAME_LENGTH 30
#define MAX_VARIABLE_NAME_LENGTH 20

// Function to check if a function name follows camelCase
int is_valid_function_name(const char *name) {
    if (!islower(name[0])) return 0;  // Must start with a lowercase letter
    for (int i = 1; name[i]; i++) {
        if (name[i] == '_') return 0;  // No underscores allowed
    }
    return 1;
}

// Function to check if a variable name is too long
int is_long_variable_name(const char *name) {
    return (strlen(name) > MAX_VARIABLE_NAME_LENGTH);
}

// Function to analyze the source code
AnalysisResult analyze_code(const char *code) {
    AnalysisResult result;
    result.total_issues = 0;
    result.issues = malloc(MAX_ISSUES * sizeof(Issue));

    char *copy = strdup(code); // Work on a copy
    char *line = strtok(copy, "\n");
    int line_number = 1;

    while (line) {
        // Check for improperly named functions
        if (strstr(line, "void ") || strstr(line, "int ") || strstr(line, "char ")) {
            char function_name[100];
            if (sscanf(line, "%*s %99[^()]", function_name) == 1) {
                if (!is_valid_function_name(function_name)) {
                    snprintf(result.issues[result.total_issues].message, 256, 
                             "Non-compliant function name: '%s'.", function_name);
                    result.issues[result.total_issues].line = line_number;
                    result.total_issues++;
                }
            }
        }

        // Check for incorrect macros
        if (strstr(line, "#define")) {
            char macro_name[100];
            if (sscanf(line, "#define %s", macro_name) == 1) {
                if (!isupper(macro_name[0])) {  // Check if it starts with an uppercase letter
                    snprintf(result.issues[result.total_issues].message, 256, 
                             "Incorrect macro naming convention: '%s'.", macro_name);
                    result.issues[result.total_issues].line = line_number;
                    result.total_issues++;
                }
            }
        }

        // Check for overly long variable names
        if (strstr(line, "int ") || strstr(line, "char ") || strstr(line, "float ")) {
            char variable_name[100];
            if (sscanf(line, "%*s %99[^ =;]", variable_name) == 1) {
                if (is_long_variable_name(variable_name)) {
                    snprintf(result.issues[result.total_issues].message, 256, 
                             "Variable name too long: '%s'.", variable_name);
                    result.issues[result.total_issues].line = line_number;
                    result.total_issues++;
                }
            }
        }

        line = strtok(NULL, "\n");
        line_number++;
    }

    free(copy);
    return result;
}

void free_analysis_result(AnalysisResult *result) {
    if (result->issues) {
        free(result->issues);
        result->issues = NULL;
    }
}