/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_in.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 19:21:00 by dbennie           #+#    #+#             */
/*   Updated: 2019/12/05 19:21:04 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	ft_join_text(t_buf *buf, size_t ant, char *name)
{
	long	j;

	j = -1;
	ft_copy_char(buf->str, &buf->i, 'L');
	ft_copy_num(buf->str, &buf->i, ant);
	ft_copy_char(buf->str, &buf->i, '-');
	while (name[++j])
		ft_copy_char(buf->str, &buf->i, name[j]);
}

static void	ft_copy(t_data *data, t_path *path, t_buf *buf, size_t ant)
{
	(buf->space) ? ft_copy_char(buf->str, &buf->i, ' ') : (buf->space = 1);
	ft_join_text(buf, ant, path->prev->room->name);
	path->prev->room->ant = (path->prev->room != data->end) ?
							ant : path->prev->room->ant + 1;
	(path->room == data->start) ? --path->room->ant : (path->room->ant = 0);
}

static void	ft_step(t_data *data, size_t *ant, t_buf *buf)
{
	t_way	*way;
	t_path	*path;

	buf->space = 0;
	way = data->old_ways;
	while (way)
	{
		path = way->path;
		while (path)
		{
			if (path->room == data->start && (way->path_cost <= data->old_steps
					|| way->path_number == 1) && data->start->ant)
				ft_copy(data, path, buf, ++*ant);
			else if (path->room != data->start && path->room != data->end &&
					path->room->ant)
				ft_copy(data, path, buf, path->room->ant);
			path = path->next;
		}
		way = way->next;
	}
}

void		ft_lem_in(t_data *data)
{
	size_t	ant;
	t_buf	buf;

	ant = 0;
	ft_bzero(buf.str, BUFF_SIZE);
	buf.i = -1;
	while (data->old_steps)
	{
		ft_step(data, &ant, &buf);
		ft_copy_char(buf.str, &buf.i, '\n');
		--data->old_steps;
	}
	write(1, buf.str, buf.i + 1);
}
