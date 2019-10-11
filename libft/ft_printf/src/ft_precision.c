/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:37:29 by dbennie           #+#    #+#             */
/*   Updated: 2019/08/26 16:37:30 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_precision(t_format *form, const char *s, long long *i,
														va_list *ap)
{
	(*i) = 0;
	while (!(TYPE) && (FLAGS || MOD || (NUM) || DOT || STAR))
	{
		if (s[*i] == '.')
		{
			form->p = -1;
			++(*i);
			if (s[*i] == '*')
			{
				++(*i);
				form->p = va_arg(*ap, int);
				if (form->p > MAXWIDHT)
					exit(0);
			}
			else if (NUM)
				ft_read(&form->p, s, i);
			if (form->p == -1)
				form->p = 0;
		}
		(*i)++;
	}
}
