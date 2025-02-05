# CleanCode Project

## Overview
The CleanCode project is designed to analyze source code files and check for adherence to clean code practices. It provides a set of tools to read files, analyze their content, and format the results in JSON.

## Project Structure
```
clean_code_checker/
├── src/
│   ├── main.c
│   ├── file_reader.c
│   ├── file_reader.h
│   ├── analyzer.c
│   ├── analyzer.h
│   ├── json_formatter.c
│   ├── json_formatter.h
├── include/
│   ├── file_reader.h
│   ├── analyzer.h
│   ├── json_formatter.h
├── test_files/
│   ├── example.c
│   ├── example.cpp
├── output/
│   ├── report.json
├── CMakeLists.txt
└── README.md
```

## Files Description
- **src/main.c**: Entry point of the application. Initializes the clean code checker.
- **src/file_reader.c**: Implements functions for reading files (open, read, close).
- **src/file_reader.h**: Header file declaring functions and types for file reading.
- **src/analyzer.c**: Contains the implementation of code analysis logic.
- **src/analyzer.h**: Header file declaring functions and types for analysis.
- **src/json_formatter.c**: Implements functions to format analysis results into JSON.
- **src/json_formatter.h**: Header file declaring functions and types for JSON formatting.
- **include/**: Contains duplicate header files for external access.
- **test_files/**: Contains example C and C++ source code for testing.
- **output/report.json**: Stores the output report in JSON format.
- **CMakeLists.txt**: Configures the build process with CMake.
- **README.md**: Documentation for setup instructions and usage guidelines.

## Setup Instructions
1. Clone the repository.
2. Navigate to the project directory.
3. Use CMake to configure the project:
   ```
   mkdir build
   cd build
   cmake ..
   ```
4. Build the project:
   ```
   make
   ```

## Usage
Run the application with the desired source code files as input to analyze them for clean code practices. The results will be outputted in JSON format in the `output/report.json` file.