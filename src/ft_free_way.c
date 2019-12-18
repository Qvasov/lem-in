/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_way.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 19:24:53 by dbennie           #+#    #+#             */
/*   Updated: 2019/12/05 19:24:54 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	*ft_free_path(t_path *path)
{
	t_path	*tmp;

	while (path)
	{
		tmp = path;
		path = path->next;
		free(tmp);
	}
	return (NULL);
}

void	ft_free_way(t_way *way)
{
	t_path	*path;
	t_way	*ptr;

	while (way)
	{
		ptr = way;
		way = way->next;
		path = ptr->path;
		ft_free_path(path);
		free(ptr);
	}
}
