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

#include "lemin.h"

int	ft_parse_data(t_data *data, char **strings)
{
	long	i;

	data->ants = ft_atoull(strings[data->i_ants]);
	i = data->i_rooms_start - 1;
	while (++i <= data->i_rooms_end)
	{
		if (strings[i][0] != '#')
			ft_rooms(data, strings[i]);
		if (i == data->i_start)
			data->start = data->rooms;
		if (i == data->i_end)
			data->end = data->rooms;
	}
	i = data->i_links_start - 1;
	while (++i <= data->i_links_end)
		if (strings[i][0] != '#')
			ft_links(data, strings[i]);
	return (0);
}
