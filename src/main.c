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

static int	ft_zerodata(t_data *data)
{
	data->ants = 0;
	data->start = NULL;
	data->end = NULL;
	data->rooms = NULL;
	data->rooms_count = 0;
	data->ways = NULL;
	data->mod_ways = NULL;
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
	return (1);
}

int			main()
{
	t_data	data;
	char	**str_split;

	int fd = open("3", O_RDONLY);
	if (ft_read(fd, &str_split) < 0)
		return (0);
	ft_zerodata(&data);
	if (ft_valid(&data, str_split) < 0)
		exit(ft_error(NULL, str_split));
	if (ft_parse(&data, str_split) < 0)
		exit(ft_error(&data, str_split));
	ft_free_str_split(str_split);
	if (ft_ways(&data) < 0)
		exit(ft_error(&data, NULL));
	if (!data.mod_ways)
		exit(ft_error(&data, NULL));
	data.start->ant = data.ants;
	ft_lem_in(&data, data.steps);
	ft_free_data(&data);
	return (0);
	//exit mozhmo ispolzovat
	//error sdelat normalniy
}
