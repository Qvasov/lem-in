/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:30:08 by dbennie           #+#    #+#             */
/*   Updated: 2019/11/01 18:30:10 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/lem-in.h"

int	ft_read(int fd, char ***data)
{
	int		ret;
	char	buf[10240];
	char	*tmp;
	char	*trash;

	if (data == NULL || !(tmp = ft_strnew(0)))
		return (-1);
	while ((ret = read(fd, &buf, 10239)) > 0)
	{
		buf[ret] = '\0';
		trash = tmp;
		if (!(tmp = ft_strjoin(tmp, buf)))
			return (-1);
		free(trash);
	}
	if (ret < 0)
		return (0);
	if (!(*data = ft_strsplit(tmp, '\n')))
	{
		free(tmp);
		return (-1);
	}
	free(tmp);
	return (1);
}
