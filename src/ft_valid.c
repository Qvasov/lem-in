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
	int 	dash;

	if (line[0] == 0 || line[0] == 'L')
		return (ft_error());
	if (line[0] == '#')
		return (ft_valid_comment(line));
	if (data->ants_define == 0)
	{//ft_valid_ants();
		i = -1;
		while (line[++i])
			if (!ft_isdigit(line[i]))
				return (ft_error());
		return (1);
	}
	if (data->rooms_define == 1)
	{//ft_valid_links();
		i = 0;
		dash = 0;
		while (line[++i])
		{
			if (line[i] == '-')
				++dash;
			else if (dash && line[i] == ' ')
			{
				if (line[i + 1] == '\0' && line[i - 1] == '-')
					return (3);
				else
					break; // return(); //ft_valid_rooms
			}
			else if (!dash && line[i] == ' ')
				break; // return(); //ft_valid_rooms
		}
		if (dash)
			return (3);
		else
			return (ft_error(0));
	}
	if (data->rooms_define != 2)
	{//ft_valid_rooms();
		i = 0;
		space = 0;
		while (line[i] && space == 0)
			if (line[++i] == ' ')
				space = 1;
		if (!line[i] || !ft_isnum(&line[++i], ' '))
			return (ft_error());
		while (line[i] && space == 1)
			if (line[++i] == ' ')
				space = 2;
		if (!line[i] || !ft_isnum(&line[++i], '\0'))
			return (ft_error());
		data->rooms_define = 1;
		return (2);
	}
	else
		return (ft_error());
	return (0);
}
