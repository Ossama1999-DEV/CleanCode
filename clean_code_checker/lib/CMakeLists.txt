cmake_minimum_required(VERSION 3.10)

set(SOURCES
    src/file_reader.c
    src/json_formatter.c
    src/analyzer.c
)

add_library(clean_code_lib SHARED ${SOURCES})

target_include_directories(clean_code_lib PUBLIC include)

# Set the output directory for the library
set_target_properties(clean_code_lib PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)
