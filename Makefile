# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddarell <ddarell@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/09 19:21:40 by dbennie           #+#    #+#              #
#    Updated: 2020/01/16 15:06:38 by dbennie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	lem-in
INC_NAME		=	lemin.h

LIB_PATH		=	libft/
LIB_INC_PATH	=	libft/
LIB_NAME		=	libft.a

SRC_PATH		=	src/
INC_PATH		=	inc/
OBJ_PATH		=	obj/

SRC_NAME		=	ft_lemin_read.c ft_rooms.c ft_ford.c ft_suurballe.c\
				   	ft_direction.c ft_turn.c ft_error.c ft_valid.c\
				   	ft_findrooms.c ft_valid_ants.c ft_free_data.c\
					ft_valid_duplicates_rooms.c ft_free_str_split.c\
					ft_valid_hash.c ft_valid_links.c ft_lemin.c\
					ft_valid_rooms.c ft_links.c ft_ways.c ft_parse_data.c\
					ft_ways_ascending.c ft_path_ascending.c main.c\
					ft_flags_lemin.c ft_match_rooms_off.c\

SRC				=	$(addprefix $(SRC_PATH), $(SRC_NAME))
INC				=	$(addprefix $(INC_PATH), $(INC_NAME))
OBJ				=	$(addprefix $(OBJ_PATH), $(SRC_NAME:.c=.o))

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
IFLAGS			=	-I $(INC_PATH). -I $(LIB_PATH).
LFLAGS			=	-L $(LIB_PATH) -lft

LIB				=	make -C $(LIB_PATH)

.PHONY:	all clean fclean re lib

$(OBJ_PATH)%.o:		$(SRC_PATH)%.c $(INC)
					@mkdir -p $(OBJ_PATH)
					$(CC) $(CFLAGS) $(IFLAGS) -c -o $@ $<

all:				$(NAME)

$(NAME):			$(OBJ)

					$(LIB)
					$(CC) $(CFLAGS) $(IFLAGS) -o $@ $^ $(LFLAGS)

clean:
					make clean -C $(LIB_PATH)
					rm -rf $(OBJ_PATH)

fclean:				clean
					make fclean -C $(LIB_PATH)
					rm -f $(NAME)

re:					fclean all
