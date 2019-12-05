/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 19:26:04 by dbennie           #+#    #+#             */
/*   Updated: 2019/12/05 19:26:07 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/lem-in.h"

void	ft_free_links(t_link *links)
{
	t_link	*tmp;

	while (links)
	{
		tmp = links;
		links = links->next;
		free(tmp);
	}
}
