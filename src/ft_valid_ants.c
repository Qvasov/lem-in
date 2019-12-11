/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_ants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 15:52:39 by dbennie           #+#    #+#             */
/*   Updated: 2019/12/11 15:52:41 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/lem-in.h"

int	ft_valid_ants(char *str)
{
	long	i;
	char	*tmp;

	i = -1;
	while (str[++i])
		if (!(str[i] >= '0' && str[i] <= '9') || i >= 20)
			exit(1);
	tmp = ft_ulltoa(ft_atoull(str));
	if (ft_strcmp(tmp, str))
		exit(1);
	free(tmp);
	return (0);
}
