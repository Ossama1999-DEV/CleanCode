cmake_minimum_required(VERSION 3.10)

# Définir le standard C
set(CMAKE_C_STANDARD 99)

# Ajouter les fichiers sources
set(SOURCES
    main.c
)

# Ajouter l'exécutable
add_executable(clean_code_checker_main ${SOURCES})

# Spécifier le compilateur GCC
set(CMAKE_C_COMPILER gcc)

# Définir les options de compilation
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -mconsole")

# Définir le répertoire de sortie pour les exécutables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/main)

# Inclure les répertoires d'en-tête
target_include_directories(clean_code_checker_main PRIVATE ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/lib/include)

# Lier la bibliothèque partagée à l'exécutable
target_link_libraries(clean_code_checker_main clean_code_checker_lib)

