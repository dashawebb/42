cmake_minimum_required(VERSION 3.13)
project(untitled C)

set(CMAKE_C_STANDARD 99)

include_directories(libft/includes)

#link_directories(libft)

add_library(libft.a SHARED IMPORTED)
set_target_properties(libft.a PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libft/libft.a)

add_executable(untitled main.c ft_ls/ft_ls.c ft_ls/ft_ls.h ft_ls/sorting.c ft_ls/list_functions.c ft_ls/output.c)

target_link_libraries(untitled libft.a)

