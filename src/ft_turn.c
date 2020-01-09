/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:01:12 by dbennie           #+#    #+#             */
/*   Updated: 2019/11/28 18:01:13 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_turn_null(t_link *turn_tail)
{
	while (turn_tail)
	{
		turn_tail->room->cost = 0x7FFFFFFF;
		turn_tail->turn_in = 0;
		turn_tail->parrent = NULL;
		if (turn_tail->turn_next)
			turn_tail->turn_next->turn_prev = NULL;
		turn_tail->turn_next = NULL;
		turn_tail = turn_tail->turn_prev;
	}
}

void	ft_turn(t_link **head, t_link **tail, t_link **end, t_data *data)
{
	t_link	*link;

	link = (*head)->room->links;
	while (link)
	{
		if (((*head)->room->cost + link->cost < link->room->cost) &&
			(!(*head)->parrent || link->room != (*head)->parrent->room) &&
			link->room != data->start)
		{
			if (link->turn_in == 0)
			{
				(*tail)->turn_next = link;
				link->turn_prev = *tail;
				link->turn_in = 1;
				*tail = (*tail)->turn_next;
			}
			link->parrent = *head;
			link->room->cost = (*head)->room->cost + link->cost;
			if (link->room == data->end)
				*end = link;
		}
		link = link->next;
	}
}
