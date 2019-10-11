/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 19:48:28 by dbennie           #+#    #+#             */
/*   Updated: 2019/04/16 15:13:56 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *l;

	if (!(l = malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		l->content_size = 0;
		l->content = NULL;
	}
	else
	{
		l->content = malloc(content_size);
		if (!l->content)
		{
			free(l);
			return (NULL);
		}
		else
		{
			ft_memmove(l->content, content, content_size);
			l->content_size = content_size;
		}
	}
	l->next = NULL;
	return (l);
}
