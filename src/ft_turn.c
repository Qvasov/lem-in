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

void		ft_turn_null(t_link *turn_tail)
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

static int	check_new_parrent_loop(t_link *new_parrent, t_room *start)
{
	t_link	*ptr;
	int		s;

	s = 0;
	ptr = new_parrent;
	while (ptr && s == 0)
	{
		if (ptr->parrent->room == new_parrent->room)
			return (1);
		if (ptr->parrent->room_src == start)
			s = 1;
		ptr = ptr->parrent;
	}
	return (0);
}

void		ft_turn(t_link **head, t_link **tail, t_link **end, t_data *data)
{
	t_link	*ptr;

	ptr = (*head)->room->links;
	while (ptr)
	{
		if (((*head)->room->cost + ptr->cost < ptr->room->cost) && //для того чтобы не уйти в room_out так как цена не изменится
		(!(*head)->parrent || ptr->room != (*head)->parrent->room) &&
		ptr->room != data->start /*&& ptr->cost != 0*/)
		{
			if (ptr->turn_in == 0)
			{
				(*tail)->turn_next = ptr;
				ptr->turn_prev = *tail;
				ptr->turn_in = 1;
				*tail = (*tail)->turn_next;
			}
			if (ptr->parrent && check_new_parrent_loop((*head), data->start))
			{
				ptr = ptr->next;
				continue ;
			}
			ptr->parrent = *head;
			ptr->room->cost = (*head)->room->cost + ptr->cost;
			(ptr->room == data->end) ? *end = ptr : 0;
		}
		ptr = ptr->next;
	}
}
