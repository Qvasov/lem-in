/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddarell <ddarell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 20:06:00 by dbennie           #+#    #+#             */
/*   Updated: 2020/01/12 13:40:22 by ddarell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	valid_strings(t_data *data, char *str, int i, int *f)
{
	if (str[0] == '\0' || str[0] == 'L')
		ft_error(1);
	else if (str[0] == '#')
		ft_valid_hash(str, f);
	else if (!(ft_bit_check(*f, ANTS)))
		ft_valid_ants(str, f, data, i);
	else if (ft_bit_check(*f, ANTS) && !(ft_bit_check(*f, LINKS)) &&
			ft_strchr(str, ' '))
		ft_valid_rooms(str, f, data, i);
	else if (ft_bit_check(*f, ROOMS) && ft_bit_check(*f, ANTS) &&
			ft_bit_check(*f, START) && ft_bit_check(*f, END) &&
			!(ft_bit_check(*f, DEF_SE)))
		ft_valid_links(str, f, data, i);
	else
		ft_error(5);
}

int			ft_valid(t_data *data, char **strings)
{
	int	i;
	int	f;

	f = 0;
	i = -1;
	while (strings[++i])
		valid_strings(data, strings[i], i, &f);
	if (!(ft_bit_check(f, ANTS) && ft_bit_check(f, ROOMS) &&
			ft_bit_check(f, LINKS) && ft_bit_check(f, START) &&
			ft_bit_check(f, END)))
		ft_error(5);
	ft_valid_duplicates_rooms(data, strings);
//	ft_valid_duplicates_links(data, strings);
	return (0);
}
