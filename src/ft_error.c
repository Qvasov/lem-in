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

#include "inc/lem-in.h"

int	ft_error(t_data *data, char **dat)
{
	if (data)
		ft_free_data(data);
	if (dat)
		free(dat); //очистака сплита двумерного line
	return (0);
}