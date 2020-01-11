/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_rooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:59:52 by dbennie           #+#    #+#             */
/*   Updated: 2019/12/11 18:59:53 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	check_room(char *str)
{
	int space;

	space = 0;
	while (*str && *str != '-' && *str != ' ')
		str++;
	while (*str)
	{
		if (*str == ' ')
		{
			str++;
			space++;
		}
		else
			ft_error(2);
		str = (*str == '+' || *str == '-') ? str + 1 : str;
		(*str >= '0' && *str <= '9') ? 1 : ft_error(2);
		while (*str >= '0' && *str <= '9')
			str++;
	}
	(space != 2) ? ft_error(2) : 1;
}

int	ft_valid_rooms(char *str, int *f, t_data *data, int j)
{
	check_room(str);
	ft_bit_on(f, ROOMS);
	if (!(data->i_rooms_start))
		data->i_rooms_start = j;
	data->i_rooms_end = j;
	if (!(data->i_start) && ft_bit_check(*f, START) && ft_bit_check(*f, DEF_SE))
		data->i_start = j;
	else if (!(data->i_end) && ft_bit_check(*f, END)
			&& ft_bit_check(*f, DEF_SE))
		data->i_end = j;
	ft_bit_off(f, DEF_SE);
	return (0);
}
//check naming on -
//negative coordinates and positive with +
