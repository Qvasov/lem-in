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

static t_link	*ft_createlink(t_room *room, char *room_name)
{
	t_link	*link;

	if (!(link = (t_link *)malloc(sizeof(t_link))))
		return (NULL);
	link->name = room_name;
	link->room = room;
	link->next = NULL;
	link->prev = NULL;
	return (link);
}

static int		ft_connectlink(t_room *room1, t_room * room2, char *room2_name)
{
	t_link	*link;
	t_link	*tmp;

	if (!(link = ft_createlink(room2, room2_name)))
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

void			ft_links(t_data *data, char *line)
{
	t_line	*names;
	int		n;

	if (!(names = (t_line *)malloc(sizeof(t_line))))
		exit (ft_error(data, line));
	while (data->dash--)
	{
		if (!(ft_names(names, line)))
		{
			free(names);
			ft_error(data, line);
		}
		n = ft_findrooms(data, names);
		if (!n && !data->dash)
		{
			ft_free_names(names);
			free(names);
			exit (ft_error(data, line));
		}
		else if (n)
		{
			if (!(ft_connectlink(names->room1, names->room2, names->room2->name))
			|| !ft_connectlink(names->room2, names->room1, names->room1->name))
			{
				ft_free_names(names);
				free(names);
				exit (ft_error(data, line));
			}
		}
		ft_free_names(names);
		free(names);
		data->links_define = 1;
	}
}
