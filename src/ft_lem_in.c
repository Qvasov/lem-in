/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_in.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:16:01 by dbennie           #+#    #+#             */
/*   Updated: 2019/12/04 17:16:02 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/lem-in.h"

void	ft_lem_in(t_way *ways, size_t steps, t_room *start, t_room *end)
{
	t_way	*ptr_way;
	t_path	*path;
	size_t	ant;
	int		space;

	ant = 0;
	while (steps)
	{
		space = 0;
		ptr_way = ways;
		while (ptr_way)
		{
			path = ptr_way->path;
			while (path)
			{
				if (path->room == start && (steps >= ptr_way->path_cost || ptr_way->path_number == 1)
				&& start->ant)
				{
					++ant;
					--start->ant;
					(space) ? write(1, " ", 1) : (space = 1);
					ft_printf("L%llu-%s", ant, path->prev->room->name);
					path->prev->room->ant = (path->prev->room != end) ?
							ant : path->prev->room->ant + 1;
				}
				else if (path->room->ant && path->room != start && path->room != end)
				{
					(space) ? write(1, " ", 1) : (space = 1);
					ft_printf("L%llu-%s", path->room->ant, path->prev->room->name);
					path->prev->room->ant = (path->prev->room != end) ?
							path->room->ant : path->prev->room->ant + 1;
					path->room->ant = 0;
				}
				path = path->next;
			}
			ptr_way = ptr_way->next;
		}
		write(1, "\n", 1);
		--steps;
	}
}
