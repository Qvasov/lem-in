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

int	ft_valid_rooms(char *str)
{
	long	i;
	int		space;

	i = 0;
	space = 0;
	if (str[i] == 'L')
		exit(2);
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
	return (0);
}
