/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 18:04:19 by dbennie           #+#    #+#             */
/*   Updated: 2019/10/13 18:04:22 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/lem-in.h"

int	ft_parse(t_data *data)
{
	char	*line;
	int		v;
	int		g;

	line = NULL;
	while (1)
	{
		g = get_next_line(0, &line);
		if (g > 0)
		{
			v = ft_valid(data, line);
			if (v != 2 && (data->start_define == 1 || data->end_define == 1))
				exit (ft_error(data, line));
			if (v == 5 && !data->start_define)
				data->start_define = 1;
			else if (v == 6 && !data->end_define)
				data->end_define = 1;
			else if (v == 1 && !data->ants_define)
			{
				ft_ants(data, line);
				data->ants_define = 1;
			}
			else if (v == 2 && data->rooms_define != 2)
				ft_roomslist(data, line);
			else if (v == 3 && data->rooms_define != 0)
			{
				ft_links(data, line);
				data->rooms_define = 2;
			}
			else
				exit (ft_error(data, line));
			free(line);
			line = NULL;
		}
		else if (g < 0)
			exit (ft_error(data, line));
		else if (g == 0)
			break;
	}
	if ((data->start_define != 2 || data->end_define != 2
		|| data->rooms_define != 2 || data->ants_define != 1
		|| data->links_define != 1) && !line)
		exit (ft_error(data, line));
	return (1);
}
