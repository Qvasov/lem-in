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

static int	ft_min_steps_for_ants(t_way *way, int ants)
{
	int	steps;
	int	ost;
	int	tmp;

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

static t_var	*ft_cmp_vars(t_var *vars)
{
	t_var	*ptr;
	int		best_steps;
	t_var	*best_var;

	ptr = vars;
	best_steps = ptr->steps;
	best_var = ptr;
	while ((ptr = ptr->next))
		if (ptr->steps < best_steps)
		{
			best_steps = ptr->steps;
			best_var = ptr;
		}
	if (!best_var)
		ft_error(1);

	return (best_var);
}

static int	number_of_paths(t_room *start, t_room *end)
{
	int		i;
	int		j;
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
	int		new_steps;
	t_var	*var;

	new_steps = 0;
	data->ways_count = number_of_paths(data->start, data->end); //находит ВОЗМОЖНОЕ наибольшее кол-во непересекающихся путей
	while (data->ways_count > 0 && ft_suurballe(data)) //находит короткий путь и "блокирует" его //b_loop loops when ways_count == 13
	{
		--data->ways_count; //Удаление из возможнных
		if ((new_ways = ft_paths_ascending(data->start, data->end)))
			new_steps = ft_min_steps_for_ants(new_ways, data->ants); //sprosit u dimasa pro segu
		!(var = (t_var *)malloc(sizeof(t_var))) ? ft_perror() : 0;
		var->ways = new_ways;
		var->steps = new_steps;
		var->next = NULL;
		if (!data->vars)
			data->vars = var;
		else
		{
			var->next = data->vars;
			data->vars = var;
		}
	}
	data->vars == NULL ? ft_error(10) : 1;//added condition to avoid SEG when no ways found
	data->best_var = ft_cmp_vars(data->vars);
	data->old_ways = data->best_var->ways;
	data->old_steps = data->best_var->steps;
}
