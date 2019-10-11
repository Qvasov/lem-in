/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 13:50:13 by dbennie           #+#    #+#             */
/*   Updated: 2019/08/27 13:50:14 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_addcolor(t_buf *buf, const char *color)
{
	size_t	i;

	i = 0;
	while (color[i])
		buf->str[buf->len++] = color[i++];
}

static int	ft_compare(t_buf *buf, char *str)
{
	if (!(ft_strcmp(str, "green")))
		ft_addcolor(buf, GREEN);
	else if (!(ft_strcmp(str, "red")))
		ft_addcolor(buf, RED);
	else if (!(ft_strcmp(str, "cyan")))
		ft_addcolor(buf, CYAN);
	else if (!(ft_strcmp(str, "yellow")))
		ft_addcolor(buf, YELLOW);
	else if (!(ft_strcmp(str, "white")))
		ft_addcolor(buf, WHITE);
	else if (!(ft_strcmp(str, "purple")))
		ft_addcolor(buf, PURPLE);
	else if (!(ft_strcmp(str, "blue")))
		ft_addcolor(buf, BLUE);
	else if (!(ft_strcmp(str, "eoc")))
		ft_addcolor(buf, NORM);
	else
		return (0);
	return (1);
}

void		ft_color(t_buf *buf, const char *s, long long *i)
{
	long long	r;
	char		*sub;

	r = 1;
	if (s[r])
	{
		while (s[r] && s[r] != '}')
			++r;
		if (!(sub = ft_strsub(s, 1, r - 1)))
			exit(0);
		if (ft_compare(buf, sub))
			*i = *i + r + 1;
		ft_strdel(&sub);
	}
}
