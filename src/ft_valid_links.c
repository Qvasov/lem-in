/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_links.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:22:43 by dbennie           #+#    #+#             */
/*   Updated: 2019/12/11 20:22:44 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/lem-in.h"

int	ft_valid_links(char *str, int *flag, t_data *data, long j)
{
	long	i;

	i = 0;
	if (str[i] == 'L')
		exit(3);
	while (str[++i])
		if (str[i] == '-' && str[i + 1])
		{
			LINKS = 1;
			if (!data->i_links_start)
				data->i_links_start = j;
			data->i_links_end = j;
			return (0);
		}
	exit(3);
}

