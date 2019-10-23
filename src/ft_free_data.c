/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 20:21:44 by dbennie           #+#    #+#             */
/*   Updated: 2019/10/18 20:21:45 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/lem-in.h"

void	ft_free_data(t_data *data)
{
	t_room	*tmp;

	if (!data->tail)
		return;
	while (data->tail->next)
	{
		tmp = data->tail;
		data->tail = data->tail->next;
		free(tmp->name);
		ft_free_links(tmp->links);
		free(tmp);
	}
	free(data->tail->name);
	ft_free_links(data->tail->links);
	free(data->tail);
}
