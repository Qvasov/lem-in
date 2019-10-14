/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 20:06:00 by dbennie           #+#    #+#             */
/*   Updated: 2019/10/14 20:06:02 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/lem-in.h"

int	ft_valid_comment(char *line)
{
	if (ft_strequ(line, "##start"))
		return (5);
	else if (ft_strequ(line, "##end"))
		return (6);
	return (4);
}

int	ft_valid(t_data *data, char *line)
{
	long	i;
	int		space;

	if ((!data->start_define || !data->end_define || !data->rooms_define
	|| !data->ants_define || !data->links_define) && line[0] == '\0')
		return (ft_error());
	if (line[0] == 'L')
		return (ft_error());
	if (line[0] == '#')
		return (ft_valid_comment(line));
	if (data->ants_define == 0)
	{//ft_valid_ants();
		i = -1;
		while (line[++i])
			if (!ft_isdigit(line[i]))
				return (ft_error());
		data->ants = ft_atoll(line);
		return (1);
	}
	if (data->rooms_define == 0)
	{//ft_valid_rooms();
		i = 0;
		space = 0;
		while (line[++i])
			if (line[i] == ' ')
			{
				++space;
				break;
			}

		}
	}
	return (0);
}
