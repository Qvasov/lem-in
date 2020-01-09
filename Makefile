# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbennie <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/09 19:21:40 by dbennie           #+#    #+#              #
#    Updated: 2020/01/09 19:21:46 by dbennie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEF				=	\033[0m
BOLD			=	\033[1m
UNDERLINE		=	\033[4m
REV				=	\033[7m
BLACK			=	\033[30m
RED				=	\033[31m
GREEN			=	\033[32m
YELLOW			=	\033[33m
BLUE			=	\033[34m
PINK			=	\033[35m
CYAN			=	\033[36m
GREY			=	\033[37m
BLACK_B			=	\033[40m
RED_B			=	\033[41m
GREEN_B			=	\033[42m
YELLOW_B		=	\033[43m
BLUE_B			=	\033[44m
PINK_B			=	\033[45m
CYAN_B			=	\033[46m
GREY_B			=	\033[47m

NAME			=	lem-in

INC_NAME        =   lemin.h
LIB_PATH		=	libft/
LIB_INC_PATH	=	libft/

LIB_NAME		=	libft.a

LIB				=	$(addprefix $(LIB_PATH), $(LIB_NAME))
LIB_INC			=	$(addprefix -I, $(LIB_INC_PATH))

SRC_PATH		=	src/
INC_PATH		=	inc/
OBJ_PATH		=	obj/

SRC_NAME		=	ft_copy_char.c ft_lemin_read.c ft_copy_num.c ft_rooms.c\
					ft_dijkstra.c ft_suurballe.c ft_direction.c ft_turn.c\
					ft_error.c ft_valid.c ft_findrooms.c ft_valid_ants.c\
					ft_free_data.c ft_valid_duplicates_links.c ft_free_links.c\
					ft_valid_duplicates_rooms.c ft_free_str_split.c\
					ft_valid_hash.c ft_free_way.c ft_valid_links.c ft_lem_in.c\
					ft_valid_rooms.c ft_links.c ft_ways.c ft_parse_data.c\
					ft_ways_ascending.c ft_path_ascending.c main.c ft_flags_lemin.c\

SRC             =	$(addprefix $(SRC_PATH), $(SRC_NAME))
INC             =   $(addprefix $(INC_PATH), $(INC_NAME))

CC = gcc
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I $(INC_PATH). -I $(LIB_PATH).
LFLAGS = -L $(LIB_PATH) -lft

.PHONY: all clean fclean re lib

OBJ = $(addprefix $(OBJ_PATH), $(SRC_NAME:.c=.o))

LIB = make -C $(LIB_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INC)
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(IFLAGS) -c -o $@ $<

all:		$(NAME)

$(NAME):	$(OBJ)

	$(LIB)
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ $^ $(LFLAGS)

clean:
	make clean -C $(LIB_PATH)
	rm -rf $(OBJ_PATH)

fclean: clean
	make fclean -C $(LIB_PATH)
	rm -f $(NAME)

re: fclean all
