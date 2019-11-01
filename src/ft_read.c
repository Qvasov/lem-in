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

int	ft_read(int fd, char **line)
{
	int		ret;
	char	buf[10240];
	char	*tmp;
	int		i;

	i = -1;
	if (line == NULL || !(tmp = ft_strnew(0)))
		return (-1);
	while ((ret = read(fd, &buf, 1)) > 0)
	{
		//if (i > 2)
		//	ft_error(s, NULL, NULL);
		if (buf == '\n' || buf == '\0')
		{
			if (ft_op(s, tmp) == 0)
				ft_error(s, NULL, NULL);
			ft_bzero(tmp, 5);
			i = -1;
		}
		else
			tmp[++i] = buf;
	}
	return ((ret == 0 && i == -1) ? 1 : -1);
}
