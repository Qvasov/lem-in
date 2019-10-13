/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ants.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 20:02:28 by dbennie           #+#    #+#             */
/*   Updated: 2019/10/13 20:02:32 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/lem-in.h"

void	ft_ants(t_data *data)
{
	long		i;
	char 	tmp[20];

	i = -1;
	while (data->map[++i] != '\n')
		tmp[i] = data->map[i];
	tmp[i] = '\0';
	data->ants = (size_t)ft_atoll(tmp);
	data->index = i + 1;
}
