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
			if (v == 5 && !data->start_define)
				data->start_define = 1;
			if (v == 6 && !data->end_define)
				data->end_define = 1;
			if (v == 1 && !data->ants_define)
				data->ants_define = 1;
			else
				ft_error();


			ft_farm(data);
			ft_links(data);
		}
		else if (r < 0)
			return (ft_error());
		else
			return (1);
	}
}