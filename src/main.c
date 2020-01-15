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

static void	print_n_free_map_data(char **map_data)
{
	ft_printf("%s\n", *map_data);
	free(*map_data);
	*map_data = NULL;
}

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
	data->i_ants = 0;
	data->i_rooms_start = 0;
	data->i_rooms_end = 0;
	data->i_links_start = 0;
	data->i_links_start = 0;
	data->i_links_end = 0;
	data->i_start = 0;
	data->i_end = 0;
}

static void	print_ways(t_way *way)
{
	t_path	*ptr;
	t_way	*p;
	int 	ways_count;

	p = way;
	ways_count = way->path_number;
	while ((p = p->next))
		++ways_count;
	ft_printf("\nTotal ways: %d\n", ways_count);
	while (way)
	{
		ft_printf("%3d| ", way->ants);
		ptr = way->path;
		while (ptr && ptr->next)
			ptr = ptr->next;
		while (ptr)
		{
			ft_printf("%s", ptr->room->name);
			if (ptr->prev)
				ft_printf(" - ");
			else
				ft_printf("\n");
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
	t_flags	flags;

	ft_flags_lemin(&flags, ac, av);
	map_data = ft_lemin_read(&flags, &str_split);
	ft_zerodata(&data);
	ft_valid(&data, str_split);
	ft_parse_data(&data, str_split);
	ft_free_str_split(&str_split);
	ft_ways(&data);
	print_n_free_map_data(&map_data);
	ft_lemin(&data);
	(flags.ways == 1) ? print_ways(data.best_var->ways) : 0;
//	print_ways(data.ways_dij); //для дебага
	ft_free_data(&data);
	return (0);
}
