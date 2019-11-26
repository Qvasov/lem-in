#include "inc/lem-in.h"

void	ft_lem_in(t_way *ways, size_t steps, t_room *start, t_room *end)
{
	t_way	*ptr_way;
	t_path	*ptr_path;
	size_t	ant;
	size_t	ant_turn;

	ant = 0;
	ant_turn = 0;
	while (steps)
	{
		ptr_way = ways;
		while (ptr_way)
		{
			ptr_path = ptr_way->path;
			while (ptr_path)
			{
				if (ptr_path->room == start && (steps >= ptr_way->path_cost || ptr_way->path_number == 1)
				&& start->ant)
				{
					++ant_turn;
					ant = ant_turn;
					--start->ant;
				}
				else if (ptr_path->room == end && ant)
				{
					ant = 0;
					++end->ant;
				}
				else if (ptr_path->room->ant && ant && ptr_path->room != end && ptr_path->room != start)
				{

					ptr_path->room->ant = ant;
					ant = 0;
					ft_printf("L%llu-%s", ptr_path->room->ant, ptr_path->room->name);
				}
				else if (!ptr_path->room->ant && ant && ptr_path->room != end && ptr_path->room != start)
				{
					ptr_path->room->ant = ant;
					ant = 0;
					ft_printf("L%llu-%s", ptr_path->room->ant, ptr_path->room->name);
				}
				else if (ptr_path->room->ant && !ant && ptr_path->room != start && ptr_path->room != end)
				{
					ptr_path->room->ant = 0;
					ant = ptr_path->room->ant;
				}
				ptr_path = ptr_path->next;
			}
			ptr_way = ptr_way->next;
		}
		write(1, "\n", 1);
		--steps;
	}
	if (start->ant == 0 && end->ant == 9 && ant == 0)
		write(1, "OK", 2);
}
