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

int	ft_valid_rooms(char *str)
{
	long	i;
	int		space;

	i = 0;
	space = 0;
	while (str[i] && space == 0)
		if (str[++i] == ' ')
			space = 1;
	if (!str[i] || !ft_isnum(&str[++i], ' '))
		return (-1);
	while (str[i] && space == 1)
		if (str[++i] == ' ')
			space = 2;
	if (!str[i] || !ft_isnum(&str[++i], '\0'))
		return (-1);
	return (0);
}

int	ft_valid_links(char *str)
{
	long	i;

	i = 0;
	while (str[++i])
	{
		if (str[i] == '-' && str[i + 1])
			return (0);
	}
	return (-1);
}

int	ft_valid_ants(char *str)
{
	long	i;

	i = -1;
	while (str[++i])
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (-1);
	if (ft_strcmp(ft_lltoa(ft_atoll(str)), str)) //если больше чем long long //ft_isnum(str, 0)
		return (-1);
	return (0);
}

int	ft_valid_startend(char *str, int *flag)
{
	if (ft_strequ(str, "##start") && !START && ANTS && !LINKS && !SE)
	{
		START = 1;
		SE = 1;
		return (0);
	}
	else if (ft_strequ(str, "##end") && !END && ANTS && !LINKS && !SE)
	{
		END = 1;
		SE = 1;
		return (0);
	}
	return (-1);
}

void	ft_zero_flag(int *flag)
{
	flag[0] = 0;
	flag[1] = 0;
	flag[2] = 0;
	flag[3] = 0;
	flag[4] = 0;
	flag[5] = 0;
}

int		ft_roomcmp(char *room1, char *room2)
{
	int		i;
	int		j;

	i = -1;
	while (room1[++i] && room2[i] && room1[i] != ' ' && room2[i] != ' ')
		if (room1[i] != room2[i])
			break ;
	if (room1[i] == room2[i])
		return (1);
	--i;
	j = i;
	while (room1[++i] && room1[i] != ' ')
		;
	while (room2[++j] && room2[j] != ' ')
		;
	while (room1[++i] && room2[++j])
		if (room1[i] != room2[i])
			return (0);
	return (1);
}

int		ft_valid_duplicates(t_data *data, char **strings)
{
	int		i;
	int		j;

	i = data->i_rooms_start - 1;
	while (++i <= data->i_rooms_end)
	{
		j = i;
		while (++j <= data->i_rooms_end)
			if (ft_roomcmp(strings[i], strings[j]))
				return (1);
	}
	return (0);
}

int		ft_linkcmp(char *link1, char *link2)
{
	int		i;
	int		j;

	i = -1;
	//while (link1[i] )
	return (0);
}

int		ft_valid_duplinks(t_data *data, char **strings)
{
	int		i;
	int 	j;

	i = data->i_links_start - 1;
	while (++i <= data->i_links_end)
	{
		j = i;
		while (++j <= data->i_links_end)
			if (ft_linkcmp(strings[i], strings[j]))
				return (1);
	}
	return (0);
}

int	ft_valid(t_data *data, char **strings)
{
	long	i;
	int		flag[6];

	ft_zero_flag(flag);
	i = -1;
	while (strings[++i])
	{
		if (strings[i][0] == '\0' || strings[i][0] == 'L')
			return (-1);
		else if (strings[i][0] == '#' && strings[i][1] != '#')
			;
		else if (strings[i][0] == '#' && strings[i][1] == '#')
		{
			if (ft_valid_startend(strings[i], flag))
				return (-1);
		}
		else if (!ANTS)
		{
			if (ft_valid_ants(strings[i]))
				return (-1);
			ANTS = 1;
			data->i_ants = i;
		}
		else if (!LINKS && ANTS && ft_strchr(strings[i], ' '))
		{
			if (ft_valid_rooms(strings[i]))
				return (-1);
			ROOMS = 1;
			if (!data->i_rooms_start)
				data->i_rooms_start = i;
			data->i_rooms_end = i;
			if (!data->i_start && START && SE)
				data->i_start = i;
			else if (!data->i_end && END && SE)
				data->i_end = i;
			SE = 0;
		}
		else if (ROOMS && ANTS && START && END)
		{
			if (ft_valid_links(strings[i]))
				return (-1);
			LINKS = 1;
			if (!data->i_links_start)
				data->i_links_start = i;
			data->i_links_end = i;
		}
		else
			return (-1);
	}
	ft_valid_duplicates(data, strings);
	ft_valid_duplinks(data, strings);
	return (0);
}
