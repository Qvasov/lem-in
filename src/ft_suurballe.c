/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_suurballe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:27:26 by dbennie           #+#    #+#             */
/*   Updated: 2019/11/14 17:27:26 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	create_out_room(t_room *in, t_room *out, t_room *room)
{
	t_link	*link;

	out = ft_createroom(in->name);
	in->room_out = out;
	out->room_in = in;
	link = ft_createlink((room->room_out) ? room->room_out : room);
	link->cost = -1;
	link->room_src = in;
	out->links = in->links;
	in->links = link;
	link = out->links;
	while (link && link->room != room)
		link = link->next;
	if (link && link->room == room)
	{
		link->room = in;
		link->room_src = out;
		link->cost = 1;
	}
	else
		in->links = link; // то есть NULL?
}

static void	duplicate_rooms(t_path *path)
{
	t_room	*in;
	t_room	*out;
	t_link	*link;

	while (path)
	{
		if (!path->next || !path->next->next)
			return ;
		in = path->next->room;
		if (!in->room_out && !in->room_in)
			create_out_room(in, NULL, path->room); // сдесь NULL загоняется для того чтобы не обьявлять переменную в теле функции (Норминет)
		else if (in->room_out && !path->room->room_in)
		{
			out = path->room;
			link = in->links;
			while (link && link->room != out)
				link = link->next;
			if (link && link->room == out)
				link->room = out->room_out;
		}
		path = path->next;
	}
}

int			ft_suurballe(t_data *data)
{
	if (ft_ford(data)) //поиск в ширину 1 - нашёл, 0 - не нашёл
	{
		ft_direction(data->ways_dij->path);
		duplicate_rooms(data->ways_dij->path); //end указывает сразу на room_in(не перенапрвляется)
		return (1);
	}
	return (0);
}
