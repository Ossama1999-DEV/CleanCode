// This file declares the functions and types used in analyzer.c

#ifndef ANALYZER_H
#define ANALYZER_H

#include <stdio.h>

// Structure pour représenter un problème détecté dans le code
typedef struct {
    int line;              // Numéro de la ligne où se trouve le problème
    char message[256];     // Description du problème
} Issue;

// Structure pour stocker les résultats de l'analyse du code
typedef struct {
    int total_issues;      // Nombre total de problèmes détectés
    Issue *issues;         // Tableau des problèmes détectés
} AnalysisResult;

// Fonction principale pour analyser le code source
AnalysisResult analyze_code(const char *file_content);

// Vérifications spécifiques basées sur les principes de Clean Code
void check_variable_naming(const char *source, AnalysisResult *result);
void check_function_length(const char *source, AnalysisResult *result);
void check_goto_usage(const char *source, AnalysisResult *result);
void check_define_usage(const char *source, AnalysisResult *result);
void check_excessive_comments(const char *source, AnalysisResult *result);

// Fonction pour libérer la mémoire allouée dynamiquement dans AnalysisResult
void free_analysis_result(AnalysisResult *result);

#endif // ANALYZER_H
