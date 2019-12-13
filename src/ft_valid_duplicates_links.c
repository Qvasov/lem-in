/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_duplicates_links.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:58:27 by dbennie           #+#    #+#             */
/*   Updated: 2019/12/11 20:58:28 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/lem-in.h"

static int	ft_linkcmp(char *link1, char *link2)
{
	int		i;
	int		j;

	i = -1;
	while (link1[++i] && link2[i])
		if (link1[i] != link2[i])
		{
			j = i;
			while (link1[i] && link1[i] != '-')
				++i;
			while (link2[j] && link2[j] != '-')
				++j;
			if (link1[i] == '-' && link2[j] == '-' && \
			ft_linkcmp(link1, &link2[j]) && ft_linkcmp(link2, &link1[i]))
				return (1);
			return (0);
		}
	return (1);
}

int		ft_valid_duplicates_links(t_data *data, char **strings)
{
	long	i;
	long	j;

	i = data->i_links_start - 1;
	while (++i <= data->i_links_end)
	{
		j = i;
		while (++j <= data->i_links_end)
			if (ft_linkcmp(strings[i], strings[j]))
				exit(3);
	}
	return (0);
}
