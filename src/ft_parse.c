/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 18:04:19 by dbennie           #+#    #+#             */
/*   Updated: 2019/10/13 18:04:22 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/lem-in.h"

int	ft_parse(t_data *data, char **strings)
{
	long	i;

	ft_ants(data, strings);
	i = data->i_rooms_start;
	while (i <= data->i_rooms_end)
	{
		if (strings[i][0] != '#')
			if (ft_roomslist(data, strings[i]))
				exit(ft_error(data, strings));
		if (i == data->i_start)
			data->start = data->rooms;
		if (i == data->i_end)
			data->end = data->rooms;
		++i;
	}
	i = data->i_links_start;
	while (i <= data->i_links_end)
	{
		if (strings[i][0] != '#')
			if (ft_links(data, strings[i]))
				exit(ft_error(data, strings));
		++i;
	}
	return (0);
}
