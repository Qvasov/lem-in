/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 20:42:35 by dbennie           #+#    #+#             */
/*   Updated: 2019/08/22 20:42:37 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_delelem(t_list *elem)
{
	free(elem->content);
	free(elem);
}

void	ft_freelist(t_list *list)
{
	t_list *elem;

	while (list)
	{
		elem = list;
		list = list->next;
		ft_delelem(elem);
	}
}

char	*ft_frees(char **obj, int strs)
{
	while (--strs >= 0)
		if (obj && obj[strs])
			free(obj[strs]);
	free(obj);
	return (NULL);
}

char	*ft_freetmp1(char *tmp1)
{
	free(tmp1);
	return (NULL);
}

char	*ft_freetmp2(char *tmp1, char *tmp2)
{
	free(tmp1);
	free(tmp2);
	return (NULL);
}
