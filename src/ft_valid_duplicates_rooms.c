/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_duplicates_rooms.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:43:29 by dbennie           #+#    #+#             */
/*   Updated: 2019/12/11 20:43:29 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	ft_roomcmp(char *room1, char *room2)
{
	int		i;
	int		j;

	i = -1;
	while (room1[++i] && room2[i] && room1[i] != ' ' && room2[i] != ' ')
		if (room1[i] != room2[i])
			break ;
	if (room1[i] == room2[i])
		return (1);
	--i;
	j = i;
	while (room1[++i] && room1[i] != ' ')
		;
	while (room2[++j] && room2[j] != ' ')
		;
	while (room1[++i] && room2[++j])
		if (room1[i] != room2[i])
			return (0);
	return (1);
}

int			ft_valid_duplicates_rooms(t_data *data, char **strings)
{
	long	i;
	long	j;

	i = data->i_rooms_start - 1;
	while (++i <= data->i_rooms_end)
	{
		if (strings[i][0] != '#')
		{
			j = i;
			while (++j <= data->i_rooms_end)
				if (strings[j][0] != '#')
					if (ft_roomcmp(strings[i], strings[j]))
						ft_error(2);
		}
	}
	return (0);
}
