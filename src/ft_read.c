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

int	ft_read(int fd, char ***str_split)
{
	int		ret;
	char	buf[5120];
	char	*tmp;
	char	*trash;

	if (str_split == NULL || !(tmp = ft_strnew(0)))
		return (-1);
	while ((ret = read(fd, &buf, 5119)) > 0)
	{
		buf[ret] = '\0';
		trash = tmp;
		tmp = ft_strjoin(tmp, buf);
		free(trash);
		if (!tmp)
			return (-1);
	}
	if (ret < 0 || !(*str_split = ft_strsplit(tmp, '\n')))
	{
		free(tmp);
		return (-1);
	}
	free(tmp);
	return (0);
}
