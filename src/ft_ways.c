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

int	ft_check_ways(t_way	*ways, size_t ants)
{
	t_way	*ptr;
	size_t	sum;

	ptr = ways;
	sum = 0;
	while (ptr)
	{
		sum = sum + ptr->path_cost;
		ptr = ptr->next;
	}
	steps = sum / ways->path_number;
	if (есть еще ВОЗМОЖНЫЕ пути && муравьев больше максимального потока)
}

int	ft_mod_ways(t_room *start, t_link *link, t_way *ways)
{
	t_path	*path;
	t_path	*tmp;
	t_link	*ptr;

	if (ways->path_number <= 1)
		return (0);
	path = NULL;
	ptr = link;
	while (link->room_src != start)
	{
		while (link)
		{
			if (link->cost < ptr->cost)
				ptr = link;
			link = link->next;
		}
		tmp = path;
		if (!(path = (t_path *)malloc(sizeof(t_path))))
			return; //(ft_free_path(&tmp)); // продумать очистку
		path->room = ptr->room_src;
		path->next = tmp;
		link = ptr->room->links;
	}
	tmp = path;
	if (!(path = (t_path *)malloc(sizeof(t_path))))
		return; //(ft_free_path(&tmp)); // продумать очистку
	path->room = link->room_src;
	path->next = tmp;
	
	return (0);
}

int	ft_ways(t_data *data)
{
	int	s;

	ft_number_of_paths(data);
	while ((s = ft_suurballe(data)) > 0)
	{
		ft_mod_ways(data->start, data->end->links, data->ways);
		ft_check_ways(data->ways, data->ants);
		//proverka na potoki
		//proverka na kolichestvo putey
	}
	if (s < 0)
		return (-1);
	return (0);
}