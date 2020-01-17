/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:01:12 by dbennie           #+#    #+#             */
/*   Updated: 2019/11/28 18:01:13 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	loop(t_room *new_parrent, t_room *room)
{
	t_room	*ptr;

	ptr = new_parrent;
	while (ptr)
	{
		if (ptr == room)
			return (1);
		ptr = ptr->room_parrent;
	}
	return (0);
}

static void	change_cost(t_room *room, t_link *link, int *flag)
{
	link->room->cost = room->cost + link->cost;
	if (!link->room->room_parrent ||
	((link->room->room_parrent) && !loop(room, link->room)))
	{
		link->room->room_parrent = room;
		*flag = 1;
	}
}

void 		ft_turn(t_room *room, t_room *start, int *flag)
{
	t_link	*link;
	t_room	*room_d;

	if (room->cost != 0x7FFFFFFF)
	{
		link = room->links;
		while (link)
		{
			if (room->cost + link->cost < link->room->cost && link->room != start)
				change_cost(room, link, flag);
			link = link->next;
		}
	}
	if ((room_d = room->room_out) && room_d->cost != 0x7FFFFFFF)
	{
		link = room_d->links;
		while (link)
		{
			if (room_d->cost + link->cost < link->room->cost && link->room != start)
				change_cost(room_d, link, flag);
			link = link->next;
		}
	}
}
