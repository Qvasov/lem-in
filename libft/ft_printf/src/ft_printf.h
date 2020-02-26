/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddarell <ddarell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 20:46:28 by dbennie           #+#    #+#             */
/*   Updated: 2020/01/12 13:32:04 by ddarell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../../libft.h"

# define NORM			"\x1B[0m"
# define RED			"\x1B[31m"
# define GREEN			"\x1B[32m"
# define YELLOW			"\x1B[33m"
# define BLUE			"\x1B[34m"
# define PURPLE			"\x1B[35m"
# define CYAN			"\x1B[36m"
# define WHITE			"\x1B[37m"

# define FLAGS1			s[*i] == '-' || s[*i] == '+' || s[*i] == ' '
# define FLAGS2			s[*i] == '#' || s[*i] == '0'
# define FLAGS			FLAGS1 || FLAGS2

# define L				s[*i] == 'l' || s[*i] == 'L'
# define H				s[*i] == 'h'
# define J				s[*i] == 'j'
# define Z				s[*i] == 'z'
# define MOD    		L || H || J || Z

# define DI				s[*i] == 'd' || s[*i] == 'i'
# define UU				s[*i] == 'u' || s[*i] == 'U'
# define OXX			s[*i] == 'o' || s[*i] == 'x' || s[*i] == 'X'
# define CSP			s[*i] == 'c' || s[*i] == 's' || s[*i] == 'p'
# define F				s[*i] == 'f'
# define TYPE			DI || UU || OXX || CSP || F || s[*i] == '%'

# define NUM			s[*i] >= '0' && s[*i] <= '9'

# define DOT			s[*i] == '.'
# define STAR			s[*i] == '*'

# define MAXWIDHT		2147483640
# define BUFF_SIZE		5120

typedef struct			s_format
{
	char				f[5];
	int					w;
	int					p;
	char				mod[2];
	char				type;
	char				neg;
	char				*str;
	int					len;
	t_list				*list;
	t_list				*tail;
}						t_format;

typedef struct			s_buf
{
	char				*str;
	size_t				len;
}						t_buf;

typedef union			u_double
{
	struct
	{
		unsigned long long	m: 64;
		unsigned int	e: 15;
		unsigned int	s: 1;
	}					bits;
	long double			f;
	unsigned char		byte[10];
}						t_double;

union					u_binary
{
	int					i;
	unsigned char		byte[4];
};

struct					s_temp
{
	char				*t;
	int					k;
};

typedef struct			s_column
{
	char				**buf;
	int					i;
	int					j;
}						t_colum;

void					ft_color(t_buf *buf, const char *s, long long *i);
int						ft_printf(const char *restrict format, ...);
void					ft_zeroform(t_format *form);
long long				ft_formandout(t_format *form, const char *s,
													va_list *ap, t_buf *buf);
void					ft_flags(t_format *form, const char *s, long long *i);
void					ft_width(t_format *form, const char *s, long long *i,
																va_list *ap);
void					ft_precision(t_format *form, const char *s,
													long long *i, va_list *ap);
void					ft_read(int *j, const char *s, long long *i);
void					ft_modificator(t_format *form, const char *s,
																long long *i);
void					ft_addstr(t_format *form, int l, char c, int flagminus);
int						ft_correctmod(t_format *form);
void					ft_formstr(t_format *form, va_list *ap);
void					ft_formstr_c(t_format *form, int i);
void					ft_formstr_s(t_format *form, char *s);
void					ft_formstr_p(t_format *form, void *ptr);
void					ft_formstr_di(t_format *form, long long int num);
void					ft_formstr_o(t_format *form, unsigned long long num);
void					ft_formstr_u(t_format *form, unsigned long long num);
void					ft_formstr_x(t_format *form, unsigned long long num);
void					ft_formstr_f(t_format *form, long double num);
void					ft_formstr_b(t_format *form, unsigned long long num);
void					ft_formstr_perc(t_format *form);
void					ft_formstr_notype(t_format *form);
void					ft_bits(unsigned char octet, unsigned char *str);
char					*ft_formcount(t_format *form, int exp,
												const unsigned char *man);
void					ft_correctp(t_format *form, char *tmp1, char *tmp2,
																	int len);
char					*ft_createres(t_format *form, char *tmp1, char *tmp2);
char					*ft_fastdegree(int degree);
char					*ft_multcolumn(char *a, char *b);
char					*ft_sumdegree(char **buf, int strs, size_t len,
																	int neg);
char					*ft_frees(char **s, int strs);
char					*ft_freetmp1(char *tmp1);
char					*ft_freetmp2(char *tmp1, char *tmp2);
void					ft_addbuf(t_buf *buf, t_format *form);
void					ft_freelist(t_list *list);
void					ft_delelem(t_list *elem);

#endif
