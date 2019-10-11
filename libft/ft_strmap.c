/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 22:16:25 by dbennie           #+#    #+#             */
/*   Updated: 2019/04/17 19:11:33 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*r;
	size_t	i;

	i = 0;
	if (s && f && (r = ft_strnew(ft_strlen(s))))
	{
		while (s[i])
		{
			r[i] = f(s[i]);
			i++;
		}
		return (r);
	}
	return (NULL);
}
