cmake_minimum_required(VERSION 3.10)

set(SOURCES
    main.c
)

add_executable(clean_code_checker ${SOURCES})

target_link_libraries(clean_code_checker clean_code_lib)
target_include_directories(clean_code_checker PUBLIC ../lib/include)

# Set the output directory for the executable
set_target_properties(clean_code_checker PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/main
)
