/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 18:10:12 by dbennie           #+#    #+#             */
/*   Updated: 2019/10/13 18:10:13 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/lem-in.h"

int	ft_input(char *map)
{
	char	*tmp;
	char	*buf;
	int		ret;

	if (!(buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (ft_error());
	buf[BUFF_SIZE] = '\0';
	while ((ret = read(0, buf, BUFF_SIZE)) >= 0)
	{
		buf[ret] = '\0';
		if (!(tmp = ft_strjoin(map, buf)))
			return (ft_error());
		free(map);
		map = tmp;
	}
	if (ret < 0)
		return (ft_error());
	return (1);
}
