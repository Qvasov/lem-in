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

#include "inc/lem-in.h"

static void ft_redirection_link(t_room *src, t_room *dst)
{
	t_link	*link;

	link = src->links;
	while (link && link->room != dst)
		link = link->next;
	if (link && link->room == dst)
	{
		if (link->prev)
			link->prev->next = link->next;
		else
			src->links = link->next;
		if (link->next)
			link->next->prev = link->prev;
		link->cost = (link->cost == -1) ? 1 : -1;
		link->room = src;
		link->room_src = dst;
		link->prev = NULL;
		link->next = dst->links;
		if (dst->links)
			dst->links->prev = link;
		dst->links = link;
	}
}

static void ft_delete_link(t_room *src, t_room *dst)
{
	t_link	*link;

	link = dst->links;
	while (link && link->room != src)
		link = link->next;
	if (link && link->room == src)
	{
		if (link->prev)
			link->prev->next = link->next;
		else
			dst->links = link->next;
		if (link->next)
			link->next->prev = link->prev;
		free(link);
	}
}

void		ft_direction(t_path *path)
{
	t_room	*room_src;
	t_room	*room_dst;

	while(path && path->next)
	{
		room_src = path->room;
		room_dst = path->next->room;
		if (!(room_src->room_in || room_src->room_out) && !(room_dst->room_in || room_dst->room_out))
			ft_delete_link(room_src, room_dst);
		else if (!(room_src->room_in || room_src->room_out) && room_dst->room_out)
			ft_delete_link(room_src, room_dst->room_out);
		else if (!(room_src->room_in || room_src->room_out) && room_dst->room_in)
			ft_delete_link(room_src, room_dst->room_in);
		else if (room_src->room_in && !(room_dst->room_in || room_dst->room_out))
			ft_delete_link(room_src->room_in, room_dst);
		else if (room_src->room_out && !(room_dst->room_in || room_dst->room_out))
			ft_delete_link(room_src->room_out, room_dst);
		ft_redirection_link(room_src, room_dst);
		path = path->next;
	}
}
