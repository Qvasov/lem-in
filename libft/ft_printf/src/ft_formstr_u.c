/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formstr_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 20:42:55 by dbennie           #+#    #+#             */
/*   Updated: 2019/08/22 20:42:56 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_correctmod_u(t_format *form, unsigned long long *i,
														unsigned long long u)
{
	int	mod;

	mod = ft_correctmod(form);
	if (mod == 7 || form->type == 'U')
		mod = sizeof(size_t);
	if (mod == 6)
		mod = sizeof(unsigned long);
	if (mod == 8)
		*i = (unsigned long long int)u;
	else if (mod == 4)
		*i = (unsigned long int)u;
	else if (mod == 2)
		*i = (unsigned short int)u;
	else if (mod == 1)
		*i = (unsigned char)u;
	else
		*i = (unsigned int)u;
}

static char	*ft_printf_u(t_format *form, unsigned long long u)
{
	char				*buf;
	unsigned long long	i;
	int					j;

	ft_correctmod_u(form, &i, u);
	if (form->p >= 0 && u == 0)
		return (ft_strnew(0));
	u = i;
	j = 1;
	while (i /= 10)
		++j;
	form->len = j;
	if (!(buf = (char *)malloc(sizeof(char) * j + 1)))
		return (NULL);
	buf[j--] = '\0';
	while (j >= 0)
	{
		buf[j--] = u % 10 + 48;
		u /= 10;
	}
	return (buf);
}

void		ft_formstr_u(t_format *form, unsigned long long num)
{
	if (!(form->str = ft_printf_u(form, num)))
		exit(0);
	if (form->p >= 0 && form->p > form->len)
		ft_addstr(form, form->p - form->len, '0', 0);
	else if (form->p < 0 && form->w == form->len)
		form->p = form->w;
	else if ((form->w && form->f[4] && !form->f[0]) \
			&& form->p < 0 && form->w > form->len)
		ft_addstr(form, form->w - form->len, '0', 0);
	if (form->w > form->len)
	{
		if (form->f[0])
			ft_addstr(form, form->w - form->len, ' ', 1);
		else
			ft_addstr(form, form->w - form->len, ' ', 0);
	}
}
