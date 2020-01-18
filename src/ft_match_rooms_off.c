/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match_rooms_off.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:25:13 by dbennie           #+#    #+#             */
/*   Updated: 2020/01/17 19:25:14 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	check_linked_room(t_room *room)
{
	t_link	*l;

	while (room->links_count == 2 && room->state == 1)
	{
		room->state = 0;
		l = (room->links->room->state == 0) ? room->links->next : room->links;
		room = l->room;
	}
}

void		ft_match_rooms_off(t_room *rooms, t_room *start, t_room *end)
{
	while(rooms)
	{
		if (rooms == start || rooms == end)
		{
			rooms = rooms->next;
			continue ;
		}
		if (rooms->links_count < 2)
		{
			rooms->state = 0;
			if (rooms->links_count == 1)
				check_linked_room(rooms->links->room);
		}
		rooms = rooms->next;
	}
}
