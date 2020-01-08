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
	ost = 0; //переменная для остатка шагов
	while (way)
	{
		if (!way->prev)
			steps = way->path_cost + ants - 1;
		else if (steps > way->path_cost)
		{
			tmp = steps - (way->path_cost - 1); //кол-во шагов подлежащие пересмотру
			steps = steps - tmp;	//кол-во шагов которые не подлежащие пересмотру
			tmp = (ost) ? tmp - 1: tmp;
			steps += ((tmp * (way->path_number - 1)) + ost) / way->path_number; //новое кол-во шагов для иекущего пути
			ost = (tmp * (way->path_number - 1) + ost) % way->path_number; //кол-во муравьев в остатке (в неполном шаге)
			steps = (ost) ? steps + 1 : steps;
		}
		else if (steps <= way->path_cost)
			break ;
		way = way->next;
	}
	return (steps);
}

static int	ft_cmp_ways(t_data *data, t_way **new_way, size_t new_steps)
{
	if (new_steps < data->old_steps)
	{
		ft_free_way(data->old_ways);
		data->old_ways = *new_way;
		data->old_steps = new_steps;
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

void		ft_ways(t_data *data)
{
	t_way	*new_ways;
	size_t	new_steps;

	new_steps = 0;
	data->ways_count = number_of_paths(data->start, data->end); //находит ВОЗМОЖНОЕ наибольшее кол-во непересекающихся путей
	while (data->ways_count > 0 && ft_suurballe(data)) //находит короткий путь и "блокирует" его //loop_test loops when ways_count == 17
	{
		--data->ways_count; //Удаление из возможнных
		if ((new_ways = ft_paths_ascending(data->start, data->end)))
			new_steps = ft_min_steps_for_ants(new_ways, data->ants); //sprosit u dimasa pro segu
		if (!data->old_ways)
		{
			data->old_ways = new_ways;
			data->old_steps = new_steps;
		}
		else if (!ft_cmp_ways(data, &new_ways, new_steps))
			break ;
	}
	data->old_ways == NULL ? ft_error(10) : 1;//added condition to avoid SEG when no ways found
}
