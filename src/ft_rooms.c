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
	int		i;
	t_room	*room;

	if (!(room = (t_room *)malloc(sizeof(t_room))))
		ft_perror();
	i = 0; // why was 1??
	while (name[i] != '\0' && name[i] != ' ')
		++i;
	if (!(room->name = ft_strsub(name, 0, i)))
		ft_perror();
	room->x = 0;
	room->y = 0;
	room->links = NULL;
	room->links_count = 0;
	room->room_out = NULL;
	room->room_in = NULL;
	room->room_parrent = NULL;
	room->next = NULL;
	room->ant = 0;
	room->cost = INF;
	room->state = 1;
	return (room);
}

static t_room	*ft_createroom_xy(char *line)
{
	int		i;
	t_room	*room;

	room = ft_createroom(line);
	i = (int)ft_strlen(room->name) + 1;
	line += i;
	room->x = ft_satoi(line, &i);
	(i == 0 || line[i] != ' ') ? ft_error(2) : 1;
	line += i;
	room->y = ft_satoi(line, &i);
	(i == 0 || line[i] != 0) ? ft_error(2) : 1;
	return (room);
}

void			ft_rooms(t_data *data, char *str)
{
	t_room	*room;

	room = ft_createroom_xy(str);
	room->next = data->rooms;
	data->rooms = room;
	++data->rooms_count;
}
