/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formstr_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 20:43:09 by dbennie           #+#    #+#             */
/*   Updated: 2019/08/22 20:43:10 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_addsign(t_format *form)
{
	if (form->p == -2 && (form->w && form->f[4] && !form->f[0]))
	{
		form->str[0] = 'x';
		ft_addstr(form, 1, '0', 0);
	}
	else if (form->p < 0 && (form->w && form->f[4] && !form->f[0]))
		form->str[1] = 'x';
	else
	{
		ft_addstr(form, 1, 'x', 0);
		ft_addstr(form, 1, '0', 0);
	}
}

static char	*ft_printf_p(t_format *form, void *p)
{
	char				*buf;
	unsigned long long	i;
	int					j;

	if (form->p >= 0 && p == 0)
		return (ft_strnew(0));
	i = (unsigned long long int)p;
	j = 1;
	while (i /= 16)
		++j;
	form->len = j;
	form->f[3] = '#';
	i = (unsigned long long int)p;
	if (!(buf = (char *)malloc(sizeof(char) * j + 1)))
		return (NULL);
	buf[j--] = '\0';
	while (j >= 0)
	{
		buf[j--] = (i % 16 > 9) ? i % 16 + 87 : i % 16 + 48;
		i /= 16;
	}
	return (buf);
}

void		ft_formstr_p(t_format *form, void *ptr)
{
	if (!(form->str = ft_printf_p(form, ptr)))
		exit(0);
	if (form->p >= 0 && form->p > form->len)
		ft_addstr(form, form->p - form->len, '0', 0);
	else if (form->p < 0 && form->w == form->len)
		form->p = form->w;
	else if ((form->w && form->f[4] && !form->f[0]) \
			&& form->p < 0 && form->w > form->len)
	{
		if (form->w - form->len == 1)
			form->p = -2;
		ft_addstr(form, form->w - form->len, '0', 0);
	}
	ft_addsign(form);
	if (form->w > form->len)
	{
		if (form->f[0])
			ft_addstr(form, form->w - form->len, ' ', 1);
		else
			ft_addstr(form, form->w - form->len, ' ', 0);
	}
}
