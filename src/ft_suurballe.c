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

static int	ft_duplicate_rooms(t_path *path)
{
	t_room	*in;
	t_room	*out;
	t_link	*link;
	char	*name;

	while (path)
	{
		if (!path->next || !path->next->next)
			return (0);
		in = path->next->room;
		name = ft_strdup(in->name); //
		if (!(out = ft_createroom(name)))
			return (-1);
		if (!(link = ft_createlink(path->room->room_double ? path->room->room_double : path->room)))
			return (-1);
		link->cost = -1;
		link->room_src = in;
		in->room_double = out;
		out->room_double = in;
		out->links = in->links;
		in->links = link;
		link = out->links;
		while(link)
		{
			if (link->room == path->room)
			{
				link->room = in;
				link->cost = 0;
				link = NULL;
			}
			else
				link = link->next;
		}
		path = path->next;
	}
	return (0);
}

static void	ft_direction(t_path *path)
{
	t_room	*room_src;
	t_room	*room_dst;
	t_link	*link;

	while(path)
	{
		room_src = path->room;
		link = room_src->links;
		if ((room_dst = (path->next) ? path->next->room : NULL))
		{
			while (link)
			{
				if (link->room == room_dst)
				{
					if (link->prev)
						link->prev->next = link->next;
					else
						room_src->links = link->next;
					if (link->next)
						link->next->prev = link->prev;
					free(link);
					link = NULL;
				}
				else
					link = link->next;
			}
			link = room_dst->links;
			while (link)
			{
				if (link->room == room_src)
				{
					link->cost = -1;
					link = NULL;
				}
				else
					link = link->next;
			}
		}
		path = path->next;
	}
}

int 		ft_suurballe(t_data *data)
{
//	if ((ft_bfs(data)) < 0)
//		return (error);
//	if ((ft_bfs(data)) == 0) //netu korotkogo puti
//
	if ((ft_dijkstra(data)) > 0) // est put
	{
		//proverka na kolichestvo putey
		//proverka na potoki
		ft_direction(data->ways->path);
		if ((ft_duplicate_rooms(data->ways->path)) < 0)
			return (-1);
		return (1);
	}
	return (0);
}

//сдулать link_in вместо комнат
//продумать реализацию дейкстры через BFS