/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_suurballe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:27:26 by dbennie           #+#    #+#             */
/*   Updated: 2019/11/14 17:27:26 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/lem-in.h"

static int	ft_out(t_room *in, t_room *out, t_room *room)
{
	t_link	*link;

	if (!(out = ft_createroom(in->name)))
		return (-1);
	in->room_out = out;
	out->room_in = in;
	if (!(link = ft_createlink(room->room_out ? room->room_out : room)))
		return (-1);
	link->cost = -1;
	link->room_src = in;
	out->links = in->links;
	in->links = link;
	link = out->links;
	while (link && link->room != room)
		link = link->next;
	if (link && link->room == room)
	{
		link->room = in;
		link->room_src = out;
		link->cost = 0;
	}
	else
		in->links = link;
	return (0);
}

static int	ft_duplicate_rooms(t_path *path)
{
	t_room	*in;
	t_room	*out;
	t_link	*link;

	while (path)
	{
		if (!path->next || !path->next->next)
			return (0);
		in = path->next->room;
		out = NULL;
		if (!in->room_out && !in->room_in)
			return (ft_out(in, out, path->room));
		else if (in->room_out && !path->room->room_in)
		{
			out = path->room;
			link = in->links;
			while (link && link->room != out)
				link = link->next;
			if (link && link->room == out)
				link->room = out->room_out;
		}
		path = path->next;
	}
	return (0);
}

int			ft_suurballe(t_data *data)
{
	int		d;

	if ((d = ft_dijkstra(data)) > 0)
	{
		ft_direction(data->ways->path);
		if ((ft_duplicate_rooms(data->ways->path)) < 0)
			return (-1);
		return (1);
	}
	if (d < 0)
		return (-1);
	return (0);
}
