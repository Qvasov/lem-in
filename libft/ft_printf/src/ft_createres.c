/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createres.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 20:45:21 by dbennie           #+#    #+#             */
/*   Updated: 2019/08/22 20:45:23 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_createres(t_format *form, char *tmp1, char *tmp2)
{
	char	*res;
	int		i;

	i = form->len;
	if (form->p)
		form->len = form->len + 1 + form->p;
	if (!(res = (char *)malloc(sizeof(char) * (form->len + 1))))
		return (ft_freetmp2(tmp1, tmp2));
	res[form->len] = '\0';
	res = ft_strcpy(res, tmp1);
	if (form->p)
	{
		res[i] = '.';
		res[i + 1] = '\0';
		if (tmp2)
			res = ft_strncat(res, tmp2, form->p);
		while (res[i])
			++i;
		while (i < form->len)
			res[i++] = '0';
	}
	ft_freetmp2(tmp1, tmp2);
	return (res);
}
