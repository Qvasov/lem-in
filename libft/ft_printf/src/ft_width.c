/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:37:23 by dbennie           #+#    #+#             */
/*   Updated: 2019/08/26 16:37:24 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_star(t_format *form, va_list *ap)
{
	form->w = va_arg(*ap, int);
	if (form->w < 0)
	{
		form->f[0] = '-';
		form->w = (form->w ^ 0xffffffff) + 1;
	}
	if (form->w > MAXWIDHT)
		exit(0);
}

void		ft_width(t_format *form, const char *s, long long *i, va_list *ap)
{
	*i = 0;
	while (!(TYPE) && (FLAGS || MOD || (NUM) || DOT || STAR))
	{
		if (s[*i] == '*')
			ft_star(form, ap);
		else if (s[*i] == '.')
		{
			++(*i);
			while ((NUM) || s[*i] == '*')
				++(*i);
			--(*i);
		}
		else if (s[*i] >= '0' && s[*i] <= '9')
		{
			while (s[*i] == '0')
				++(*i);
			ft_read(&form->w, s, i);
		}
		(*i)++;
	}
}
