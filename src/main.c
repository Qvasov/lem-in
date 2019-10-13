/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 22:28:23 by dbennie           #+#    #+#             */
/*   Updated: 2019/10/11 22:28:47 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/lem-in.h"

static int	ft_zerodata(t_data *data)
{
	if(!(data->map = ft_strnew(0)))
		return (ft_error());
	data->ants = 0;
	data->farm = NULL;
	data->index = 0;
}

int			main ()
{
	t_data	data;

	ft_zerodata(&data);
	ft_input(data.map);
	ft_valid(); 			//можно валидацию вставить в parse
	ft_parse(&data);
	return (1);
}
