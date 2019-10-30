cmake_minimum_required(VERSION 3.14)
project(lem_in C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(inc)
include_directories(src)

add_executable(lem_in
        inc/lem-in.h
        src/ft_ants.c
        src/ft_error.c
        src/ft_findrooms.c
        src/ft_free_data.c
        src/ft_free_links.c
        src/ft_free_names.c
        src/ft_links.c
        src/ft_names.c
        src/ft_parse.c
        src/ft_roomslist.c
        src/ft_valid.c
        src/main.c
        libft/get_next_line.c)

target_link_libraries(lem_in ~/github/lem-in/libft/libft.a)