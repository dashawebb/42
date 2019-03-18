cmake_minimum_required(VERSION 3.13)
project(untitled C)

set(CMAKE_C_STANDARD 99)

include_directories(libft/includes)

#link_directories(libft)

add_executable(untitled main.c ft_ls/ft_ls.c ft_ls/ft_ls.h)

target_link_libraries(untitled libft/libft.a)