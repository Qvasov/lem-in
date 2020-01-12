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

static int	is_loopa(t_link *link)
{
	t_link	*ptr;

	ptr = link;
	while(ptr)
	{
		if (
		(link->room && link->room == ptr->room_src) ||
		(link->room->room_out && link->room->room_out == ptr->room_src->room_in) ||
		(link->room->room_in && link->room->room_in == ptr->room_src->room_out) ||
		(link->room && link->room == ptr->room_src->room_out) ||
		(link->room->room_in && link->room->room_in == ptr->room_src)
		)
			return (1);
		ptr = ptr->parrent;
	}
	return (0);
}

void	ft_turn(t_link **head, t_link **tail, t_link **end, t_data *data)
{
	t_link	*ptr;

	ptr = (*head)->room->links;
	while (ptr)
	{
		if (((*head)->room->cost + ptr->cost < ptr->room->cost) &&
		(!(*head)->parrent || ptr->room != (*head)->parrent->room) &&
		ptr->room != data->start)
		{
//			if (ptr->room->cost != 0x7FFFFFFF)
//				if ((is_loopa(ptr)))
//				{
//					ptr = ptr->next;
//					continue ;
//				}
//			if (ptr->turn_in == 0) попробовать удалить очередь или переделать
//			{
				(*tail)->turn_next = ptr;
				ptr->turn_prev = *tail;
				ptr->turn_in = 1;
				*tail = (*tail)->turn_next;
//			}
			ptr->parrent = *head;
			ptr->room->cost = (*head)->room->cost + ptr->cost;
			if (ptr->room == data->end)
				*end = ptr;
		}
		ptr = ptr->next;
	}
}
