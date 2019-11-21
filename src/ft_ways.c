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

static void	ft_number_of_paths(t_data *data)
{
	long	i;
	t_link	*ptr;

	i = 0;
	ptr = data->start->links;
	while (ptr)
	{
		++i;
		ptr = ptr->next;
	}
	data->ways_count = i;
	i = 0;
	ptr = data->end->links;
	while (ptr)
	{
		++i;
		ptr = ptr->next;
	}
	data->ways_count = (data->ways_count < i) ? data->ways_count : i;
}

int	ft_min_steps(t_way *way)
{
	size_t	min_cost;

	min_cost = way->path_cost;
	while (way)
	{
		if (way->path_cost < min_cost)
			min_cost = way->path_cost;
		way = way->next;
	}
	return (123);
}

//int	ft_check_ways(t_way	**old, t_way **new, size_t ants)
//{
//	t_way	*ptr;
//	size_t	steps_old;
//	size_t	steps_new;
//
//
//	ptr = ways;
//	sum = 0;
//	while (ptr)
//	{
//		sum = sum + ptr->path_cost;
//		ptr = ptr->next;
//	}
//	steps = sum / ways->path_number;
//	if (есть еще ВОЗМОЖНЫЕ пути && муравьев больше максимального потока)
//	очистка не нужного пути
//}

//void	ft_sort_ways_ascending(t_way **ways)
//{
//	size_t	min;
//	t_way	*ptr;
//	t_way	*tmp;
//
//	ptr = *ways;
//	min = ptr->path_cost;
//	while (ptr)
//	{
//		tmp = ptr;
//		while (tmp)
//		{
//			if (tmp->path_cost < min)
//				min = ptr->path_cost;
//			tmp = tmp->next;
//		}
//
//		ptr = ptr->next;
//	}
//}

//t_path	*ft_path(t_link *link, t_room *start, t_room *end, size_t *cost)
//{
//	t_path	*path;
//	t_path	*tmp;
//	t_link	*ptr;
//
//	path = NULL;
//	tmp = path;
//	if (!(path = (t_path *)malloc(sizeof(t_path))))
//		return (NULL); //(ft_free_path(&tmp)); // продумать очистку
//	path->room = end;
//	path->next = tmp;
//	end = link->room;
//	++(*cost);
//	while (end != start)
//	{
//		link = end->links;
//		ptr = link;
//		while (link)
//		{
//			if (link->cost < ptr->cost)
//				ptr = link;
//			link = link->next;
//		}
//		tmp = path;
//		if (!(path = (t_path *)malloc(sizeof(t_path))))
//			return (NULL); //(ft_free_path(&tmp)); // продумать очистку
//		path->room = ptr->room_src;
//		path->next = tmp;
//		end = ptr->room;
//		++(*cost);
//	}
//	tmp = path;
//	if (!(path = (t_path *)malloc(sizeof(t_path))))
//		return (NULL); //(ft_free_path(&tmp)); // продумать очистку
//	path->room = end;
//	path->next = tmp;
//	return (path);
//}

//t_way	*ft_paths(t_room *start, t_room *end)
//{
//	t_path	*path;
//	t_link	*link;
//	t_way	*ways;
//	t_way	*way;
//	size_t	cost;
//
//	ways = NULL;
//	link = end->links;
//	while (link)
//	{
//		if (link->cost == -1)
//		{
//			cost = 0;
//			if (!(path = ft_path(link, start, end, &cost)))
//				return (NULL);
//			if (!(way = (t_way *)malloc(sizeof(t_way))))
//				return (NULL); // продумать очистку
//			way->path = path;
//			way->path_cost = cost;
//			way->next = ways;
//			if (ways)
//				ways->prev = way;
//			way->path_number = ways ? ways->path_number + 1 : 1;
//			way->prev = NULL;
//			ways = way;
//		}
//		link = link->next;
//	}
//	return (ways);
//}

t_path	*ft_path(t_link *tail, size_t *cost, t_room *end)
{
	t_path	*path;
	t_path	*tmp;
	t_path	*start_path;

	start_path = NULL;
	path = NULL;
	while (tail)
	{
		if (tail->turn_next)
			tail->turn_next->parrent = NULL;
		tail->turn_next = NULL;
		tmp = path;
		if (!(path = (t_path *)malloc(sizeof(t_path))))
			return (NULL); //(ft_free_path(&tmp)); // продумать очистку
		path->room = tail->room;
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
		link = turn_head->room->links;
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
			else
				link = turn_head->room->room_double->links;
		}
		turn_head = turn_head->turn_next;
	}
	return (ways_begin);
}

int	ft_ways(t_data *data)
{
	t_way	*new_ways;
	int	s;

	ft_number_of_paths(data);
	while ((s = ft_suurballe(data)) > 0) //неправильно ссылки создаются в duplicate rooms
	{
		new_ways = ft_paths_ascending(data->start, data->end);
//		ft_sort_ways_ascending(&new_ways);
		if (!data->mod_ways)
		{
			data->mod_ways = new_ways;
			ft_min_steps(new_ways);
		}
//		else
//			ft_check_ways(&data->mod_ways, &new_ways, data->ants);
		//proverka na potoki
		//proverka na kolichestvo putey
	}
	if (s < 0)
		return (-1);
	return (0);
}