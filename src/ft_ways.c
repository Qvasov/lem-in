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

#include "lemin.h"

static int	ft_min_steps_for_ants(t_way *way, size_t ants)
{
	size_t	steps;
	size_t	ost;
	size_t	tmp;

	steps = 0;
	ost = 0;
	while (way)
	{
		if (!way->prev)
			steps = way->path_cost + ants - 1;
		else if (steps > way->path_cost)
		{
			tmp = steps - (way->path_cost - 1);
			steps = steps - tmp;
			tmp = (ost) ? tmp - ost : tmp;
			steps += ((tmp * (way->path_number - 1) + ost) % way->path_number) ?
				(tmp * (way->path_number - 1) + ost) / way->path_number + 1 :
				(tmp * (way->path_number - 1) + ost) / way->path_number;
			ost = (tmp * (way->path_number - 1) + ost) % way->path_number;
		}
		else if (steps <= way->path_cost)
			break ;
		way = way->next;
	}
	return (steps);
}

static int	ft_cmp_ways(t_way **old, t_way **new, size_t *steps_old,
		size_t ants)
{
	size_t	steps_new;

	steps_new = ft_min_steps_for_ants(*new, ants);
	if (steps_new < *steps_old)
	{
		ft_free_way(*old);
		*steps_old = steps_new;
		*old = *new;
		return (1);
	}
	return (0);
}

static long	number_of_paths(t_room *start, t_room *end)
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

int			ft_ways(t_data *data)
{
	t_way	*new_ways;
	size_t	steps;
	int		suur;

	steps = 0;
	data->ways_count = number_of_paths(data->start, data->end); //находит ВОЗМОЖНОЕ наибольшее кол-во непересекающихся путей
	while (data->ways_count > 0 && (suur = ft_suurballe(data)) > 0) //находит короткий путь и "блокирует его"
	{
		--data->ways_count; //Удаление из возможнных
		if (!(new_ways = ft_paths_ascending(data->start, data->end)))
			return (-1);
		if (!data->mod_ways)
		{
			data->mod_ways = new_ways;
			steps = ft_min_steps_for_ants(new_ways, data->ants);
		}
		else if (!ft_cmp_ways(&data->mod_ways, &new_ways, &steps, data->ants))
			break ;
	}
	if (suur < 0)
		return (-1);
	data->steps = steps;
	return (0);
}
