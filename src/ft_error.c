/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:44:00 by dbennie           #+#    #+#             */
/*   Updated: 2019/10/18 17:44:01 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	ft_error(t_data *data, char **str_split)
{
	if (data)
		ft_free_data(data);
	if (str_split)
		ft_free_str_split(str_split);
	return (-1);
}
