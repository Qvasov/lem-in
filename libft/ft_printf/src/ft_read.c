/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:37:42 by dbennie           #+#    #+#             */
/*   Updated: 2019/08/26 16:37:43 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_read(int *j, const char *s, long long *i)
{
	char	*buf;
	char	*tmp;
	char	c[2];

	c[1] = '\0';
	if (!(buf = ft_strnew(0)))
		exit(0);
	while (s[*i] >= '0' && s[*i] <= '9')
	{
		tmp = buf;
		c[0] = s[(*i)++];
		if (!(buf = ft_strjoin(tmp, &c[0])))
			exit(0);
		free(tmp);
		*j = ft_atoi(buf);
		if (*j > MAXWIDHT)
		{
			free(buf);
			exit(0);
		}
	}
	--(*i);
	free(buf);
}
