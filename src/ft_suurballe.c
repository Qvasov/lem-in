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

	while (path)
	{
		if (!path->next || !path->next->next)
			return (0);
		in = path->next->room;
		out = NULL;
		if (!in->room_out && !in->room_in && !(out = ft_createroom(in->name)))
			return (-1);
		if (out)
		{
			in->room_out = out;
			out->room_in = in;
			if (!(link = ft_createlink(path->room->room_out ? path->room->room_out : path->room)))
				return (-1);
			link->cost = -1;
			link->room_src = in;
			out->links = in->links;
			in->links = link;
			link = out->links;
			while (link && link->room != path->room)
				link = link->next;
			if (link && link->room == path->room)
			{
				link->room = in;
				link->room_src = out;
				link->cost = 0;
			}
			else
				in->links = link;
		}
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

static void ft_delete_link(t_room *src, t_room *dst)
{
	t_link	*link;

	link = dst->links;
	while (link && link->room != src)
		link = link->next;
	if (link && link->room == src)
	{
		if (link->prev)
			link->prev->next = link->next;
		else
			dst->links = link->next;
		if (link->next)
			link->next->prev = link->prev;
		free(link);
	}
}

static void	ft_direction(t_path *path)
{
	t_room	*room_src;
	t_room	*room_dst;
	t_link	*link;
//	t_room	*src;

	while(path && path->next)
	{
		room_src = path->room;
//		src = room_src;
		room_dst = path->next->room;
		if (!(room_src->room_in || room_src->room_out) && !(room_dst->room_in || room_dst->room_out))
			ft_delete_link(room_src, room_dst);
		else if (!(room_src->room_in || room_src->room_out) && room_dst->room_out)
			ft_delete_link(room_src, room_dst->room_out);
		else if (!(room_src->room_in || room_src->room_out) && room_dst->room_in)
			ft_delete_link(room_src, room_dst->room_in);
		else if (room_src->room_in && !(room_dst->room_in || room_dst->room_out))
			ft_delete_link(room_src->room_in, room_dst);
		else if (room_src->room_out && !(room_dst->room_in || room_dst->room_out))
			ft_delete_link(room_src->room_out, room_dst);
//		if (!(room_src->room_out || room_src->room_in)  || !(room_dst->room_in || room_dst->room_out))
//		{
//			link = room_dst->links;
//			while (1) //можно f как флаг что отчистилось
//			{
//				if (!link && (room_dst->room_out || room_dst->room_in))
//					link = room_dst->room_out->links;
//				else if (!link && !(room_dst->room_out || room_dst->room_in))
//				{
//					src = (room_src->room_in) ? room_src->room_in : room_src->room_out;
//					link = room_dst->links;
//				}
//				if (!link)
//					break;
//				if (link->room == src) //ili room_src
//				{
//					if (link->prev)
//						link->prev->next = link->next;
//					else
//						room_dst->links = link->next;
//					if (link->next)
//						link->next->prev = link->prev;
//					free(link);
//					break;
//				}
//				link = link->next;
//			}
//		}
		link = room_src->links;
		while (link && link->room != room_dst)
			link = link->next;
		if (link && link->room == room_dst)
		{
			if (link->prev)
				link->prev->next = link->next;
			else
				room_src->links = link->next;
			if (link->next)
				link->next->prev = link->prev;
			link->cost = (link->cost == -1) ? 1 : -1;
			link->room = room_src;
			link->room_src = room_dst;
			link->prev = NULL;
			link->next = room_dst->links;
			if (room_dst->links)
				room_dst->links->prev = link;
			room_dst->links = link;
		}
		path = path->next;
	}
}

int 		ft_suurballe(t_data *data)
{
	int	d;

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
