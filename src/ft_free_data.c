/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 20:21:44 by dbennie           #+#    #+#             */
/*   Updated: 2019/10/18 20:21:45 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/lem-in.h"

void	ft_free_data(t_data *data)
{
	t_room	*tmp;

	while (data->rooms)
	{
		tmp = data->rooms;
		data->rooms = data->rooms->next;
		free(tmp->name);
		ft_free_links(tmp->links);
		if (tmp->room_out)
		{
			free(tmp->room_out->name);
			ft_free_links(tmp->room_out->links);
		}
		free(tmp->room_out);
		free(tmp);
	}
	ft_free_way(data->ways);
	ft_free_way(data->mod_ways);
}
