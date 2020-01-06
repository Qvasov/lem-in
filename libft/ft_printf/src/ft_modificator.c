/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formandout2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 20:44:09 by dbennie           #+#    #+#             */
/*   Updated: 2019/08/26 16:37:37 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_hhll(t_format *form, const char *s, long long *i)
{
	if ((s[*i] == 'h' || s[*i] == 'l') && s[*i] == form->mod[0])
		form->mod[1] = s[*i];
	else
		(*i)--;
}

void		ft_modificator(t_format *form, const char *s, long long *i)
{
	*i = 0;
	while (!(TYPE) && (FLAGS || MOD || (NUM) || DOT || STAR))
	{
		{
			if (H && form->mod[0] != 'l' && form->mod[0] != 'L'
				&& form->mod[0] != 'j' && form->mod[0] != 'z')
			{
				form->mod[0] = s[(*i)++];
				ft_hhll(form, s, i);
			}
			else if ((L) && form->mod[0] != 'j' && form->mod[0] != 'z')
			{
				form->mod[0] = s[(*i)++];
				ft_hhll(form, s, i);
			}
			else if (J && form->mod[0] != 'j')
				form->mod[0] = s[*i];
			else if (Z)
				form->mod[0] = s[*i];
		}
		(*i)++;
	}
}
