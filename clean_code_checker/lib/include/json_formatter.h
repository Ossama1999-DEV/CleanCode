/**
 * @file json_formatter.h
 * @brief Header file for the JSON formatting logic
 * @version 0.1
 * @date 2025-02-05
 * @author DBIBIH OUSSAMA (oussama.dbibih@viacesi.fr)
 */

#ifndef JSON_FORMATTER_H
#define JSON_FORMATTER_H

#include "analyzer.h"

/**
 * @brief Format the analysis result as a JSON file
 * @param filename The name of the JSON file to create
 * @param result The analysis result to format
 * @return int 0 on success, -1 on failure
 */
int format_json(const char *filename, AnalysisResult result);

#endif
