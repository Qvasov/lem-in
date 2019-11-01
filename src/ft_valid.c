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

int	ft_valid_rooms(t_data *data, char *line)
{
	long	i;
	int		space;

	i = 0;
	space = 0;
	while (line[i] && space == 0)
		if (line[++i] == ' ')
			space = 1;
	if (!line[i] || !ft_isnum(&line[++i], ' '))
		return (-1);
	while (line[i] && space == 1)
		if (line[++i] == ' ')
			space = 2;
	if (!line[i] || !ft_isnum(&line[++i], '\0'))
		return (-1);
	data->rooms_define = 1;
	return (2);
}

int	ft_valid_links(t_data *data, char *line)
{
	long	i;

	i = 0;
	data->dash = 0;
	while (line[++i])
	{
		if (line[i] == '-')
			++data->dash;
		else if (data->dash && line[i] == ' ')
		{
			if (line[i + 1] == '\0' && line[i - 1] == '-')
				return (3);
			else
				return(ft_valid_rooms(data, line));
		}
		else if (!data->dash && line[i] == ' ')
			return(ft_valid_rooms(data, line));
	}
	if (data->dash)
		return (3);
	else
		return (-1);
}

int	ft_valid_ants(char *line)
{
	long	i;

	i = -1;
	while (line[++i])
		if (!ft_isdigit(line[i]))
			return (-1);
	return (1);
}

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
	if (line[0] == '\0' || line[0] == 'L')
		return (-1);
	if (line[0] == '#')
		return (ft_valid_comment(line));
	if (data->ants_define == 0)
		return (ft_valid_ants(line));
	if (data->rooms_define >= 1)
		return (ft_valid_links(data, line));
	if (data->rooms_define != 2)
		return (ft_valid_rooms(data, line));
	else
		return (-1);
}
