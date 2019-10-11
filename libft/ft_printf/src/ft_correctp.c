/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_correctp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 20:45:32 by dbennie           #+#    #+#             */
/*   Updated: 2019/08/22 20:45:34 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_correctpmore5(int *i, char *tmp2)
{
	if (--(*i) >= 0)
	{
		tmp2[*i] += 1;
		while (tmp2[*i] > '9' && (*i) >= 0)
		{
			tmp2[*i] = '0';
			if (--(*i) >= 0)
				tmp2[*i] += 1;
		}
	}
}

void				ft_correctp(t_format *form, char *tmp1, char *tmp2, int len)
{
	int	i;

	i = form->p;
	while (tmp2[i] && i >= form->p && i <= len)
	{
		if (tmp2[i] < '5')
			break ;
		else if (tmp2[i] >= '5')
			ft_correctpmore5(&i, tmp2);
	}
	if (i++ < 0)
	{
		tmp1[i] += 1;
		while (tmp1[i] > '9')
		{
			tmp1[i] = '0';
			tmp1[++i] += 1;
		}
	}
}
