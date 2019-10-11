/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 15:24:12 by dbennie           #+#    #+#             */
/*   Updated: 2019/04/15 19:08:05 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*r;

	i = 0;
	if (s && f && (r = ft_strnew(ft_strlen(s))))
	{
		while (s[i])
		{
			r[i] = f(i, s[i]);
			i++;
		}
		return (r);
	}
	return (NULL);
}
