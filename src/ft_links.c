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

#include "inc/lem-in.h"

static t_link	*ft_createlink(t_room *room)
{
	t_link	*link;

	if (!(link = (t_link *)malloc(sizeof(t_link))))
		return (NULL);
	link->room = room;
	link->next = NULL;
	link->prev = NULL;
	return (link);
}

static int		ft_connectlink(t_room *room1, t_room *room2)
{
	t_link	*link;
	t_link	*tmp;

	if (!(link = ft_createlink(room2)))
		return (0);
	if (room1->links)
	{
		tmp = room1->links;
		room1->links = link;
		link->next = tmp;
		tmp->prev = link;
	}
	else
		room1->links = link;
	return (1);
}

int				ft_links(t_data *data, char *str)
{
	t_room	*room1;
	t_room	*room2;

	room1 = NULL;
	room2 = NULL;
	if (ft_findrooms(data, str, &room1, &room2))
		return (-1);
	if (!(ft_connectlink(room1, room2) || !ft_connectlink(room2, room1)))
		return (-1);
//	data->links_define = 1;
	return (0);
}
