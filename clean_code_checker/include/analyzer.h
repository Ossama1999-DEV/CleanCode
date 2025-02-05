// This file declares the functions and types used in analyzer.c

#ifndef ANALYZER_H
#define ANALYZER_H

// Function to analyze the content of a file for clean code practices
void analyze_code(const char *file_content);

// Function to report the findings of the analysis
void report_findings();

#endif // ANALYZER_H