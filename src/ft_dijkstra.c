#include "inc/lem-in.h"

int	ft_free_path(t_path **path)
{
	t_path	*tmp;

	while (*path)
	{
		tmp = *path;
		(*path) = (*path)->next;
		free(tmp);
	}
	free(path);
	return (0);
}

int	ft_path(t_link *tail, t_way **ways)
{
	t_way	*way;
	t_path	*tmp;
	t_path	*path;
	size_t	cost;

	path = NULL;
	cost = tail->room->cost;
	while (tail)
	{
		tmp = path;
		if (!(path = (t_path *)malloc(sizeof(t_path))))
			return (ft_free_path(&tmp)); // продумать очистку
		path->room = tail->room;
		path->next = tmp;
		tail = tail->parrent;
	}
	if (!(way = (t_way *)malloc(sizeof(t_way))))
		return (0);
	way->path = path;
	way->prev = *ways;
	if (*ways)
		(*ways)->next = way;
	way->path_number = (*ways) ? (*ways)->path_number + 1 : 1;
	way->path_cost = cost;
	way->next = NULL;
	*ways = way;
	return (1);
}

static t_link	*ft_link_start(t_room *start)
{
	t_link	*ptr;

	ptr = (start->links) ? start->links->room->links : NULL;
	if (ptr)
		start->cost = 0;
	while (ptr)
	{
		if (ptr->room->name == start->name)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

int	ft_dijkstra(t_data* data)
{
	t_link	*turn_head;
	t_link	*turn_tail;
	t_link	*link;
	t_link	*end;

	turn_head = ft_link_start(data->start);
	turn_tail = turn_head;
	end = NULL;
	while (turn_head)
	{
		if 	(turn_head->room->links && turn_head->room != data->end)
		{
			link = turn_head->room->links;
			while (link)
			{
				if ((turn_head->room->cost + link->cost < link->room->cost) && \
				(!turn_head->parrent || link->room != turn_head->parrent->room)) //
				{
					if (link->turn_in == 0)
					{
						turn_tail->turn_next = link;
						link->turn_prev = turn_tail;
						link->turn_in = 1;
						turn_tail = turn_tail->turn_next;
					}
					link->parrent = turn_head;
					link->room->cost = turn_head->room->cost + link->cost;
					if (link->room == data->end)
						end = link;
				}
				link = link->next;
			}
		}
		turn_head = turn_head->turn_next;
	}
	if (end)
	{
		if (!ft_path(end, &data->ways))
			return (-1);
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
		return (1);
	}
	return (0);
}
