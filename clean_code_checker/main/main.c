#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "file_reader.h"
#include "json_formatter.h"
#include "analyzer.h"

#define OUTPUT_DIR "C:\\Users\\asus\\OneDrive\\Bureau\\Perso\\CleanCode\\clean_code_checker\\output\\"

int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc < 2 || argc > 3) {
        fprintf(stderr, "Usage: <file.c|file.cpp> [--verbose|--print]\n");
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    int verbose_mode = (argc == 3 && strcmp(argv[2], "--verbose") == 0);
    int print_mode = (argc == 3 && strcmp(argv[2], "--print") == 0);

    // Check the file extension
    if (!(strstr(filename, ".c") || strstr(filename, ".cpp"))) {
        fprintf(stderr, "Error: The file must be a .c or .cpp file\n");
        return EXIT_FAILURE;
    }

    if (verbose_mode) {
        printf("Analyzing...\n");
        printf("File: %s\n", filename);
    }

    // Read the source file
    char *source_code = read_file(filename);
    if (!source_code) {
        fprintf(stderr, "Error: Unable to read the file %s\n", filename);
        return EXIT_FAILURE;
    }

    // Analyze the source code
    AnalysisResult result = analyze_code(source_code);

    // Generate the output JSON file name
    char output_filename[512];
    snprintf(output_filename, sizeof(output_filename), "%sresult.json", OUTPUT_DIR);

    // Save the JSON report to a file
    if (format_json(output_filename, result) != 0) {
        fprintf(stderr, "Error: Unable to write the JSON file %s\n", output_filename);
        free(source_code);
        free_analysis_result(&result);
        return EXIT_FAILURE;
    }

    printf("Report successfully generated: %s\n", output_filename);

    // Print the JSON content if print_mode is enabled
    if (print_mode) {
        char *json_content = read_file(output_filename);
        if (json_content) {
            printf("JSON Report Content:\n%s\n", json_content);
            free(json_content);
        } else {
            fprintf(stderr, "Error: Unable to read the JSON file %s\n", output_filename);
        }
    }

    // Free memory
    free(source_code);
    free_analysis_result(&result);

    return EXIT_SUCCESS;
}
