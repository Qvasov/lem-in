#include "lemin.h"

static void		ft_create_way(t_path *path, int path_cost, t_way **ways)
{
	t_way	*way;

	if (!(way = (t_way *)malloc(sizeof(t_way))))
		ft_perror();
	way->path = path;
	way->path_number = (*ways) ? (*ways)->path_number + 1 : 1;
	way->path_cost = path_cost;
	way->ants = 0;
	way->prev = NULL;
	way->next = *ways;
	if (*ways)
		(*ways)->prev = way;
	*ways = way;
}

static void		ft_path(t_link *tail, t_way **ways)
{
	t_path	*tmp;
	t_path	*path;
	int		path_cost;

	path = NULL;
	path_cost = tail->room->cost;
	while (tail)//loop of the cycle on b_loop when ways_count == 13
	{
		tmp = path;
		if (!(path = (t_path *)malloc(sizeof(t_path))))
			ft_perror();
		path->room = tail->room;
		path->next = tmp;
		path->prev = NULL;
		if (tmp)
			tmp->prev = path;
		tail = tail->parrent;
	}
	ft_create_way(path, path_cost, ways);
}

static t_link	*ft_link_start(t_room *start)
{
	t_link		*ptr;

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

static void	inf(int *d, int room_count)
{
	int	i;

	i = 0;
	d[i] = 0;
	while (++i < room_count)
		d[i] = 0x7FFFFFFF;
}

int			ft_ford(t_data *data)
{
	t_link	*head;
	t_link	*tail;
	t_link	*end;

	head = ft_link_start(data->start);
	tail = head;
	end = NULL;
	while (head)
	{
		if (head->room->links && head->room != data->end)
		{
			ft_turn(&head, &tail, data);
			(head->room == data->end) ? end = head : 0;
		}
		head = head->turn_next;
	}
	if (end)
	{
		ft_path(end, &data->ways_dij);
		ft_turn_null(tail);
		return (1);
	}
	return (0);
}

