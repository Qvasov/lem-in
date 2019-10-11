/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addbuf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 20:46:02 by dbennie           #+#    #+#             */
/*   Updated: 2019/08/22 20:46:04 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_addtoend(t_format *form, t_list *new)
{
	if (new)
	{
		if (!form->list)
		{
			form->list = new;
			form->tail = form->list;
		}
		else
		{
			form->tail->next = new;
			form->tail = new;
		}
	}
}

void		ft_addbuf(t_buf *buf, t_format *form)
{
	t_list	*new;

	if (buf->len >= BUFF_SIZE - 1)
	{
		if (!(new = ft_lstnew(buf->str, buf->len)))
		{
			ft_freelist(form->list);
			exit(0);
		}
		ft_addtoend(form, new);
		buf->len = 0;
	}
}
