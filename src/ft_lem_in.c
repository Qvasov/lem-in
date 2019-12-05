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

void	ft_copy_char(char *str, int *i, char c)
{
	if (*i == BUFF_SIZE - 1)
	{
		write (1, str, *i + 1);
		ft_bzero(str, BUFF_SIZE);
		*i = 0;
	}
	str[++*i] = c;
}

void	ft_join(char *str, int *i, size_t ant, char *name)
{
	long	j;

	j = -1;
	ft_copy_char(str, i, 'L');
	while (ant)
	{
		ft_copy_char(str, i, ant % 10 + '0');
		ant = ant / 10;
	}
	ft_copy_char(str, i, '-');
	while (name[++j])
		ft_copy_char(str, i, name[j]);
}

void	ft_lem_in(t_way *ways, size_t steps, t_room *start, t_room *end)
{
	t_way	*ptr_way;
	t_path	*path;
	size_t	ant;
	int		space;
	char	str[BUFF_SIZE];
	int		i;

	ant = 0;
	ft_bzero(str, BUFF_SIZE);
	i = -1;
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
					(space) ? ft_copy_char(str, &i, ' ') : (space = 1);
					ft_join(str, &i, ant, path->prev->room->name);
//					(space) ? write(1, " ", 1) : (space = 1);
//					ft_printf("L%llu-%s", ant, path->prev->room->name);
					path->prev->room->ant = (path->prev->room != end) ?
							ant : path->prev->room->ant + 1;
				}
				else if (path->room->ant && path->room != start && path->room != end)
				{
					(space) ? ft_copy_char(str, &i, ' ') : (space = 1);
					ft_join(str, &i, ant, path->prev->room->name);
//					(space) ? write(1, " ", 1) : (space = 1);
//					ft_printf("L%llu-%s", path->room->ant, path->prev->room->name);
					path->prev->room->ant = (path->prev->room != end) ?
							path->room->ant : path->prev->room->ant + 1;
					path->room->ant = 0;
				}
				path = path->next;
			}
			ptr_way = ptr_way->next;
		}
		ft_copy_char(str, &i, '\n');
//		write(1, "\n", 1);
		--steps;
	}
	write (1, str, i + 1);
}
