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

int	ft_findrooms(t_data *data, t_line *names)
{
	t_room	*head;
	t_room	*ok1;
	t_room	*ok2;

	names->room2 = NULL;
	names->room1 = NULL;
	head = data->tail;
	while (head)
	{
		if (!names->room1 && ft_strequ(head->name, names->name1))
			names->room1 = head;
		if (!names->room2 && ft_strequ(head->name, names->name2))
			names->room2 = head;
		head = head->next;
	}
	if (names->room1 && names->room2)
		return (1);
	return (0);
}
