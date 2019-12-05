/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findnames.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 20:26:15 by dbennie           #+#    #+#             */
/*   Updated: 2019/10/16 20:26:16 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/lem-in.h"

int	ft_name_equ(char *name_room, char *name_link, int direction)
{
	long	i;
	long	j;

	i = -1;
	if (!direction)
	{
		while (name_room[++i] && name_link[i] && name_link[i] != '-')
			if (name_room[i] != name_link[i])
				return (0);
		if (!name_room[i] && name_link[i] == '-')
			return (1);
	}
	else
	{
		while (name_link[++i] && name_link[i] != '-')
			;
		j = 0;
		++i;
		while (name_room[j] && name_link[i])
		{
			if (name_room[j] != name_link[i])
				return (0);
			++j;
			++i;
		}
		if (name_room[j] == name_link[i])
			return (1);
	}
	return (0);
}

int	ft_findrooms(t_data *data, char *link, t_room **room1, t_room **room2)
{
	t_room	*head;

	head = data->rooms;
	if (!room1 || !room2)
		return (-1);
	while (head && (!*room1 || !*room2))
	{
		if (!*room1 && ft_name_equ(head->name, link, 0))
			*room1 = head;
		else if (!*room2 && ft_name_equ(head->name, link, 1))
			*room2 = head;
		head = head->next;
	}
	return (0);
}
