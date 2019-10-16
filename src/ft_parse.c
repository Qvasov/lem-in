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

int			ft_parse(t_data *data)
{
	char	*line;
	int 	r;
	int		v;

	while (1)
	{
		r = get_next_line(0, &line);
		if (r > 0)
		{
			v = ft_valid(data, line);
			if (v != 2 && (data->start_define == 1 || data->end_define == 1)
				return (ft_error());
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
				data->rooms_define = 2;
				ft_link(data, line);
			}
			else
				ft_error();

			ft_farm(data);
		}
		else if (r < 0)
			return (ft_error());
		else
			break;
	}
	if ((!data->start_define || !data->end_define || !data->rooms_define
		 || !data->ants_define || !data->links_define) && line[0] == '\0')
		return (ft_error());
	return (1);
}