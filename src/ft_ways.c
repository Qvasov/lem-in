/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ways.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:37:00 by dbennie           #+#    #+#             */
/*   Updated: 2019/11/14 17:37:00 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/lem-in.h"

void	ft_free_old_way(t_way **old)
{
	t_path	*ptr_p;
	t_path	*path;
	t_way	*ptr_w;

	while (*old)
	{
		path = (*old)->path;
		while (path)
		{
			ptr_p = path;
			path = path->next;
			free(ptr_p);
		}
		ptr_w = *old;
		*old = (*old)->next;
		free(ptr_w);
	}
}

static long	ft_number_of_paths(t_room *start, t_room *end)
{
	long	i;
	long	j;
	t_link	*ptr;

	i = 0;
	ptr = start->links;
	while (ptr)
	{
		++i;
		ptr = ptr->next;
	}
	j = 0;
	ptr = end->links;
	while (ptr)
	{
		++j;
		ptr = ptr->next;
	}
	return (j < i ? j : i);
}

int	ft_min_steps_for_ants(t_way *way, size_t ants)
{
	size_t	steps;
	size_t	frac;
	size_t	tmp;

	steps = 0;
	frac = 0;
	while (way)
	{
		if (!way->prev)
			steps = way->path_cost + ants - 1;
		else if (steps > way->path_cost)
		{
			tmp = steps - (way->path_cost - 1);
			steps = steps - tmp;
			tmp = (frac) ? tmp - frac : tmp;
			steps += ((tmp * (way->path_number - 1) + frac) % way->path_number) ?
					 (tmp * (way->path_number - 1) + frac) / way->path_number + 1 :
					 (tmp * (way->path_number - 1) + frac) / way->path_number;
			frac = (tmp * (way->path_number - 1) + frac) % way->path_number;
		}
		else if (steps <= way->path_cost)
			break;
		way = way->next;
	}
	return (steps);
}

int	ft_cmp_ways(t_way **old, t_way **new, size_t *steps_old, size_t ants)
{
	size_t	steps_new;

	steps_new = ft_min_steps_for_ants(*new, ants);
	if (steps_new < *steps_old)
	{
		ft_free_old_way(old);
		*steps_old = steps_new;
		*old = *new;
		return (1);
	}
	return (0);
}

t_path	*ft_path(t_link *tail, size_t *cost, t_room *end)
{
	t_path	*path;
	t_path	*tmp;
	t_path	*start_path;

	start_path = NULL;
	path = NULL;
	while (tail)
	{
		tmp = path;
		if (!(path = (t_path *)malloc(sizeof(t_path))))
			return (NULL); //(ft_free_path(&tmp)); // продумать очистку
		path->room = (tail->room->room_in) ? tail->room->room_in : tail->room;
		if (!start_path)
			start_path = path;
		if (tmp)
			tmp->next = path;
		++(*cost);
		tail = tail->parrent;
	}
	tmp = path;
	if (!(path = (t_path *)malloc(sizeof(t_path))))
		return (NULL); //(ft_free_path(&tmp)); // продумать очистку
	path->room = end;
	path->next = NULL;
	if (tmp)
		tmp->next = path;
	return (start_path);
}

t_way	*ft_add_path(t_link *tail, t_way *ways, t_room *end)
{
	t_path	*path;
	t_way	*way;
	size_t	cost;

	cost = 0;
	if (!(path = ft_path(tail, &cost, end)))
		return (NULL);
	if (!(way = (t_way *)malloc(sizeof(t_way))))
		return (NULL); // продумать очистку
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

t_way	*ft_paths_ascending(t_room *start, t_room *end)
{
	t_link	*turn_head;
	t_link	*turn_tail;
	t_link	*link;
	t_way	*ways;
	t_way	*ways_begin;

	ways = NULL;
	ways_begin = NULL;
	turn_head = end->links;
	while (turn_head && turn_head->cost != -1)
		turn_head = turn_head->next;
	if (!turn_head)
		return (NULL);
	turn_tail = turn_head;
	link = turn_head->next;
	while (link)
	{
		if (link->cost == -1)
		{
			turn_tail->turn_next = link;
			turn_tail = turn_tail->turn_next;
		}
		link = link->next;
	}
	while (turn_head)
	{
		link = (turn_head->room->room_in) ? turn_head->room->room_in->links : turn_head->room->links;
		while (link)
		{
			while (link && link->cost != -1)
				link = link->next;
			if (link && link->cost == -1)
			{
				turn_tail->turn_next = link;
				link->parrent = turn_head;
				turn_tail = turn_tail->turn_next;
				if (turn_tail->room == start)
				{
					if (!(ways = ft_add_path(turn_tail, ways, end)))
						return (NULL);
					if (!ways_begin)
						ways_begin = ways;
				}
				break;
			}
		}
		turn_head = turn_head->turn_next;
	}
	//зануление turn;
	turn_head = end->links;
	while (turn_head && turn_head->cost != -1)
		turn_head = turn_head->next;
	while (turn_head)
	{
		turn_tail = turn_head->turn_next;
		turn_head->turn_next = NULL;
		turn_head->parrent = NULL;
		turn_head = turn_tail;
	}
	return (ways_begin);
}

int	ft_ways(t_data *data)
{
	t_way	*new_ways;
	size_t	steps;
	int	s;

	steps = 0;
	data->ways_count = ft_number_of_paths(data->start, data->end);
	while (data->ways_count > 0 && (s = ft_suurballe(data)) > 0)
	{
		--data->ways_count;
		new_ways = ft_paths_ascending(data->start, data->end);
		if (!data->mod_ways)
		{
			data->mod_ways = new_ways;
			steps = ft_min_steps_for_ants(new_ways, data->ants);
		}
		else if (!ft_cmp_ways(&data->mod_ways, &new_ways, &steps, data->ants))
			break;
	}
	if (s < 0)
		return (-1);
	return (0);
}