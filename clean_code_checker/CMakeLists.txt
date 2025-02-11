cmake_minimum_required(VERSION 3.10)

project(CleanCode)

# Force l'utilisation de GCC
set(CMAKE_C_COMPILER gcc)

# Définir les options de compilation
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror -fPIC")

# Ajouter les sous-répertoires
add_subdirectory(lib)
add_subdirectory(main)
