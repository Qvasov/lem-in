/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formstr_o.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 20:43:16 by dbennie           #+#    #+#             */
/*   Updated: 2019/08/22 20:43:17 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_correctmod_o(t_format *form, unsigned long long *i,
													unsigned long long o)
{
	int	mod;

	mod = ft_correctmod(form);
	if (mod == 7)
		mod = sizeof(size_t);
	if (mod == 6)
		mod = sizeof(unsigned long);
	if (mod == 8)
		*i = (unsigned long long int)o;
	else if (mod == 4)
		*i = (unsigned long int)o;
	else if (mod == 2)
		*i = (unsigned short int)o;
	else if (mod == 1)
		*i = (unsigned char)o;
	else
		*i = (unsigned int)o;
}

static void	ft_addsign(t_format *form, unsigned long long num)
{
	if (form->f[3])
	{
		if ((form->p < 0 && num == 0) || form->str[0] == '0')
			return ;
		if (form->p < 0 && (form->w && form->f[4] && !form->f[0]))
			form->str[0] = '0';
		else
			ft_addstr(form, 1, '0', 0);
	}
}

static char	*ft_printf_o(t_format *form, unsigned long long o)
{
	char					*buf;
	unsigned long long int	i;
	int						j;

	ft_correctmod_o(form, &i, o);
	if (form->p >= 0 && o == 0)
		return (ft_strnew(0));
	o = i;
	j = 1;
	while (i /= 8)
		++j;
	form->len = j;
	if (!(buf = (char *)malloc(sizeof(char) * j + 1)))
		return (NULL);
	buf[j--] = '\0';
	while (j >= 0)
	{
		buf[j--] = o % 8 + 48;
		o /= 8;
	}
	return (buf);
}

void		ft_formstr_o(t_format *form, unsigned long long num)
{
	if (!(form->str = ft_printf_o(form, num)))
		exit(0);
	if (form->p >= 0 && form->p > form->len)
		ft_addstr(form, form->p - form->len, '0', 0);
	else if (form->p < 0 && form->w == form->len)
		form->p = form->w;
	else if ((form->w && form->f[4] && !form->f[0]) \
			&& form->p < 0 && form->w > form->len)
		ft_addstr(form, form->w - form->len, '0', 0);
	ft_addsign(form, num);
	if (form->w > form->len)
	{
		if (form->f[0])
			ft_addstr(form, form->w - form->len, ' ', 1);
		else
			ft_addstr(form, form->w - form->len, ' ', 0);
	}
}
