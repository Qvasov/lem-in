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

	if (!data->rooms)
		return;
	while (data->rooms->next)
	{
		tmp = data->rooms;
		data->rooms = data->rooms->next;
		free(tmp->name);
		ft_free_links(tmp->links);
		free(tmp);
	}
	free(data->rooms->name);
	ft_free_links(data->rooms->links);
	free(data->rooms);

	t_path	*ptr;
	while (data->ways)
	{
		ptr = data->ways;
		data->ways = data->ways->next;
		free(ptr);
	}
}
