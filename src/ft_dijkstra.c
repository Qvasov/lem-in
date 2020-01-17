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

static void		ft_create_way(t_path *path, int path_cost, t_way **ways)
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

static void		ft_path(t_link *tail, t_way **ways)
{
	t_path	*tmp;
	t_path	*path;
	int		path_cost;

	path = NULL;
	path_cost = tail->room->cost;
	while (tail)//loop of the cycle on b_loop when ways_count == 13
	{
		tmp = path;
		if (!(path = (t_path *)malloc(sizeof(t_path))))
			ft_perror();
		path->room = tail->room;
		path->next = tmp;
		path->prev = NULL;
		if (tmp)
			tmp->prev = path;
		tail = tail->parrent;
	}
	ft_create_way(path, path_cost, ways);
}

static t_link	*ft_link_start(t_room *start)
{
	t_link		*ptr;

	ptr = (start->links) ? start->links->room->links : NULL;
	if (ptr)
		start->cost = 0;
	while (ptr)
	{
		if (ptr->room->name == start->name)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

int				ft_dijkstra(t_data *data)
{
	t_link	*head;
	t_link	*tail;
	t_link	*end;

	head = ft_link_start(data->start);
	tail = head;
	end = NULL;
	while (head)
	{
		if (head->room->links && head->room != data->end)
			ft_turn(&head, &tail, &end, data);
		(head->room == data->end) ? end = head : 0;
		head = head->turn_next;
	}
	if (end)
	{
		ft_path(end, &data->ways_dij);
		ft_turn_null(tail);
		return (1);
	}
	return (0);
}

int	ft_ford(t_data *data)
{
	int		k;
	t_room	*room_p;
	t_room	*room_pd;
	t_link	*link_p;
	int		flag;

	k = data->rooms_count - 1;
	flag = 1;
	data->start->cost = 0;
	while (k && flag == 1)
	{
		flag = 0;
		room_p = data->rooms;
		while (room_p)
		{
			if (room_p == data->end)
			{
				room_p = room_p->next;
				continue ;
			}
			link_p = room_p->links;
			while (link_p)
			{
				if (room_p->cost + link_p->cost < link_p->room->cost && link_p->room != data->start)
				{
					link_p->room->cost = room_p->cost + link_p->cost;
					link_p->room->room_parrent = room_p;
					flag = 1;
				}
				link_p = link_p->next;
			}
			if ((room_pd = room_p->room_out) || ((room_pd = room_p->room_in)))
			{
				link_p = room_pd->links;
				while (link_p)
				{
					if (room_pd->cost + link_p->cost < link_p->room->cost && link_p->room != data->start)
					{
						link_p->room->cost = room_pd->cost + link_p->cost;
						link_p->room->room_parrent = room_pd;
						flag = 1;
					}
					link_p = link_p->next;
				}
			}
			room_p = room_p->next;
		}
		--k;
	}
	if (!data->end->room_parrent)
		return (0);
	t_path	*tmp;
	t_path	*path;
	int		path_cost;
	t_room	*room;

	room = data->end;
	path_cost = room->cost;
	if (!(path = (t_path *)malloc(sizeof(t_path))))
		ft_perror();
	path->room = data->end;
	path->next = NULL;
	path->prev = NULL;
	while (room && room != data->start)
	{
		room_p = room->room_parrent;
		link_p = room_p->links;
		while (link_p && link_p->room != room)
			link_p = link_p->next;
		if (link_p && link_p->room == room)
		{
			tmp = path;
			if (!(path = (t_path *)malloc(sizeof(t_path))))
				ft_perror();
			path->room = room_p;
			path->next = tmp;
			path->prev = NULL;
			if (tmp)
				tmp->prev = path;
		}
		room = room->room_parrent;
	}
	ft_create_way(path, path_cost, &data->ways_dij);
	room_p = data->rooms;
	while (room_p)
	{
		room_p->room_parrent = NULL;
		room_p->cost = 0x5FFFFFFF;
		if ((room_pd = room_p->room_out) || (room_pd = room_p->room_in))
		{
			room_pd->room_parrent = NULL;
			room_pd->cost = 0x5FFFFFFF;
		}
		room_p = room_p->next;
	}
	return (1);
}