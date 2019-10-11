/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formstr_di.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 20:43:30 by dbennie           #+#    #+#             */
/*   Updated: 2019/08/22 20:43:32 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_limit(t_format *form)
{
	unsigned long long	l;
	int					i;
	char				*buf;

	l = 0x8000000000000000;
	i = 19;
	buf = (char *)malloc(sizeof(char) * 20);
	buf[19] = '\0';
	while (--i >= 0)
	{
		buf[i] = l % 10 + 48;
		l /= 10;
	}
	buf[18] = '8';
	form->len = 19;
	form->neg = '-';
	return (buf);
}

static void	ft_correctmod_d(t_format *form, long long *i, unsigned long long d)
{
	int		mod;

	mod = ft_correctmod(form);
	if (mod == 7)
		mod = sizeof(size_t);
	if (mod == 6)
		mod = sizeof(long);
	if (mod == 8)
		*i = (long long int)d;
	else if (mod == 4)
		*i = (long int)d;
	else if (mod == 2)
		*i = (short int)d;
	else if (mod == 1)
		*i = (char)d;
	else
		*i = (int)d;
	if (*i < 0)
		form->neg = '-';
	if (*i < 0)
		*i *= -1;
}

static void	ft_addsign(t_format *form)
{
	if ((form->f[2] || form->f[1]) && !form->neg)
	{
		if (form->p < 0 && (form->w && form->f[4] && !form->f[0]))
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
		if (form->p < 0 && (form->w && form->f[4] && !form->f[0]))
			form->str[0] = '-';
		else
			ft_addstr(form, 1, '-', 0);
	}
}

static char	*ft_printf_di(t_format *form, unsigned long long d)
{
	char		*buf;
	long long	i;
	int			j;

	if (d == 0x8000000000000000)
		return (ft_limit(form));
	ft_correctmod_d(form, &i, d);
	if (form->p >= 0 && d == 0)
		return (ft_strnew(0));
	d = i;
	j = 1;
	while (i /= 10)
		++j;
	form->len = j;
	if (!(buf = (char *)malloc(sizeof(char) * j + 1)))
		return (NULL);
	buf[j--] = '\0';
	while (j >= 0)
	{
		buf[j--] = d % 10 + 48;
		d /= 10;
	}
	return (buf);
}

void		ft_formstr_di(t_format *form, long long num)
{
	if (!(form->str = ft_printf_di(form, num)))
		exit(0);
	if (form->p >= 0 && form->p > form->len)
		ft_addstr(form, form->p - form->len, '0', 0);
	else if (form->p < 0 && form->w <= form->len)
		form->p = form->w;
	else if ((form->w && form->f[4] && !form->f[0])
			&& form->p < 0 && form->w > form->len)
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
