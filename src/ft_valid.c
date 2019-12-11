/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 20:06:00 by dbennie           #+#    #+#             */
/*   Updated: 2019/10/14 20:06:02 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/lem-in.h"

void	ft_zero_flag(int *flag)
{
	flag[0] = 0;
	flag[1] = 0;
	flag[2] = 0;
	flag[3] = 0;
	flag[4] = 0;
	flag[5] = 0;
}

int	ft_valid(t_data *data, char **strings)
{
	long	i;
	int		flag[6];

	ft_zero_flag(flag);
	i = -1;
	while (strings[++i])
	{
//		if (strings[i][0] == '\0' || strings[i][0] == 'L') //nuzhen li \0
//			exit(1);
		if (strings[i][0] == '#')
			ft_valid_hash(strings[i], flag);
		else if (!ANTS)
		{
			ft_valid_ants(strings[i]);
			ANTS = 1;
			data->i_ants = i;
		}
		else if (ANTS && !LINKS && ft_strchr(strings[i], ' '))
		{
			ft_valid_rooms(strings[i]);
			ROOMS = 1;
			if (!data->i_rooms_start)
				data->i_rooms_start = i;
			data->i_rooms_end = i;
			if (!data->i_start && START && DEF_SE)
				data->i_start = i;
			else if (!data->i_end && END && DEF_SE)
				data->i_end = i;
			DEF_SE = 0;
		}
		else if (ROOMS && ANTS && START && END && !DEF_SE)
		{
			ft_valid_links(strings[i]);
			LINKS = 1;
			if (!data->i_links_start)
				data->i_links_start = i;
			data->i_links_end = i;
		}
		else
			exit(5);
	}
	ft_valid_duplicates_rooms(data, strings);
	ft_valid_duplicates_links(data, strings);
	return (0);
}
