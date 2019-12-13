/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_rooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:59:52 by dbennie           #+#    #+#             */
/*   Updated: 2019/12/11 18:59:53 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/lem-in.h"

int	ft_valid_rooms(char *str, int *flag, t_data *data, long j)
{
	long	i;
	int		space;

	i = 0;
	space = 0;
	while (str[i] && space == 0)
		if (str[++i] == ' ')
			space = 1;
	if (!str[i] || !ft_isnum(&str[++i], ' '))
		exit(2);
	while (str[i] && space == 1)
		if (str[++i] == ' ')
			space = 2;
	if (!str[i] || !ft_isnum(&str[++i], '\0'))
		exit(2);
	ROOMS = 1;
	if (!data->i_rooms_start)
		data->i_rooms_start = j;
	data->i_rooms_end = j;
	if (!data->i_start && START && DEF_SE)
		data->i_start = j;
	else if (!data->i_end && END && DEF_SE)
		data->i_end = j;
	DEF_SE = 0;
	return (0);
}
