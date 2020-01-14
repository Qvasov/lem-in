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
//	data->ways = NULL;
	data->old_ways = NULL;
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

static void print_ways(t_way *way)
{
	t_path *ptr;
	while (way)
	{
		ptr = way->path;
		printf("%d) ", way->path_number);
		while(ptr)
		{
			printf("%s", ptr->room->name);
			if (ptr->room->room_in && !ptr->room->room_out)
				printf("o");
			else if (!ptr->room->room_in && ptr->room->room_out)
				printf("i");
			else if (!ptr->room->room_in && !ptr->room->room_out)
				printf("");
			if (ptr->next)
				printf(" - ");
			else
				printf("\n");
			ptr = ptr->next;
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

	print_ways(data.old_ways);

	data.start->ant = data.ants;
	print_n_free_map_data(&map_data);
	ft_lem_in(&data);
	ft_free_data(&data);
	return (0);
}
