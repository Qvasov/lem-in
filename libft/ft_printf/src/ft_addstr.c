/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 20:56:36 by dbennie           #+#    #+#             */
/*   Updated: 2019/08/22 20:56:38 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_add_minus(t_format *form, char *num, char *tmp)
{
	form->str = ft_strcpy(form->str, num);
	form->str[form->len] = '\0';
	form->str = ft_strcat(form->str, tmp);
}

static void	ft_add(t_format *form, char *num, char *tmp, int l)
{
	form->str = ft_strcpy(form->str, tmp);
	form->str[l] = '\0';
	form->str = ft_strcat(form->str, num);
}

void		ft_addstr(t_format *form, int l, char c, int flagminus)
{
	char	*tmp;
	char	*num;
	int		j;

	if (!(tmp = (char *)malloc(sizeof(char) * (l + 1))))
		exit(0);
	tmp[l] = '\0';
	j = -1;
	while (++j < l)
		tmp[j] = c;
	num = form->str;
	if (!(form->str = (char *)malloc(sizeof(char) * (l + form->len + 1))))
	{
		free(tmp);
		exit(0);
	}
	form->str[l + form->len] = '\0';
	if (flagminus)
		ft_add_minus(form, num, tmp);
	else
		ft_add(form, num, tmp, l);
	free(num);
	free(tmp);
	form->len += l;
}
