/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dijkstra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:06:35 by dbennie           #+#    #+#             */
/*   Updated: 2019/11/28 18:06:36 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	null(t_room *room)
{
	while (room)
	{
		room->room_parrent = NULL;
		room->cost = 0x7FFFFFFF;
		if (room->room_out)
		{
			room->room_out->room_parrent = NULL;
			room->room_out->cost = 0x7FFFFFFF;
		}
		else if (room->room_in)
		{
			room->room_in->room_parrent = NULL;
			room->room_in->cost = 0x7FFFFFFF;
		}
		room = room->next;
	}
}

static void	create_way(t_path *path, int path_cost, t_way **ways)
{
	t_way	*way;

	if (!(way = (t_way *)malloc(sizeof(t_way))))
		ft_perror();
	way->path = path;
	way->path_number = (*ways) ? (*ways)->path_number + 1 : 1;
	way->path_cost = path_cost;
	way->ants = 0;
	way->prev = NULL;
	way->next = *ways;
	if (*ways)
		(*ways)->prev = way;
	*ways = way;
}

static void	path(t_room *room, t_room *start, t_way **ways)
{
	t_path	*tmp;
	t_path	*path;
	t_room	*room_p;
	t_link	*link_p;
	int		path_cost;

	path_cost = room->cost;
	(!(path = (t_path *)malloc(sizeof(t_path)))) ? ft_perror() : 0;
	path->room = room;
	path->next = NULL;
	path->prev = NULL;
	while (room && room != start)
	{
		room_p = room->room_parrent;
		link_p = room_p->links;
		while (link_p && link_p->room != room)
			link_p = link_p->next;
		if (link_p && link_p->room == room)
		{
			tmp = path;
			(!(path = (t_path *)malloc(sizeof(t_path)))) ? ft_perror() : 0;
			path->room = room_p;
			path->next = tmp;
			path->prev = NULL;
			if (tmp)
				tmp->prev = path;
		}
		room = room->room_parrent;
	}
	create_way(path, path_cost, ways);
}

static void	change_cost(t_room *room, t_link *link, t_room *start, int *flag)
{
		link->room->cost = room->cost + link->cost;
		link->room->room_parrent = room;
		*flag = 1;
}

static void turn(t_room *room, t_room *start, int *flag)
{
	t_link	*link;
	t_room	*room_d;

	if (room->cost != 0x7FFFFFFF)
	{
		link = room->links;
		while (link)
		{
			if (room->cost + link->cost < link->room->cost && link->room != start)
				change_cost(room, link, start, flag);
			link = link->next;
		}
	}
	if ((room_d = room->room_out) && room_d->cost != 0x7FFFFFFF)
	{
		link = room_d->links;
		while (link)
		{
			if (room_d->cost + link->cost < link->room->cost && link->room != start)
				change_cost(room_d, link, start, flag);
			link = link->next;
		}
	}
}

int			ft_ford(t_data *data)
{
	int		k;
	t_room	*room;
	int		flag;

	k = data->rooms_count - 1;
	flag = 1;
	data->start->cost = 0;
	while (--k && flag == 1)
	{
		flag = 0;
		room = data->rooms;
		(room == data->end) ? room = room->next : 0;
		while (room)
		{
			turn(room, data->start, &flag);
			((room = room->next) == data->end) ? room = room->next : 0;
		}
	}
	//на ноль
	if (!data->end->room_parrent)
		return (0);
	path(data->end, data->start, &data->ways_dij);
	null(data->rooms);
	return (1);
}