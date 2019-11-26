#include "inc/lem-in.h"

static t_path	*ft_path(t_link *tail, size_t *cost, t_room *end)
{
	t_path	*path;
	t_path	*tmp;

	path = NULL;
	while (tail)
	{
		tmp = path;
		if (!(path = (t_path *)malloc(sizeof(t_path))))
			return ((void *)ft_free_path(tmp));
		path->room = (tail->room->room_in) ? tail->room->room_in : tail->room;
		path->next = tmp;
		if (tmp)
			tmp->prev = path;
		++(*cost);
		tail = tail->parrent;
	}
	tmp = path;
	if (!(path = (t_path *)malloc(sizeof(t_path))))
		return ((void *)ft_free_path(tmp));
	path->room = end;
	path->next = tmp;
	path->prev = NULL;
	if (tmp)
		tmp->prev = path;
	return (path);
}

static t_way	*ft_add_path(t_link *tail, t_way *ways, t_room *end)
{
	t_path	*path;
	t_way	*way;
	size_t	cost;

	cost = 0;
	if (!(path = ft_path(tail, &cost, end)))
		return (NULL);
	if (!(way = (t_way *)malloc(sizeof(t_way))))
		return ((void *)ft_free_path(path));
	way->path = path;
	way->path_cost = cost;
	if (ways)
		ways->next = way;
	way->prev = ways;
	way->next = NULL;
	way->path_number = ways ? ways->path_number + 1 : 1;
	ways = way;
	return (ways);
}

t_way			*ft_paths_ascending(t_room *start, t_room *end)
{
	t_link	*turn_head;
	t_link	*turn_tail;
	t_link	*link;
	t_way	*ways;
	t_way	*ways_begin;

	ways = NULL;
	ways_begin = NULL;
	turn_head = end->links;
	while (turn_head && turn_head->cost != -1)
		turn_head = turn_head->next;
	if (!turn_head)
		return (NULL);
	turn_tail = turn_head;
	link = turn_head->next;
	while (link)
	{
		if (link->cost == -1)
		{
			turn_tail->turn_next = link;
			turn_tail = turn_tail->turn_next;
		}
		link = link->next;
	}

	while (turn_head)
	{
		link = (turn_head->room->room_in) ? turn_head->room->room_in->links : turn_head->room->links;
		while (link)
		{
			while (link && link->cost != -1)
				link = link->next;
			if (link && link->cost == -1)
			{
				turn_tail->turn_next = link;
				link->parrent = turn_head;
				turn_tail = turn_tail->turn_next;
				if (turn_tail->room == start)
				{
					if (!(ways = ft_add_path(turn_tail, ways, end)))
						return (NULL);
					if (!ways_begin)
						ways_begin = ways;
				}
				break;
			}
		}
		turn_head = turn_head->turn_next;
	}
	//зануление turn;
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
	return (ways_begin);
}
