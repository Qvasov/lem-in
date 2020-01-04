/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_ascending.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:00:00 by dbennie           #+#    #+#             */
/*   Updated: 2019/12/04 17:00:01 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		ft_null(t_link *turn_head, t_link *turn_tail, t_room *end)
{
	turn_head = end->links;
	while (turn_head && turn_head->cost != -1)
		turn_head = turn_head->next;
	while (turn_head)
	{
		turn_tail = turn_head->turn_next;
		turn_head->turn_next = NULL;
		turn_head->parrent = NULL;
		turn_head = turn_tail;
	}
}

static void		ft_link_end(t_link **turn_head, t_link **turn_tail)
{
	t_link	*link;

	link = (*turn_head)->next;
	while (link)
	{
		if (link->cost == -1)
		{
			(*turn_tail)->turn_next = link;
			*turn_tail = (*turn_tail)->turn_next;
		}
		link = link->next;
	}
}

t_way			*ft_paths_ascending(t_room *start, t_room *end)
{
	t_link	*turn_head;
	t_link	*turn_tail;
	t_way	*ways_begin;

	turn_head = end->links;
	while (turn_head && turn_head->cost != -1)
		turn_head = turn_head->next;
	if (!turn_head)
		return (NULL);
	turn_tail = turn_head;
	ft_link_end(&turn_head, &turn_tail);//rewrite
	if (!(ways_begin = ft_ways_ascending(turn_head, turn_tail, start, end)))
		return (NULL);
	ft_null(turn_head, turn_tail, end);
	return (ways_begin);
}
