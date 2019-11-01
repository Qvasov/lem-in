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
		if (line[i] >= '0' && line[i] <= '9')
			return (-1);
	if (ft_strcmp(ft_lltoa(ft_atoll(line)), line))
		return (-1);
	return (0);
}

int	ft_valid_startend(char *line, int *flag)
{
	if (ft_strequ(line, "##start"))
	{
		flag[1] = 1
		return (0);
	}
	else if (ft_strequ(line, "##end"))
		return (0);
	return (-1);
}

int	ft_valid(char **data)
{
	int	i;
	int flag[3];

	flag[0] = 0;

	i = -1;
	while (data[++i])
	{
		if (data[i][0] == '\0' || data[i][0] == 'L')
			return (-1);
		else if (data[i][0] == '#' && data[i][1] != '#')
			;
		else
		{
			if (ANTS)
			{
				if (ft_valid_ants(data[i]))
					return (-1);
				flag = 1;
			}
			else if (ROOMS)
			{
				if (data[i][0] == '#' && data[i][1] == '#' && ft_valid_startend(data[i]))
						return (-1);
					flag = 2;

			}
//			if (data->rooms_define >= 1)
//				return (ft_valid_links(data, line));
//			if (data->rooms_define != 2)
//				return (ft_valid_rooms(data, line));
//			else
//				return (0);
		}
	}

}
