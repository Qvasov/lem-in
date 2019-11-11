#include "inc/lem-in.h"

t_way		*ft_free_way(t_way **way)
{
	t_way	*tmp;

	while (*way)
	{
		tmp = *way;
		(*way) = (*way)->next;
		free(tmp);
	}
	free(way);
	return (NULL);
}

t_way	*ft_way(t_link *end)
{
	t_way	*way;
	t_way	*tmp;

	way = NULL;
	while (end)
	{
		tmp = way;
		if (!(way = (t_way *)malloc(sizeof(t_way))))
			return (ft_free_way(&tmp));
		way->room = end->room;
		way->next = tmp;
		end = end->parrent;
	}
	return (way);
}

static t_link	*ft_link_start(t_room *start)
{
	t_link	*ptr;

	ptr = start->links->room->links;
	while (ptr)
	{
		if (ptr->room->name == start->name)
		{
			ptr->room->turn_in = 1;
			return (ptr);
		}
		ptr = ptr->next;
	}
	return (NULL);
}

t_way	*ft_bfs(t_data* data)
{
	t_link	*turn_head;
	t_link	*turn_tail;
	t_link	*link;

	turn_head = ft_link_start(data->start);
	turn_tail = turn_head;
	while (turn_head)
	{
		if (turn_head->room->name == data->end->name)
			return ((data->ways = ft_way(turn_head)));
		if 	(turn_head->room->links)
		{
			link = turn_head->room->links;
			while (link)
			{
				if (link->room->turn_in == 0)
				{
					turn_tail->turn_next = link;
					turn_tail = turn_tail->turn_next;
					turn_tail->room->turn_in = 1;
					turn_tail->parrent = turn_head;
				}
				link = link->next;
			}
		}
		turn_head = turn_head->turn_next;
	}
	return (NULL);
}
