NAME = push_swap

FLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

DIR_S = src/

DIR_O = obj/

DIR_LIB = libft/

INCLUDES = inc/push_swap.h

SOURCES =	ft_checkdouble.c\
			ft_checker.c\
			ft_convert.c\
			ft_cost.c\
			ft_errors.c\
			ft_find_num_with_min_cost.c\
			ft_flags_checker.c\
			ft_flags_push_swap.c\
			ft_frees.c\
			ft_instructions.c\
			ft_issort.c\
			ft_move.c\
			ft_op.c\
			ft_quicksort.c\
			ft_push.c\
			ft_push_swap.c\
			ft_rotate.c\
			ft_revrotate.c\
			ft_sort.c\
			ft_split.c\
			ft_swaps.c\
			ft_visualisation.c\
			ft_zero.c\

SRCS = $(addprefix $(DIR_S),$(SOURCES))

OBJS = $(addprefix $(DIR_O),$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS) obj/checker.o obj/push_swap.o
	make -C libft/
	$(CC) $(FLAGS) -o checker obj/checker.o $(OBJS) -L. $(LIBFT)
	$(CC) $(FLAGS) -o push_swap obj/push_swap.o $(OBJS) -L. $(LIBFT)

$(DIR_O)%.o: $(DIR_S)%.c
	@mkdir -p $(DIR_O)
	$(CC) $(FLAGS) -I $(DIR_S) -o $@ -c $<

clean:
	@rm -rf $(DIR_O)
	@make clean -C $(DIR_LIB)

fclean: clean
	@rm -f push_swap
	@rm -f checker
	@make fclean -C $(DIR_LIB)

re: fclean all
