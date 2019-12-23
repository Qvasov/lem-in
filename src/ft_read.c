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

#include "lemin.h"

int	ft_read(int fd, char ***str_split)
{
	int		ret;
	char	buf[5120];
	char	*str;
	char	*trash;

	if (str_split == NULL || !(str = ft_strnew(0)))
		return (-1);
	while ((ret = read(fd, &buf, 5119)) > 0)
	{
		buf[ret] = '\0';
		trash = str;
		if (!(str = ft_strjoin(str, buf)))
			break; //
		free(trash);
	}
	close(fd);
	if (ret > 0 || ret < 0 || !(*str_split = ft_strsplit(str, '\n')))
		exit(-1);
	free(str);
	return (0);
}
