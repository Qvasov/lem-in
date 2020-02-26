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
	write(1, "usage:\t./lem-in [-flags] < <lem-in_map>\n"
		  "\t\t-f <lem-in_map> - put the map as an argument\n"
	"\t\t-w alternative output\n", 111);
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
