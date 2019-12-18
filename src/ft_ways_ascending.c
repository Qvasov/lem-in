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

static t_path	*ft_path(t_link *tail, size_t *cost, t_room *end)
{
	t_path	*path;
	t_path	*tmp;

	path = NULL;
	while (tail)
	{
		tmp = path;
		if (!(path = (t_path *)malloc(sizeof(t_path))))
			return (ft_free_path(tmp));
		path->room = (tail->room->room_in) ? tail->room->room_in : tail->room;
		path->next = tmp;
		if (tmp)
			tmp->prev = path;
		++(*cost);
		tail = tail->parrent;
	}
	tmp = path;
	if (!(path = (t_path *)malloc(sizeof(t_path))))
		return (ft_free_path(tmp));
	path->room = end;
	path->next = tmp;
	path->prev = NULL;
	if (tmp)
		tmp->prev = path;
	return (path);
}

static t_way	*ft_add_path(t_link *tail, t_way *ways, t_room *end)
{
	t_path	*path;
	t_way	*way;
	size_t	cost;

	cost = 0;
	if (!(path = ft_path(tail, &cost, end)))
		return (NULL);
	if (!(way = (t_way *)malloc(sizeof(t_way))))
		return (ft_free_path(path));
	way->path = path;
	way->path_cost = cost;
	if (ways)
		ways->next = way;
	way->prev = ways;
	way->next = NULL;
	way->path_number = ways ? ways->path_number + 1 : 1;
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
			if (tail->room == start && !(ways = ft_add_path(tail, ways, end)))
				return (NULL);
			if (!ways_begin)
				ways_begin = ways;
		}
		head = head->turn_next;
	}
	return (ways_begin);
}
