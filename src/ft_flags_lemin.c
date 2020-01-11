#include "lemin.h"

static int	ft_usage()
{
	write(1, "usage: ./lem-in [-flags] < <lem-in_map>\n", 40);
	write(1, "-f <lem-in_map> - put the map as an argument\n", 45);
	exit(0);
}

static void	ft_descriptor(char **fd, int ac, char **av, int *i)
{
	if (++(*i) < ac)
		*fd = av[*i];
	else
		ft_usage();
}

void	ft_flags_lemin(t_flags *flags, int ac, char **av)
{
	int	i;

	flags->fd_path = NULL;
	if (ac == 1)
		return ;
	i = 0;
	while (++i < ac)
	{
		if (ft_strequ(av[i], "-f"))
			ft_descriptor(&flags->fd_path, ac, av, &i);
		else
			ft_usage();
	}
}
