/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_str_split.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:09:52 by dbennie           #+#    #+#             */
/*   Updated: 2019/11/06 14:09:52 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_free_str_split(char **str_split)
{
	size_t	i;

	i = 0;
	while (str_split[i])
		free(str_split[i++]);
	free(str_split);
}
