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

int	ft_lemin_read(int fd, char ***str_split)
{
	int		ret;
	char	buf[16385];
	char	*str;
	char	*trash;

	if (/*str_split == NULL ??? || */!(str = ft_strnew(0)))
		return (-1);
	while ((ret = read(fd, &buf, 16384)) > 0)
	{
		buf[ret] = '\0';
		trash = str;
		if (!(str = ft_strjoin(str, buf)))
			ft_perror();
		free(trash);
	}
	if ((close(fd)) == -1)
		ft_perror();
	if (ret < 0 || !(*str_split = ft_strsplit(str, '\n')))//ret != 0
		ft_perror();
	free(str);
	return (0);
}
// what about multiple \n case??
// ft_strsplit costs a lot of resources, mb we can use only str
// read and close must be preserved))
