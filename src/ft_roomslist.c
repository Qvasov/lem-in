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

static t_room	*ft_createroom(char *line)
{
	long	i;
	t_room	*room;

	if (!(room = (t_room *)malloc(sizeof(t_room))))
		return (NULL);
	i = 1;
	while (line[i] != ' ')
		++i;
	if (!(room->name = ft_strsub(line, 0, i)))
	{
		free(room);
		return (NULL);
	}
	i = i + 1;
	room->x = ft_atoll(&line[i]);
	while (line[i] != ' ')
		++i;
	i = i + 1;
	room->y = ft_atoll(&line[i]);
	room->links = NULL;
	room->next = NULL;
	return (room);
}

void			ft_roomslist(t_data *data, char *line)
{
	t_room	*room;

	if (!(room = ft_createroom(line)))
		exit (ft_error(data, line));
	room->next = data->tail;
	data->tail = room;
	++data->rooms_count;
	if (data->start_define == 1)
	{
		data->start = data->tail;
		data->start_define = 2;
	}
	if (data->end_define == 1)
	{
		data->end = data->tail;
		data->end_define = 2;
	}
}
