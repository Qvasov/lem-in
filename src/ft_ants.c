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

int	ft_ants(t_data *data, char **strings)
{
	data->ants = ft_atoll(strings[data->i_ants]);
//	data->ants_define = 1;
	return (0);
}
