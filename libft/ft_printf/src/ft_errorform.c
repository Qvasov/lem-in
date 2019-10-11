/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errorform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 20:44:35 by dbennie           #+#    #+#             */
/*   Updated: 2019/08/22 20:45:01 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putweight(int w, t_buf *buf)
{
	char	tmp[11];
	int		j;
	int		i;

	j = 1;
	i = w;
	while (i /= 10)
		++j;
	tmp[j] = '\0';
	while (--j >= 0)
	{
		tmp[j] = w % 10 + 48;
		w /= 10;
	}
	while (tmp[++j])
		buf->str[buf->len++] = tmp[j];
}

int			ft_errorform(t_format *form, t_buf *buf)
{
	buf->str[buf->len++] = '%';
	if (form->f[3] == '#')
		buf->str[buf->len++] = '#';
	if (form->f[1] == '+')
		buf->str[buf->len++] = '+';
	if (form->f[2] == ' ' && form->f[1] != '+')
		buf->str[buf->len++] = ' ';
	if (form->f[0] == '-')
		buf->str[buf->len++] = '-';
	if (form->f[4] == '0' && form->f[0] != '-')
		buf->str[buf->len++] = '0';
	if (form->w)
		ft_putweight(form->w, buf);
	return (form->len);
}
