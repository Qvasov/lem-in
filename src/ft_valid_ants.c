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

#include "lemin.h"

int	ft_valid_ants(char *str, int *f, t_data *data)
{
	int	flag;

	if (!(*str == '+' || (*str <= '9' && *str >= '0')))
		ft_error(1);
	data->ants = ft_satoi(str, &flag);
	if (!(flag) || *(str + flag))
		ft_error(1);
	ft_bit_on(f, ANTS);
	return (0);
}
