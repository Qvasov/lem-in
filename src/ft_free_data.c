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

#include "lemin.h"

static void	ft_free_links(t_link *links)
{
	t_link	*tmp;

	while (links)
	{
		tmp = links;
		links = links->next;
		free(tmp);
	}
}

static void	ft_free_path(t_path *path)
{
	t_path	*tmp;

	while (path)
	{
		tmp = path;
		path = path->next;
		free(tmp);
	}
}

static void	ft_free_ways(t_way *way)
{
	t_way	*tmp;

	while (way)
	{
		tmp = way;
		way = way->next;
		ft_free_path(tmp->path);
		free(tmp);
	}
}

static void ft_free_vars(t_var *vars)
{
	t_var	*tmp;

	while (vars)
	{
		tmp = vars;
		vars = vars->next;
		ft_free_ways(tmp->ways);
		free(tmp);
	}
}

void		ft_free_data(t_data *data)
{
	t_room	*tmp;

	while (data->rooms)
	{
		tmp = data->rooms;
		data->rooms = data->rooms->next;
		free(tmp->name);
		ft_free_links(tmp->links);
		if (tmp->room_out)
		{
			free(tmp->room_out->name);
			ft_free_links(tmp->room_out->links);
		}
		free(tmp->room_out);
		free(tmp);
	}
	ft_free_ways(data->ways_dij);
	ft_free_vars(data->vars);
}
