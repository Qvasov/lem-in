/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_direction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:29:27 by dbennie           #+#    #+#             */
/*   Updated: 2019/11/28 18:29:28 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	ft_redirection_link(t_room *from, t_room *to)
{
	t_link	*link;

	link = from->links;
	while (link && link->room != to)
		link = link->next;
	if (link && link->room == to)
	{
		if (link->prev)
			link->prev->next = link->next;
		else
			from->links = link->next;
		if (link->next)
			link->next->prev = link->prev;
		link->cost = (link->cost == -1) ? 2 : -1;
		link->room = from;
		link->room_src = to;
		link->prev = NULL;
		link->next = to->links;
		if (to->links)
			to->links->prev = link;
		to->links = link;
	}
}

static void	ft_delete_link(t_room *from, t_room *to)
{
	t_link	*link;

	link = from->links;
	while (link && link->room != to)
		link = link->next;
	if (link && link->room == to)
	{
		if (link->prev)
			link->prev->next = link->next;
		else
			from->links = link->next;
		if (link->next)
			link->next->prev = link->prev;
		free(link);
	}
}

void		ft_direction(t_path *path)
{
	t_room	*room_src;
	t_room	*room_dst;

	while (path && path->next)
	{
		room_src = path->room;
		room_dst = path->next->room;
		if (!(room_src->room_in || room_src->room_out) &&
		!(room_dst->room_in || room_dst->room_out))
			ft_delete_link(room_dst, room_src);
		else if (!(room_src->room_in || room_src->room_out) &&
		room_dst->room_out)
			ft_delete_link(room_dst->room_out, room_src);
		else if (!(room_src->room_in || room_src->room_out) &&
		room_dst->room_in)
			ft_delete_link(room_dst->room_in, room_src);
		else if (room_src->room_in &&
		!(room_dst->room_in || room_dst->room_out))
			ft_delete_link(room_dst, room_src->room_in);
		else if (room_src->room_out &&
		!(room_dst->room_in || room_dst->room_out))
			ft_delete_link(room_dst, room_src->room_out);
		ft_redirection_link(room_src, room_dst);
		path = path->next;
	}
}
