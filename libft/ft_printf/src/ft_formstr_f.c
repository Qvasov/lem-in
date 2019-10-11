/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formstr_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 20:43:23 by dbennie           #+#    #+#             */
/*   Updated: 2019/08/22 20:43:24 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_limit(t_format *form, t_double *count)
{
	char	*buf;

	buf = NULL;
	form->len = 3;
	if (count->bits.m == 0)
		count->bits.e = 0;
	else if (count->bits.e == 32767 && count->f != count->f)
	{
		if (!(buf = (char *)malloc(sizeof(char) * 4)))
			exit(0);
		buf[0] = 'n';
		buf[1] = 'a';
		buf[2] = 'n';
		buf[3] = '\0';
	}
	else if (count->bits.m == 0x8000000000000000 && count->bits.e == 32767)
	{
		if (!(buf = (char *)malloc(sizeof(char) * 4)))
			exit(0);
		buf[0] = 'i';
		buf[1] = 'n';
		buf[2] = 'f';
		buf[3] = '\0';
	}
	return (buf);
}

static void	ft_addsign(t_format *form)
{
	if ((form->f[2] || form->f[1]) && !form->neg)
	{
		if (form->w && form->f[4] && !form->f[0] && form->p < form->len)
		{
			if (!form->f[1])
				form->str[0] = ' ';
			else
				form->str[0] = '+';
		}
		else
		{
			if (!form->f[1])
				ft_addstr(form, 1, ' ', 0);
			else
				ft_addstr(form, 1, '+', 0);
		}
	}
	else if (form->neg)
	{
		if (form->w && form->f[4] && !form->f[0] && form->p < form->len)
			form->str[0] = '-';
		else
			ft_addstr(form, 1, '-', 0);
	}
}

static char	*ft_printf_f(t_format *form, long double num)
{
	char			*buf;
	t_double		count;
	int				exp;
	unsigned char	man[65];
	int				i;

	i = 8;
	buf = NULL;
	count.f = num;
	form->neg = count.bits.s;
	buf = ft_limit(form, &count);
	exp = count.bits.e - 16383;
	man[64] = '\0';
	while (--i >= 0)
		ft_bits(count.byte[i], &man[64 - 8 * (i + 1)]);
	if (!buf)
		if (!(buf = ft_formcount(form, exp, man)))
			exit(0);
	return (buf);
}

void		ft_formstr_f(t_format *form, long double num)
{
	if (form->p < 0)
		form->p = 6;
	if (!(form->str = ft_printf_f(form, num)))
		exit(0);
	if (form->f[3] && form->p == 0)
		ft_addstr(form, 1, '.', 1);
	form->p = form->len;
	if (form->w && form->f[4] && !form->f[0] && form->w > form->len)
		ft_addstr(form, form->w - form->len, '0', 0);
	ft_addsign(form);
	if (form->w > form->len)
	{
		if (form->f[0])
			ft_addstr(form, form->w - form->len, ' ', 1);
		else
			ft_addstr(form, form->w - form->len, ' ', 0);
	}
}
