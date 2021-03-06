/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddarell <ddarell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 22:28:23 by dbennie           #+#    #+#             */
/*   Updated: 2020/01/12 13:26:38 by ddarell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	ft_zerodata(t_data *data)
{
	data->ants = 0;
	data->start = NULL;
	data->end = NULL;
	data->rooms = NULL;
	data->rooms_count = 0;
	data->vars = NULL;
	data->best_var = NULL;
	data->ways_dij = NULL;
	data->ways_count = 0;
	data->i_rooms_start = 0;
	data->i_rooms_end = 0;
	data->i_links_start = 0;
	data->i_links_start = 0;
	data->i_links_end = 0;
	data->i_start = 0;
	data->i_end = 0;
	data->flags.fd_path = NULL;
	data->flags.ways = 0;
}

static void	print_n_free_map_data(char **map_data)
{
	ft_printf("%s\n", *map_data);
	free(*map_data);
	*map_data = NULL;
}

static void ft_print_ways(t_way *way, int steps)
{
	t_path	*ptr;
	t_way	*w;
	int 	ways_count;

	w = way;
	ways_count = (w->ants) ? 1 : 0;
	while ((w = w->next) && w->ants)
		++ways_count;
	ft_printf("Total lines: %d\nTotal ways:  %d\n"
			  " ANTS | WAYS\n", steps, ways_count);
	while (way && way->ants > 0)
	{
		ft_printf("%5d | ", way->ants);
		ptr = way->path;
		while (ptr && ptr->next)
			ptr = ptr->next;
		while (ptr)
		{
			ft_printf("%s", ptr->room->name);
			(ptr->prev) ? ft_printf(" - ") : ft_printf("\n");
			ptr = ptr->prev;
		}
		way = way->next;
	}
}

int			main(int ac, char **av)
{
	t_data	data;
	char	**str_split;
	char	*map_data;

	ft_zerodata(&data);
	ft_flags_lemin(&data.flags, ac, av);
	map_data = ft_lemin_read(&data.flags, &str_split);
	ft_valid(&data, str_split);
	ft_parse_data(&data, str_split);
	ft_free_str_split(&str_split);
	ft_match_rooms_off(data.rooms, data.start, data.end);
	ft_ways(&data);
	print_n_free_map_data(&map_data);
	ft_lemin(&data);
	(data.flags.ways == 1) ? ft_print_ways(data.best_var->ways, data.best_var->steps) : 0;
	ft_free_data(&data);
	return (0);
}
