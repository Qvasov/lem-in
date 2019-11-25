#include "inc/lem-in.h"

void	ft_lem_in(t_way *ways, size_t steps, t_room *start, t_room *end)
{
	t_way	*ptr;
	t_path	*path;
	int		n;

	while (steps)
	{
		ptr = ways;
		while (ptr)
		{
			if (steps > ptr->path_cost)
				//path = ptr->path; закидываем муравья и проталкиваем
			else
			{}	//проталкиваем муравья
			ptr = ptr->next;
		}
		--steps;
	}
}
