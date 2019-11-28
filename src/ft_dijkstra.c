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

#include "inc/lem-in.h"

static int		ft_create_way(t_path *path, size_t path_cost, t_way **ways)
{
	t_way	*way;

	if (!(way = (t_way *)malloc(sizeof(t_way))))
		return (ft_free_path(path));
	way->path = path;
	way->next = *ways;
	if (*ways)
		(*ways)->prev = way;
	way->path_number = (*ways) ? (*ways)->path_number + 1 : 1;
	way->path_cost = path_cost;
	way->prev = NULL;
	*ways = way;
	return (1);
}

static int		ft_path(t_link *tail, t_way **ways)
{
	t_path	*tmp;
	t_path	*path;
	size_t	path_cost;

	path = NULL;
	path_cost = tail->room->cost;
	while (tail)
	{
		tmp = path;
		if (!(path = (t_path *)malloc(sizeof(t_path))))
			return (ft_free_path(tmp));
		path->room = tail->room;
		path->next = tmp;
		path->prev = NULL;
		if (tmp)
			tmp->prev = path;
		tail = tail->parrent;
	}
	if (!(ft_create_way(path, path_cost, ways)))
		return (0);
	return (1);
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
	t_link	*turn_head;
	t_link	*turn_tail;
	t_link	*end;

	turn_head = ft_link_start(data->start);
	turn_tail = turn_head;
	end = NULL;
	while (turn_head)
	{
		if (turn_head->room->links && turn_head->room != data->end)
			ft_turn(&turn_head, &turn_tail, &end, data->end);
		turn_head = turn_head->turn_next;
	}
	if (end)
	{
		if (!ft_path(end, &data->ways))
			return (-1);
		ft_turn_null(turn_tail);
		return (1);
	}
	return (0);
}
