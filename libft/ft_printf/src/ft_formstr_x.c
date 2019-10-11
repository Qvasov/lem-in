/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formstr_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 20:42:45 by dbennie           #+#    #+#             */
/*   Updated: 2019/08/22 20:42:46 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_correctmod_x(t_format *form, unsigned long long *i,
														unsigned long long x)
{
	int					mod;

	mod = ft_correctmod(form);
	if (mod == 7)
		mod = sizeof(size_t);
	if (mod == 6)
		mod = sizeof(unsigned long);
	if (mod == 8)
		*i = (unsigned long long int)x;
	else if (mod == 4)
		*i = (unsigned long int)x;
	else if (mod == 2)
		*i = (unsigned short int)x;
	else if (mod == 1)
		*i = (unsigned char)x;
	else
		*i = (unsigned int)x;
}

static void	ft_addsign(t_format *form)
{
	if (form->f[3])
	{
		if (form->p == -2 && (form->w && form->f[4] && !form->f[0]))
		{
			form->str[0] = form->type;
			ft_addstr(form, 1, '0', 0);
		}
		else if (form->p < 0 && (form->w && form->f[4] && !form->f[0]))
			form->str[1] = form->type;
		else
		{
			ft_addstr(form, 1, form->type, 0);
			ft_addstr(form, 1, '0', 0);
		}
	}
}

static char	*ft_printf_x(t_format *form, unsigned long long x)
{
	char				*buf;
	unsigned long long	i;
	int					j;

	ft_correctmod_x(form, &i, x);
	if (form->p >= 0 && x == 0)
		return (ft_strnew(0));
	x = i;
	j = 1;
	while (i /= 16)
		++j;
	form->len = j;
	if (!(buf = (char *)malloc(sizeof(char) * j + 1)))
		return (NULL);
	buf[j--] = '\0';
	while (j >= 0)
	{
		buf[j--] = (x % 16 > 9) ? x % 16 + form->type - 33 : x % 16 + 48;
		x /= 16;
	}
	return (buf);
}

void		ft_formstr_x(t_format *form, unsigned long long num)
{
	if (!(form->str = ft_printf_x(form, num)))
		exit(0);
	if (form->p >= 0 && form->p > form->len)
		ft_addstr(form, form->p - form->len, '0', 0);
	else if (form->p < 0 && form->w <= form->len)
		form->p = form->w;
	else if ((form->w && form->f[4] && !form->f[0]) \
			&& form->p < 0 && form->w > form->len)
	{
		if (form->w - form->len == 1)
			form->p = -2;
		ft_addstr(form, form->w - form->len, '0', 0);
	}
	if (num != 0)
		ft_addsign(form);
	if (form->w > form->len)
	{
		if (form->f[0])
			ft_addstr(form, form->w - form->len, ' ', 1);
		else
			ft_addstr(form, form->w - form->len, ' ', 0);
	}
}
