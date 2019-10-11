/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formstr_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 15:35:56 by dbennie           #+#    #+#             */
/*   Updated: 2019/08/27 16:02:07 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_correctmod_b(t_format *form, unsigned long long *i,
														unsigned long long b)
{
	int		mod;

	mod = ft_correctmod(form);
	if (mod == 7)
		mod = sizeof(size_t);
	if (mod == 6)
		mod = sizeof(unsigned long);
	if (mod == 8)
		*i = (unsigned long long)b;
	else if (mod == 4)
		*i = (unsigned long int)b;
	else if (mod == 2)
		*i = (unsigned short int)b;
	else if (mod == 1)
		*i = (unsigned char)b;
	else
		*i = (unsigned int)b;
}

static void	ft_addsign(t_format *form)
{
	if (form->mod[0] == 'h' && form->mod[1] == 'h' &&
			form->len <= (int)sizeof(char) * 8)
		ft_addstr(form, sizeof(char) * 8 - form->len, '0', 0);
	else if (form->mod[0] == 'h' && form->mod[1] == '\0' &&
			form->len <= (int)sizeof(short int) * 8)
		ft_addstr(form, sizeof(short int) * 8 - form->len, '0', 0);
	else if (form->mod[0] == 'l' && form->mod[1] == '\0' &&
			form->len <= (int)sizeof(long) * 8)
		ft_addstr(form, sizeof(long) * 8 - form->len, '0', 0);
	else if (form->mod[0] == 'l' && form->mod[1] == 'l' &&
			form->len <= (int)sizeof(long long) * 8)
		ft_addstr(form, sizeof(long long) * 8 - form->len, '0', 0);
	else if (form->mod[0] == 'h' && form->mod[1] == '\0' &&
			form->len <= (int)sizeof(short int) * 8)
		ft_addstr(form, sizeof(short int) * 8 - form->len, '0', 0);
	else if (form->mod[0] == 'z' && form->mod[1] == '\0' &&
			form->len <= (int)sizeof(size_t) * 8)
		ft_addstr(form, sizeof(size_t) * 8 - form->len, '0', 0);
	else if (form->mod[0] == 'j' && form->mod[1] == '\0' &&
			form->len <= (int)sizeof(unsigned long) * 8)
		ft_addstr(form, sizeof(unsigned long) * 8 - form->len, '0', 0);
	else
		ft_addstr(form, sizeof(int) * 8 - form->len, '0', 0);
}

static char	*ft_printf_b(t_format *form, unsigned long long b)
{
	char				*buf;
	unsigned long long	i;
	int					j;

	ft_correctmod_b(form, &i, b);
	if (form->p >= 0 && b == 0)
		return (ft_strnew(0));
	b = i;
	j = 1;
	while (i /= 2)
		++j;
	form->len = j;
	if (!(buf = (char *)malloc(sizeof(char) * j + 1)))
		return (NULL);
	buf[j--] = '\0';
	while (j >= 0)
	{
		buf[j--] = b % 2 + 48;
		b /= 2;
	}
	return (buf);
}

void		ft_formstr_b(t_format *form, unsigned long long num)
{
	if (!(form->str = ft_printf_b(form, num)))
		exit(0);
	if (form->p >= 0 && form->p > form->len)
		ft_addstr(form, form->p - form->len, '0', 0);
	else if (form->p < 0 && form->w <= form->len)
		form->p = form->w;
	else if ((form->w && form->f[4] && !form->f[0])
			&& form->p < 0 && form->w > form->len)
		ft_addstr(form, form->w - form->len, '0', 0);
	if (form->f[3])
		ft_addsign(form);
	if (form->w > form->len)
	{
		if (form->f[0])
			ft_addstr(form, form->w - form->len, ' ', 1);
		else
			ft_addstr(form, form->w - form->len, ' ', 0);
	}
}
