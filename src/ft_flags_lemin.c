/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_lemin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 21:58:17 by dbennie           #+#    #+#             */
/*   Updated: 2020/01/14 21:58:19 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	ft_usage(void)
{
	write(1, "usage: ./lem-in [-flags] < <lem-in_map>\n", 40);
	write(1, "-f <lem-in_map> - put the map as an argument\n", 45);
	write(1, "-w usage dlya a\n", 16); // usage dlya aa
	exit(0);
}

static void	ft_descriptor(char **fd, int ac, char **av, int *i)
{
	if (++(*i) < ac)
		*fd = av[*i];
	else
		ft_usage();
}

void		ft_flags_lemin(t_flags *flags, int ac, char **av)
{
	int	i;

	flags->fd_path = NULL;
	flags->ways = 0;
	if (ac == 1)
		return ;
	i = 0;
	while (++i < ac)
	{
		if (ft_strequ(av[i], "-f"))
			ft_descriptor(&flags->fd_path, ac, av, &i);
		else if (ft_strequ(av[i], "-w"))
			flags->ways = 1;
		else
			ft_usage();
	}
}
