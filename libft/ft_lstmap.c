/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 17:48:39 by dbennie           #+#    #+#             */
/*   Updated: 2019/04/17 19:16:53 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newl;

	if (!lst || !f)
		return (NULL);
	if (!(newl = malloc(sizeof(t_list))))
		return (NULL);
	*newl = *f(lst);
	if (lst->next)
	{
		newl->next = ft_lstmap(lst->next, f);
		if (!newl->next)
		{
			free(newl->content);
			free(newl);
			return (NULL);
		}
	}
	return (newl);
}
