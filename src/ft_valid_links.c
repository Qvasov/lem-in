/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_links.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddarell <ddarell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:22:43 by dbennie           #+#    #+#             */
/*   Updated: 2020/01/12 13:41:57 by ddarell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_valid_links(char *str, int *f, t_data *data, int j)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '-' && str[i] != ' ')
		i++;
	if (str[i] == '-' && str[i + 1])
	{
		ft_bit_on(f, LINKS);
		if (!data->i_links_start)
			data->i_links_start = j;
		data->i_links_end = j;
		i++;
	}
	while (str[i] && str[i] != '-' && str[i] != ' ')
		i++;
	(str[i] || !(ft_bit_check(*f, LINKS))) ? ft_error(3) : 1;
}
