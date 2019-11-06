#include "inc/lem-in.h"

void	ft_free_links(t_link *links)
{
	t_link	*tmp;

	while (links)
	{
		tmp = links;
		links = links->next;
		free(tmp);
	}
}
