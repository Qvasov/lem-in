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

#include "lemin.h"

int	ft_name_equ_room1(char *name_room, char *name_link)
{
	long	i;

	i = -1;
	while (name_room[++i] && name_link[i] && name_link[i] != '-')
		if (name_room[i] != name_link[i])
			return (0);
	if (!name_room[i] && name_link[i] == '-')
		return (1);
	return (0);
}

int	ft_name_equ_room2(char *name_room, char *name_link)
{
	long	i;
	long	j;

	i = -1;
	j = 0;
	while (name_link[++i] && name_link[i] != '-')
		;
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
		if (!*room1 && ft_name_equ_room1(head->name, link))
			*room1 = head;
		else if (!*room2 && ft_name_equ_room2(head->name, link))
			*room2 = head;
		head = head->next;
	}
	return (0);
}
