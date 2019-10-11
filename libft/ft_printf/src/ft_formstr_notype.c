/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formstr_no.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 17:13:50 by dbennie           #+#    #+#             */
/*   Updated: 2019/08/24 17:13:54 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_printf_notype(t_format *form)
{
	char	*buf;

	form->len = 1;
	if (!(buf = ft_strdup(&form->type)))
		return (NULL);
	return (buf);
}

void		ft_formstr_notype(t_format *form)
{
	if (!(form->str = ft_printf_notype(form)))
		exit(0);
	else if ((form->w && form->f[4] && !form->f[0]) && form->w > form->len)
		ft_addstr(form, form->w - form->len, '0', 0);
	if (form->w > form->len)
	{
		if (form->f[0])
			ft_addstr(form, form->w - form->len, ' ', 1);
		else
			ft_addstr(form, form->w - form->len, ' ', 0);
	}
}
