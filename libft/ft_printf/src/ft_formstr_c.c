/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formstr_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 20:43:38 by dbennie           #+#    #+#             */
/*   Updated: 2019/08/22 20:43:41 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*ft_printf_c(t_format *form, int i)
{
	char	c;
	char	*buf;

	if (!(buf = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	c = (char)i;
	form->len = 1;
	buf[0] = c;
	buf[1] = '\0';
	return (buf);
}

void				ft_formstr_c(t_format *form, int num)
{
	int		f;

	f = 0;
	if (!(form->str = ft_printf_c(form, num)))
		exit(0);
	if ((form->w && form->f[4] && !form->f[0])
		&& form->p < 0 && form->w > form->len)
		ft_addstr(form, form->w - form->len, '0', 0);
	if (form->w > form->len)
	{
		if (form->f[0])
		{
			if (!(ft_strcmp(form->str, "\0\0")))
			{
				form->str[0] = '0';
				f = 1;
			}
			ft_addstr(form, form->w - form->len, ' ', 1);
		}
		else
			ft_addstr(form, form->w - form->len, ' ', 0);
		if (f)
			form->str[0] = '\0';
	}
}
