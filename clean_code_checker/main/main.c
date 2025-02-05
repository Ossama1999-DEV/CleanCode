#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_reader.h"
#include "json_formatter.h"
#include "analyzer.h"

int main(int argc, char *argv[]) {
    // Vérifier si un fichier a été passé en argument
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <fichier.c|fichier.cpp>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];

    // Vérifier l'extension du fichier (doit être .c ou .cpp)
    if (!(strstr(filename, ".c") || strstr(filename, ".cpp"))) {
        fprintf(stderr, "Erreur : Le fichier doit être un fichier .c ou .cpp\n");
        return EXIT_FAILURE;
    }

    // Lire le fichier source
    char *source_code = read_file(filename);
    if (!source_code) {
        fprintf(stderr, "Erreur : Impossible de lire le fichier %s\n", filename);
        return EXIT_FAILURE;
    }

    // Analyser le code source
    AnalysisResult result = analyze_code(source_code);

    // Convertir en JSON
    char *json_report = format_json(result);

    // Afficher le rapport JSON
    printf("%s\n", json_report);

    // Libérer la mémoire
    free(source_code);
    free(json_report);

    return EXIT_SUCCESS;
}