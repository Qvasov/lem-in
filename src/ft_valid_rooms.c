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

int	ft_valid_rooms(char *str, int *f, t_data *data, long j)
{
	long	i;
	int		space;

	i = 0;
	space = 0;
	while (str[i] && space == 0 && str[i] != '-')
		if (str[++i] == ' ')
			space = 1;
	if (!str[i] || !ft_isnum(&str[++i], ' '))
		ft_error(2);
	while (str[i] && space == 1)
		if (str[++i] == ' ')
			space = 2;
	if (!str[i] || !ft_isnum(&str[++i], '\0'))
		ft_error(2);
	ft_bit_on(f, ROOMS);
	if (!(data->i_rooms_start))
		data->i_rooms_start = j;
	data->i_rooms_end = j;
	if (!(data->i_start) && ft_bit_check(*f, START) && ft_bit_check(*f, DEF_SE))
		data->i_start = j;
	else if (!data->i_end && ft_bit_check(*f, END) && ft_bit_check(*f, DEF_SE))
		data->i_end = j;
	ft_bit_off(f, DEF_SE);
	return (0);
}
//check naming on -
//negative coordinates and positive with +
