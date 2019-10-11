/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formandout1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 20:44:15 by dbennie           #+#    #+#             */
/*   Updated: 2019/08/26 19:13:36 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	ft_formandout(t_format *form, const char *s, va_list *ap,
																	t_buf *buf)
{
	long long	i;
	long long	j;

	i = 0;
	j = 0;
	if (s[i] == '\0')
		return (0);
	ft_zeroform(form);
	ft_flags(form, s, &i);
	ft_width(form, s, &i, ap);
	ft_precision(form, s, &i, ap);
	ft_modificator(form, s, &i);
	if (s[i] != '\0')
		form->type = s[i++];
	ft_formstr(form, ap);
	while (j < form->len)
	{
		ft_addbuf(buf, form);
		buf->str[buf->len++] = form->str[j++];
	}
	ft_strdel(&form->str);
	return (i);
}
