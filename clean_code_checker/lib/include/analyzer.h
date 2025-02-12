/**
 * @file analyzer.h
 * @brief Header file for the code analysis logic
 * @version 0.1
 * @date 2025-02-05
 * 
 * 
 */

#ifndef ANALYZER_H
#define ANALYZER_H

#include <stdio.h>

/**
 * @brief Structure to represent an issue detected in the code
 */
typedef struct {
    int line;              /**< Line number where the issue is found */
    char message[256];     /**< Description of the issue */
} Issue;

/**
 * @brief Structure to store the results of the code analysis
 */
typedef struct {
    int total_issues;      /**< Total number of issues detected */
    Issue *issues;         /**< Array of detected issues */
} AnalysisResult;

/**
 * @brief Main function to analyze the source code
 * @return AnalysisResult The result of the analysis
 */
AnalysisResult analyze_code(const char *file_content);

/**
 * @brief Check variable naming conventions
 * @param source The source code to check
 * @param result The result structure to store detected issues
 */
void check_variable_naming(const char *source, AnalysisResult *result);

/**
 * @brief Check function length
 * @param source The source code to check
 * @param result The result structure to store detected issues
 */
void check_function_length(const char *source, AnalysisResult *result);

/**
 * @brief Check for usage of goto statements
 * @param source The source code to check
 * @param result The result structure to store detected issues
 */
void check_goto_usage(const char *source, AnalysisResult *result);

/**
 * @brief Check for usage of statements
 * @param source The source code to check
 * @param result The result structure to store detected issues
 */
void check_define_usage(const char *source, AnalysisResult *result);

/**
 * @brief Check for excessive comments
 * @param source The source code to check
 * @param result The result structure to store detected issues
 */
void check_excessive_comments(const char *source, AnalysisResult *result);

/**
 * @brief Free dynamically allocated memory in AnalysisResult
 * @param result The result structure to free
 */
void free_analysis_result(AnalysisResult *result);

#endif // ANALYZER_H
