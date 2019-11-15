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
	size_t	len;

	path = NULL;
	len = 0;
	tail->room->turn_in = 0;
	while (tail)
	{
		tmp = path;
		if (!(path = (t_path *)malloc(sizeof(t_path))))
			return (ft_free_path(&tmp));
		path->room = tail->room;
		path->next = tmp;
		//tail->path_in = 1;
		tail = tail->parrent;
		++len;
	}

	if (!(way = (t_way *)malloc(sizeof(t_way))))
		return (0);
	way->path = path;
	way->prev = *ways;
	if (*ways)
		(*ways)->next = way;
	way->path_number = (*ways) ? (*ways)->path_number + 1 : 1;
	way->path_lenght = len;
	way->next = NULL;
	*ways = way;
	return (1);
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

int	ft_bfs(t_data* data)
{
	t_link	*turn_head;
	t_link	*turn_tail;
	t_link	*link;

	turn_head = ft_link_start(data->start);
	turn_tail = turn_head;
	while (turn_head)
	{
//		if (turn_tail->room->name == data->end->name && turn_tail->room->turn_in)
//		{
//			if (!ft_path(turn_tail, &data->ways))
//				return (-1);
//			while (turn_tail)
//			{
//				turn_tail->room->turn_in = 0;
//				turn_tail = turn_tail->turn_prev;
//			}
//			return (1);
//		}
		if 	(turn_head->room->links)
		{
			link = turn_head->room->links;
			while (link)
			{
				if (link->room->turn_in == 0)
				{
					turn_tail->turn_next = link;
					link->turn_prev = turn_tail;
					turn_tail = turn_tail->turn_next;
					turn_tail->room->turn_in = 1;
					turn_tail->room->room_double->turn_in = 1;
					turn_tail->parrent = turn_head;
					if (turn_tail->room == data->end)
					{
						if (!ft_path(turn_tail, &data->ways))
							return (-1);
						while (turn_tail)
						{
							turn_tail->room->turn_in = 0;
							turn_tail = turn_tail->turn_prev;
						}
						return (1);
					}
				}
				link = link->next;
			}
		}
		turn_head = turn_head->turn_next;
	}
	return (0);
}
