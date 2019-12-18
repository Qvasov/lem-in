/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 19:16:39 by dbennie           #+#    #+#             */
/*   Updated: 2019/12/05 19:16:41 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_copy_char(char *str, int *i, char c)
{
	if (*i == BUFF_SIZE - 1)
	{
		write(1, str, *i + 1);
		ft_bzero(str, BUFF_SIZE);
		*i = -1;
	}
	str[++*i] = c;
}
