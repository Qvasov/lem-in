/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 22:28:23 by dbennie           #+#    #+#             */
/*   Updated: 2019/10/11 22:28:47 by dbennie          ###   ########.fr       */
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
	data->ways = NULL;
	data->old_ways = NULL;
	data->steps = 0;
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

int			main(int ac, char **av)
{
	t_data	data;
	char	**str_split;
	t_flags	flags;
	int		fd;

	ft_flags_lemin(&flags, ac, av);
	fd = (flags.fd_path) ? open(flags.fd_path, O_RDONLY) : 0;
	if (fd < 0)
		ft_perror();
	ft_read(fd, &str_split);
	ft_zerodata(&data);
	ft_valid(&data, str_split);
	ft_parse_data(&data, str_split);
	ft_free_str_split(str_split);
	ft_ways(&data);
	if (!data.old_ways)
		ft_error(1);
	data.start->ant = data.ants;
	ft_lem_in(&data, data.steps);
	ft_free_data(&data);
	return (0);
	//(46)esli pshibka malloca to che togda sprosit u dimasa (poka chto prosto exit(-1))
	//dobavit ft_perror v libu
}
