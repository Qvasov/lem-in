/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:18:31 by dbennie           #+#    #+#             */
/*   Updated: 2019/04/19 21:06:36 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;

	if (s1 && s2)
		if ((r = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
			return (ft_strcat(ft_strcpy(r, s1), s2));
	return (NULL);
}
