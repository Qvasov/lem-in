/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_farm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 20:04:05 by dbennie           #+#    #+#             */
/*   Updated: 2019/10/13 20:04:06 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/lem-in.h"

static t_room	*ft_createroom(char *name)
{

}

static int		ft_createfarm(t_data *data, int rooms)
{
	t_room	*tmp;


	if (!(data->farm = (t_room **)malloc(sizeof(t_room *) * (rooms + 1))))
		return(ft_error());
	data->farm[rooms] = NULL;

}

static void 	ft_rooms(t_data *data, size_t *rooms)
{
	long 	i;
	long	j;
	t_room 	*room;

	i = data->index - 1;
	room = NULL;
	while (data->map[++i])
	{
		if (data->map[i] == '#') // start i and
			while (data->map[i] != '\n')
				++i;
		else
		{
			while (data->map[i] != '\n')
			{
				j = 0;
				while (data->map[i] == ' ')
					++j;
				// schitavanie imeni
				room = ft_createroom(&data->map[i] - j, j);
				++j;
				++i;
			}
			if (!f)
				break;
			++(*rooms);
		}
	}
}

void			ft_farm(t_data *data)
{
	size_t	rooms;

	rooms = 0;
	ft_rooms(data, &rooms);
	ft_createfarm(data, rooms);


}
