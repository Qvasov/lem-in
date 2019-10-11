/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_correctmod.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 20:45:42 by dbennie           #+#    #+#             */
/*   Updated: 2019/08/22 20:45:44 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_correctmod(t_format *form)
{
	if (form->mod[0] == 'l' && form->mod[1] == '\0')
		return (4);
	else if ((form->mod[0] == 'l' && form->mod[1] == 'l') || \
			(form->mod[0] == 'L' && form->mod[1] == '\0'))
		return (8);
	else if (form->mod[0] == 'h' && form->mod[1] == '\0')
		return (2);
	else if (form->mod[0] == 'h' && form->mod[1] == 'h')
		return (1);
	else if (form->mod[0] == 'j')
		return (6);
	else if (form->mod[0] == 'z')
		return (7);
	return (0);
}
