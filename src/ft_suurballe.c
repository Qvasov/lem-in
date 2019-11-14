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

#include "inc/lem-in.h"

static int	ft_duplicate_rooms(t_path *path)
{
	t_room	*tmp_in;
	t_room	*tmp_out;
	t_link	*tmp_link;
	char	*tmp_name;

	while (path)
	{
		if (!path->next)
			return (0);
		tmp_in = path->next->room;
		tmp_name = ft_strdup(tmp_in->name);
		if (!(tmp_out = ft_createroom(tmp_name)))
			return (-1);
		if (!(tmp_link = ft_createlink(path->room)))
			return (-1);
		tmp_link->cost = -1;
		tmp_in->room_out = tmp_out;
		tmp_out->links = tmp_in->links;
		tmp_in->links = tmp_link;
		tmp_link = tmp_out->links;
		while(tmp_link)
		{
			if (tmp_link->room == path->room)
			{
				tmp_link->room = tmp_in;
				tmp_link->cost = 0;
				tmp_link = NULL;
			}
			else
				tmp_link = tmp_link->next;
		}
		path = path->next;
	}
	return (0);
}

static void	ft_direct(t_path *path)
{
	t_room	*room_src;
	t_room	*room_dst;
	t_link	*link;

	while(path)
	{
		room_src = path->room;
		link = room_src->links;
		if ((room_dst = (path->next) ? path->next->room : NULL))
		{
			while (link)
			{
				if (link->room == room_dst)
				{
					if (link->prev)
						link->prev->next = link->next;
					else
						room_src->links = link->next;
					if (link->next)
						link->next->prev = link->prev;
					free(link);
					link = NULL;
				}
				else
					link = link->next;
			}
			link = room_dst->links;
			while (link)
			{
				if (link->room == room_src)
				{
					link->cost = -1;
					link = NULL;
				}
				else
					link = link->next;
			}
		}
		path = path->next;
	}
}

int 		ft_suurballe(t_data *data)
{
	if ((ft_bfs(data)) < 0)
		return (error);
	if ((ft_bfs(data)) == 0) //netu korotkogo puti
	if ((ft_bfs(data)) > 0) // est put
	{
		//proverka na kolichestvo putey
		//proverka na potoki
		ft_direct(data->ways->path);
		if ((ft_duplicate_rooms(data->ways->path)) < 0)
			return (-1);
		return (1);
	}
}
