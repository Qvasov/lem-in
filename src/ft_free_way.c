#include "inc/lem-in.h"

int		ft_free_path(t_path *path)
{
	t_path	*tmp;

	while (path)
	{
		tmp = path;
		path = path->next;
		free(tmp);
	}
	return (0);
}

void	ft_free_way(t_way *way)
{
	t_path	*path;
	t_way	*ptr;

	while (way)
	{
		ptr = way;
		way = way->next;
		path = ptr->path;
		ft_free_path(path);
		free(ptr);
	}
}
