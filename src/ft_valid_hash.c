/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_hash.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:48:31 by dbennie           #+#    #+#             */
/*   Updated: 2019/12/11 19:48:33 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/lem-in.h"

int	ft_valid_hash(char *str, int *flag)
{
	if (ft_strequ(str, "##start"))
	{
		if (!START && ANTS && !LINKS && !DEF_SE)
		{
			START = 1;
			DEF_SE = 1;
		}
		else
			exit(4);
	}
	else if (ft_strequ(str, "##end"))
	{
		if (!END && ANTS && !LINKS && !DEF_SE)
		{
			END = 1;
			DEF_SE = 1;
		}
		else
			exit(4);
	}
	return (0);
}
