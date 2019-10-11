/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 21:36:08 by dbennie           #+#    #+#             */
/*   Updated: 2019/04/15 18:43:39 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	ls;
	size_t	ld;

	i = 0;
	j = 0;
	ls = ft_strlen(src);
	ld = ft_strlen(dst);
	while (dst[i])
		i++;
	if (ld < size)
	{
		while (src[j] && j < (size - ld - 1))
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
		return (ld + ls);
	}
	else
		return (ls + size);
}
