/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ways_ascending.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:56:17 by dbennie           #+#    #+#             */
/*   Updated: 2019/12/04 16:56:18 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_path	*ft_path(t_link *head, int *cost, t_room *end)
{
	t_path	*path;
	t_path	*tmp;

	path = NULL;
	while (head)
	{
		tmp = path;
		if (!(path = (t_path *)malloc(sizeof(t_path))))
			ft_perror();
		path->room = (head->room->room_in) ? head->room->room_in : head->room;
		path->next = tmp;
		if (tmp)
			tmp->prev = path;
		++(*cost);
		head = head->parrent;
	}
	tmp = path;
	if (!(path = (t_path *)malloc(sizeof(t_path)))) //создание на path на end
		ft_perror();
	path->room = end;
	path->next = tmp;
	path->prev = NULL;
	if (tmp)
		tmp->prev = path;
	return (path);
}

static t_way	*ft_add_path(t_link *head, t_way *ways, t_room *end)
{
	t_path	*path;
	t_way	*way;
	int		cost;

	cost = 0;
	path = ft_path(head, &cost, end);
	if (!(way = (t_way *)malloc(sizeof(t_way))))
		ft_perror();
	way->path = path;
	way->path_cost = cost;
	if (ways)
		ways->next = way;
	way->prev = ways;
	way->next = NULL;
	way->path_number = (ways) ? ways->path_number + 1 : 1;
	ways = way;
	return (ways);
}

t_way			*ft_ways_ascending(t_link *head, t_link *tail,
													t_room *start, t_room *end)
{
	t_link	*link;
	t_way	*ways;
	t_way	*ways_begin;

	ways = NULL;
	ways_begin = NULL;
	while (head)
	{
		link = (head->room->room_in) ?
				head->room->room_in->links : head->room->links;
		while (link && link->cost != -1)
			link = link->next;
		if (link && link->cost == -1)
		{
			tail->turn_next = link;
			link->parrent = head;
			tail = tail->turn_next;
		}
		if (head->room == start)
			ways = ft_add_path(head, ways, end);
		if (!ways_begin && ways)
			ways_begin = ways;
		head = head->turn_next;
	}
	return (ways_begin);
}
