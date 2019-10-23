/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_names.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 20:17:51 by dbennie           #+#    #+#             */
/*   Updated: 2019/10/16 20:17:52 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/lem-in.h"

int	ft_names(t_line *names, char *line)
{
	size_t	i;

	names->name1 = NULL;
	names->name2 = NULL;
	names->room2 = NULL;
	names->room1 = NULL;
	names->len = ft_strlen(line);
	names->dash = 1;
	i = 0;
	while (names->dash)
		if (line[++i] == '-')
			--names->dash;
	if (!(names->name1 = ft_strsub(line, 0, i)))
		return (0);
	if (!(names->name2 = ft_strsub(line, i + 1, names->len - i)))
	{
		free(names->name1);
		return (0);
	}
	return (1);
}
