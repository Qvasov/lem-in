cmake_minimum_required(VERSION 3.14)
project(lem-in C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(lem-in
        src/main.c
        inc/lem-in.h
        src/ft_parse.c
        src/ft_ants.c
        src/ft_roomslist.c
        src/ft_valid.c
        src/ft_links.c
        src/ft_names.c src/ft_findrooms.c src/ft_free_names.c src/ft_error.c src/ft_free_data.c)

target_link_libraries(lem-in /libft/libft.a)
