NAME = ft_printf.a

FLAGS = -Wall -Wextra -Werror

LIBFT = inc/libft

DIR_S = src/

DIR_O = obj/

INCLUDES = inc/ft_printf.h

SOURCES =	ft_addbuf.c \
			ft_addstr.c \
			ft_createres.c \
			ft_bits.c \
			ft_color.c \
			ft_correctmod.c \
			ft_correctp.c \
			ft_errorform.c \
			ft_fastdegree.c \
			ft_formandout.c \
			ft_flags.c \
			ft_width.c \
			ft_precision.c \
			ft_lemin_read.c \
			ft_modificator.c \
			ft_formcount.c \
			ft_formstr.c \
			ft_formstr_b.c \
			ft_formstr_c.c \
			ft_formstr_di.c \
			ft_formstr_f.c \
			ft_formstr_notype.c \
			ft_formstr_o.c \
			ft_formstr_p.c \
			ft_formstr_perc.c \
			ft_formstr_s.c \
			ft_formstr_u.c \
			ft_formstr_x.c \
			ft_free.c \
			ft_multcolumn.c \
			ft_sumdegree.c \
			ft_printf.c

SRCS = $(addprefix $(DIR_S),$(SOURCES))

OBJS = $(addprefix $(DIR_O),$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)%.o: $(DIR_S)%.c
	@mkdir -p $(DIR_O)
	@$(CC) $(FLAGS) -I $(DIR_S) -o $@ -c $<

clean:
	@rm -rf $(DIR_O)

fclean: clean
	@rm -f $(NAME)

re: fclean all
