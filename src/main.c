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
//	data->ants = 0;
//	data->farm = NULL;
//	data->index = 0;
	data->start_define = 0;
	data->end_define = 0;
	data->ants_define = 0;
	data->rooms_define = 0;
	data->links_define = 0;
	return (1);
}

int			main()
{
	t_data	data;

	ft_zerodata(&data);
	ft_parse(&data);

}
