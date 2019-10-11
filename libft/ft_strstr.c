/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 22:14:00 by dbennie           #+#    #+#             */
/*   Updated: 2019/04/15 20:18:19 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	if (needle[j] == '\0')
		return ((char *)haystack);
	while (haystack[i])
	{
		while (needle[j] == haystack[k + i])
		{
			j++;
			k++;
			if (needle[j] == '\0')
				return ((char *)&haystack[k + i - j]);
		}
		j = 0;
		k = 0;
		i++;
	}
	return (NULL);
}
