/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formstr_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 20:43:02 by dbennie           #+#    #+#             */
/*   Updated: 2019/08/22 20:43:03 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_printf_s(t_format *form, char *s)
{
	char	*buf;
	char	*tmp;
	int		j;

	tmp = s;
	if (!s)
		tmp = "(null)";
	j = ft_strlen(tmp);
	if (form->p >= 0 && form->p < j)
		j = form->p;
	form->len = j;
	if (!(buf = (char *)malloc(sizeof(char) * j + 1)))
		return (NULL);
	buf[j] = '\0';
	while (--j >= 0)
		buf[j] = tmp[j];
	return (buf);
}

void		ft_formstr_s(t_format *form, char *s)
{
	if (!(form->str = ft_printf_s(form, s)))
		exit(0);
	if ((form->w && form->f[4] && !form->f[0])
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
