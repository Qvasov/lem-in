/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:37:17 by dbennie           #+#    #+#             */
/*   Updated: 2019/08/26 16:37:19 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags(t_format *form, const char *s, long long *i)
{
	*i = 0;
	while (!(TYPE) && (FLAGS || MOD || (NUM) || DOT))
	{
		if (s[*i] == '-' && form->f[0] != '-')
			form->f[0] = '-';
		else if (s[*i] == '+' && form->f[1] != '+')
			form->f[1] = '+';
		else if (s[*i] == ' ' && form->f[2] != ' ')
			form->f[2] = ' ';
		else if (s[*i] == '#' && form->f[3] != '#')
			form->f[3] = '#';
		else if (s[*i] == '0' && form->f[4] != '0')
		{
			--(*i);
			if ((!(NUM) && !(DOT)) || *i < 0)
				form->f[4] = '0';
			while ((NUM) || DOT || *i < 0)
				++(*i);
			--(*i);
		}
		++(*i);
	}
}
