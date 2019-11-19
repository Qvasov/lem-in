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

//int	ft_check_ways(t_way	**old, t_way **new, size_t ants)
//{
//	t_way	*ptr;
//	size_t	sum;
//	size_t	steps_old;
//	size_t	steps_new;
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

t_path	*ft_path(t_link *link, t_room *start, t_room *end, size_t *cost)
{
	t_path	*path;
	t_path	*tmp;
	t_link	*ptr;

	path = NULL;
	tmp = path;
	if (!(path = (t_path *)malloc(sizeof(t_path))))
		return (NULL); //(ft_free_path(&tmp)); // продумать очистку
	path->room = end;
	path->next = tmp;
	end = link->room;
	++(*cost);
	while (end != start)
	{
		link = end->links;
		ptr = link;
		while (link)
		{
			if (link->cost < ptr->cost)
				ptr = link;
			link = link->next;
		}
		tmp = path;
		if (!(path = (t_path *)malloc(sizeof(t_path))))
			return (NULL); //(ft_free_path(&tmp)); // продумать очистку
		path->room = ptr->room_src;
		path->next = tmp;
		end = ptr->room;
		++(*cost);
	}
	tmp = path;
	if (!(path = (t_path *)malloc(sizeof(t_path))))
		return (NULL); //(ft_free_path(&tmp)); // продумать очистку
	path->room = end;
	path->next = tmp;
	return (path);
}

t_way	*ft_paths(t_room *start, t_room *end)
{
	t_path	*path;
	t_link	*link;
	t_way	*ways;
	t_way	*way;
	size_t	cost;

	ways = NULL;
	link = end->links;
	while (link)
	{
		if (link->cost == -1)
		{
			cost = 0;
			if (!(path = ft_path(link, start, end, &cost)))
				return (NULL);
			if (!(way = (t_way *)malloc(sizeof(t_way))))
				return (NULL); // продумать очистку
			way->path = path;
			way->path_cost = cost;
			way->prev = ways;
			if (ways)
				ways->next = way;
			way->path_number = ways ? ways->path_number + 1 : 1;
			way->next = NULL;
			ways = way;
		}
		link = link->next;
	}
	return (ways);
}

int	ft_ways(t_data *data)
{
	t_way	*new_ways;
	int	s;

	ft_number_of_paths(data);
	while ((s = ft_suurballe(data)) > 0)
	{
		new_ways = ft_paths(data->start, data->end);
		if (!data->ways)
			data->ways = new_ways;
//		else
//			ft_check_ways(&data->ways, &new_ways, data->ants);
		//proverka na potoki
		//proverka na kolichestvo putey
	}
	if (s < 0)
		return (-1);
	return (0);
}