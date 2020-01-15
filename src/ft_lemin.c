/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 19:21:00 by dbennie           #+#    #+#             */
/*   Updated: 2019/12/05 19:21:04 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	ft_join_text(t_buf *buf, int ant, char *name)
{
	int		j;

	j = -1;
	ft_putchar_buf(buf->str, &buf->i, BUFF_SIZE, 'L');
	ft_putnbr_buf(buf->str, &buf->i, BUFF_SIZE, ant);
	ft_putchar_buf(buf->str, &buf->i, BUFF_SIZE, '-');
	while (name[++j])
		ft_putchar_buf(buf->str, &buf->i, BUFF_SIZE, name[j]);
}

static void	ft_copy(t_data *data, t_path *path, t_buf *buf, int ant)
{
	(buf->space) ? ft_putchar_buf(buf->str, &buf->i, BUFF_SIZE, ' ')
	: (buf->space = 1);
	ft_join_text(buf, ant, path->prev->room->name);
	path->prev->room->ant = (path->prev->room != data->end) ?
							ant : path->prev->room->ant + 1;
	(path->room == data->start) ? --path->room->ant : (path->room->ant = 0);
}

static void	ft_step(t_data *data, int *ant, t_buf *buf)
{
	t_way	*way;
	t_path	*path;

	buf->space = 0;
	way = data->best_var->ways;
	while (way)
	{
		path = way->path;
		while (path)
		{
			if (path->room == data->start && data->start->ant &&
			(way->path_cost < data->best_var->steps || way->path_number == 1))
			{
				ft_copy(data, path, buf, ++*ant);
				++way->ants; //подчсчет кол-ва муравьев проходящих через этот путь
			}
			else if (path->room != data->start && path->room != data->end
			&& path->room->ant)
				ft_copy(data, path, buf, path->room->ant);
			path = path->next;
		}
		way = way->next;
	}
}

void		ft_lemin(t_data *data)
{
	int		ant;
	t_buf	buf;
	int		steps;

	data->start->ant = data->ants;
	ant = 0;
	buf.i = 0;
	steps = data->best_var->steps;
	while (steps)
	{
		ft_step(data, &ant, &buf);
		ft_putchar_buf(buf.str, &buf.i, BUFF_SIZE, '\n');
		--steps;
	}
	write(1, buf.str, buf.i);
}
