/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_names.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 21:46:55 by dbennie           #+#    #+#             */
/*   Updated: 2019/10/16 21:46:57 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/lem-in.h"

void	ft_free_names(t_line *names)
{
	free(names->name1);
	names->name1 = NULL;
	free(names->name2);
	names->name2 = NULL;
	names->room1 = NULL;
	names->room2 = NULL;
}
