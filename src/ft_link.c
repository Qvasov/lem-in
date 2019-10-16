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

static t_link	*ft_createlink(char *room2)
{
	t_link	*link;

	if (!(link = (t_link *)malloc(sizeof(t_link))))
		return (NULL);
	link->name = room2;
	link->next = NULL;
	link->prev = NULL;
	return (link);
}

static void		ft_connectlink(t_room *room, char *name)
{
	t_link	*link;
	t_link	*tmp;

	if (!(link = ft_createlink(name)))
		return (ft_error());
	if (room->links)
	{
		tmp = room->links;
		room->links = link;
		link->next = tmp;
		tmp->prev = link;
	}
	else
		room->links = link;
}

void			ft_link(t_data *data, char *line)
{
	t_line	*names;

	if (!(names = (t_line *)malloc(sizeof(t_line))))
		return (ft_error());
	names->len = ft_strlen(line);
	names->dash = 1;
	while (data->dash--)
	{
		ft_names(names, line);
		if (!ft_findrooms(data, names) && !data->dash)
			return (ft_error());
		else if (ft_findrooms(data, names))
		{
			ft_connectlink(names->room1, names->room2->name);
			ft_connectlink(names->room2, names->room1->name);
		}
		ft_free_names(names);
	}
}
