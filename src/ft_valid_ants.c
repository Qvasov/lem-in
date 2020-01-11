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

int	ft_valid_ants(char *str, int *f, t_data *data, int j)
{
//	int		i;
	int 	flag;
//	char	*tmp;

//	i = -1;

	if (!(*str == '+' || (*str <= '9' && *str >= '0')))
		ft_error(1);
	data->ants = ft_satoi(str, &flag); //saving ant results
	if (!(flag) || *(str + flag))
		ft_error(1);
/*
	while (str[++i])
		if (!(str[i] >= '0' && str[i] <= '9') || i >= 20)
			ft_error(1);
	tmp = ft_ulltoa(ft_atoull(str));//too complex
	if (ft_strcmp(tmp, str))
		ft_error(1);
	free(tmp);*/

	ft_bit_on(f, ANTS);
	data->i_ants = j;//mb no need
	return (0);
}
