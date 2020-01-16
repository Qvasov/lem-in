/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:17:51 by dbennie           #+#    #+#             */
/*   Updated: 2019/10/16 17:17:52 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_link		*ft_createlink(t_room *room)
{
	t_link	*link;

	if (!(link = (t_link *)malloc(sizeof(t_link))))
		ft_perror();
	link->cost = 2;
	link->room_src = NULL;
	link->room = room;
	link->next = NULL;
	link->prev = NULL;
	link->turn_next = NULL;
	link->turn_prev = NULL;
	link->parrent = NULL;
	link->turn_in = 0;
	return (link);
}

static void	ft_connectlink(t_room *room_src, t_room *room_dst)
{
	t_link	*link;
	t_link	*tmp;

	link = ft_createlink(room_dst);
	if (room_src->links)
	{
		tmp = room_src->links;
		room_src->links = link;
		link->next = tmp;
		tmp->prev = link;
	}
	else
		room_src->links = link;
	link->room_src = room_src;
}

static int	ft_check_duplicate_link(t_room *room1, t_room *room2)
{
	t_link	*link;

	link = room1->links;
	while (link)
	{
		if (link->room == room2)
			return (1);
		link = link->next;
	}
	return (0);
}

void		ft_links(t_data *data, char *link_str)
{
	t_room	*room1;
	t_room	*room2;

	room1 = NULL;
	room2 = NULL;
	ft_findrooms(data, link_str, &room1, &room2);
	if (!ft_check_duplicate_link(room1, room2))
	{
		ft_connectlink(room1, room2);
		ft_connectlink(room2, room1);
	}
}
