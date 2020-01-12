/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_hash.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddarell <ddarell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:48:31 by dbennie           #+#    #+#             */
/*   Updated: 2020/01/12 13:42:23 by ddarell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	ft_valid_hash(char *str, int *f)
{
	if (ft_strequ(str, "##start"))
	{
		if (!(ft_bit_check(*f, START)) && ft_bit_check(*f, ANTS)
		&& !(ft_bit_check(*f, LINKS)) && !(ft_bit_check(*f, DEF_SE)))
		{
			ft_bit_on(f, START);
			ft_bit_on(f, DEF_SE);
		}
		else
			ft_error(4);
	}
	else if (ft_strequ(str, "##end"))
	{
		if (!(ft_bit_check(*f, END)) && ft_bit_check(*f, ANTS)
		&& !(ft_bit_check(*f, LINKS)) && !(ft_bit_check(*f, DEF_SE)))
		{
			ft_bit_on(f, END);
			ft_bit_on(f, DEF_SE);
		}
		else
			ft_error(4);
	}
	return (0);
}
