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

void	ft_names(t_line *names, char *line)
{
	size_t	i;

	names->name1 = NULL;
	names->name2 = NULL;
	i = 0;
	while (names->dash)
		if (line[++i] == '-')
			--names->dash;
	if (!(names->name1 = ft_strsub(line, 0, i)))
		return (ft_error());
	if (!(names->name2 = ft_strsub(line, i + 1, names->len - i)))
	{
		free(names->name1);
		return (ft_error());
	}
}
