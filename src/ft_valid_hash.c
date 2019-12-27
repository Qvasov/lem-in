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

#include "lemin.h"

int	ft_valid_hash(char *str, int *flag)
{
	if (ft_strequ(str, "##start")) //strcmp or strncmp
	{
		if (!START && ANTS && !LINKS && !DEF_SE) //ANTS == 0?
		{
			START = 1;
			DEF_SE = 1;
		}
		else
			ft_error(4);
	}
	else if (ft_strequ(str, "##end")) //strcmp or strncmp
	{
		if (!END && ANTS && !LINKS && !DEF_SE)
		{
			END = 1;
			DEF_SE = 1;
		}
		else
			ft_error(4);
	}
	return (0);
}
//#comments??