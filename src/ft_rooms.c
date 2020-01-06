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

#include "lemin.h"

t_room			*ft_createroom(char *name)
{
	size_t	i;
	t_room	*room;

	if (!(room = (t_room *)malloc(sizeof(t_room))))
		ft_perror();
	i = 1;
	while (name[i] != '\0' && name[i] != ' ')
		++i;
	if (!(room->name = ft_strsub(name, 0, i)))
		ft_perror();
	room->x = 0;
	room->y = 0;
	room->links = NULL;
	room->room_out = NULL;
	room->room_in = NULL;
	room->next = NULL;
	room->ant = 0;
	room->cost = 0x7FFFFFFF;
	return (room);
}

static t_room	*ft_createroom_xy(char *line)
{
	size_t	i;
	t_room	*room;

	room = ft_createroom(line);
	i = ft_strlen(room->name) + 1;
	room->x = ft_atoll(&line[i]);
	while (line[i] != ' ')
		++i;
	i = i + 1;
	room->y = ft_atoll(&line[i]);
	return (room);
}

int				ft_rooms(t_data *data, char *str)
{
	t_room	*room;

	room = ft_createroom_xy(str);
	room->next = data->rooms;
	data->rooms = room;
	++data->rooms_count;
	return (0);
}
