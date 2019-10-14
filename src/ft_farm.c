/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_farm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 20:04:05 by dbennie           #+#    #+#             */
/*   Updated: 2019/10/13 20:04:06 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/lem-in.h"

static t_room	*ft_createroom(char *data)
{
	long	i;
	t_room	*room;

	if (!(room = (t_room *)malloc(sizeof(t_room))))
		return (NULL);
	i = 0;
	while (data[i] != ' ')
		++i;
	if (!(room->name = ft_strsub(data, 0, i)))
		return (ft_freeroom());
	i = i + 1;
	room->x = ft_atoll(&data[i]);
	while (data[i] != ' ')
		++i;
	i = i + 1;
	room->y = ft_atoll(&data[i]);
	room->links = NULL;
	room->next = NULL;
	return (room);
}

static int		ft_createfarm(t_data *data, int rooms)
{
	t_room	*tmp;


	if (!(data->farm = (t_room **)malloc(sizeof(t_room *) * (rooms + 1))))
		return(ft_error());
	data->farm[rooms] = NULL;

}

static void 	ft_rooms(t_data *data, t_room *rooms)
{
	long 	i;
	long	j;
	t_room 	*room;

	i = data->index - 1;
	while (data->map[++i])
	{
		if (data->map[i] == '#')
		{
			while (data->map[i] != '\n')
				++i;
		}
		else if (data->map[i] != '#')
		{
			room = NULL;
			j = i;
			while (j && data->map[j] != '\n')
				if (data->map[j++] == ' ')
					j = 0;
			if (j)
				break;
			if (!(room = ft_createroom(&data->map[i])))
				return (ft_error());
			room->next = rooms;
			rooms = room;
			while (data->map[i] != '\n')
				++i;
		}
	}
	data->index = i;
}

void			ft_farm(t_data *data)
{
	t_room	*rooms;

	rooms = NULL;
	ft_rooms(data, rooms);
	ft_createfarm(data, rooms);
}
