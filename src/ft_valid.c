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

#include "lemin.h"
/*
static void	flg(int f, int offset)
{
	flag[0] = 0;
	flag[1] = 0;
	flag[2] = 0;
	flag[3] = 0;
	flag[4] = 0;
	flag[5] = 0;
}
*/
int			ft_valid(t_data *data, char **strings)
{
	int	i;
	int	f;//let's do it on bits??

	f = 0;
	i = -1;
	while (strings[++i])
	{
		if (strings[i][0] == '\0' || strings[i][0] == 'L')
			ft_error(1);
		else if (strings[i][0] == '#')
			ft_valid_hash(strings[i], &f);
		else if (!(ft_bit_check(f, ANTS)))
			ft_valid_ants(strings[i], &f, data, i);
		else if (ft_bit_check(f, ANTS) && !(ft_bit_check(f, LINKS)) && ft_strchr(strings[i], ' '))
			ft_valid_rooms(strings[i], &f, data, i);
		else if (ft_bit_check(f, ROOMS) && ft_bit_check(f, ANTS) && ft_bit_check(f, START) && ft_bit_check(f, END) && !(ft_bit_check(f, DEF_SE)))
			ft_valid_links(strings[i], &f, data, i);
		else
			ft_error(5);
	}
	if (!(ft_bit_check(f, ANTS)) || !(ft_bit_check(f, ROOMS)) || !(ft_bit_check(f, LINKS)) || !(ft_bit_check(f, START)) || !(ft_bit_check(f, END)))
		ft_error(5);
	ft_valid_duplicates_rooms(data, strings);
//	ft_valid_duplicates_links(data, strings);
	return (0);
}
//valid no minus
