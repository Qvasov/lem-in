/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:54:49 by dbennie           #+#    #+#             */
/*   Updated: 2019/04/15 18:55:14 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	f;

	i = 0;
	f = 0;
	while (s[i] || (s[i] == '\0' && s[i] == c))
	{
		if (s[i] == c && c != '\0')
			f = i;
		else if (s[i] == c && c == '\0')
			return ((char *)&s[i]);
		i++;
	}
	if (s[f] == c)
		return ((char *)&s[f]);
	return (NULL);
}
