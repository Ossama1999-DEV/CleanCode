cmake_minimum_required(VERSION 3.10)


# Définir le standard C
set(CMAKE_C_STANDARD 99)

# Ajouter les fichiers sources
set(SOURCES
    src/file_reader.c
    src/analyzer.c
    src/json_formatter.c
)

# Ajouter les fichiers d'en-tête
set(HEADERS
    include/file_reader.h
    include/analyzer.h
    include/json_formatter.h
)

# Ajouter la bibliothèque partagée
add_library(clean_code_checker_lib SHARED ${SOURCES})
set_target_properties(clean_code_checker_lib PROPERTIES OUTPUT_NAME "_cleanCodeChecker")

# Inclure les répertoires d'en-tête
target_include_directories(clean_code_checker_lib PRIVATE ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/lib/include)  # Update this line

# Spécifier le compilateur GCC
set(CMAKE_C_COMPILER gcc)

# Définir les options de compilation
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")

# Définir le répertoire de sortie pour les bibliothèques partagées
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Définir le répertoire de sortie pour les exécutables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
