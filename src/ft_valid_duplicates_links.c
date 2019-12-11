/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_duplicates_links.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:58:27 by dbennie           #+#    #+#             */
/*   Updated: 2019/12/11 20:58:28 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/lem-in.h"

static int	ft_roomcmp(char *room1, char *room2)
{
	int		i;
	int		j;

	i = -1;
	while (room1[++i] && room2[i] && room1[i] != ' ' && room2[i] != ' ')
		if (room1[i] != room2[i])
			break ;
	if (room1[i] == room2[i])
		exit(2);
	--i;
	j = i;
	while (room1[++i] && room1[i] != ' ')
		;
	while (room2[++j] && room2[j] != ' ')
		;
	while (room1[++i] && room2[++j])
		if (room1[i] != room2[i])
			return (0);
	exit(2);
}

int		ft_linkcmp(char *link1, char *link2)
{
	int		i;
	int		j;

	i = -1;
	while (link1[++i] && link2[i] && link1[i] != '-' && link2[i] != '-')
		if (link1[i] != link2[i])
			break;
	if (link1[i] == link2[i] && link1[i] == '-')
	{
		while (link1[++i] && link2[i])
			if (link1[i] != link2[i])
				return (0);
	}
	else if ()

	i = -1;
	j = -1;
	while (link2[j])
	return (0);
}

int		ft_valid_duplicates_links(t_data *data, char **strings)
{
	long	i;
	long	j;

	i = data->i_links_start - 1;
	while (++i <= data->i_links_end)
	{
		j = i;
		while (++j <= data->i_links_end)
			ft_linkcmp(strings[i], strings[j]);
	}
	return (0);
}
