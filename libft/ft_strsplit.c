/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:04:09 by dbennie           #+#    #+#             */
/*   Updated: 2019/04/15 22:24:38 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numstrs(const char *str, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
			j++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (j);
}

static size_t	ft_arrstrs(char **r, const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	f;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			return (0);
		f = i;
		while (s[i] && s[i] != c)
			i++;
		if (!(r[k] = (char *)malloc(sizeof(char) * (i - f + 1))))
			return (k);
		r[k][i - f] = '\0';
		j = 0;
		while (s[f] && s[f] != c)
			r[k][j++] = s[f++];
		k++;
	}
	return (0);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	j;
	size_t	k;
	char	**r;

	if (!s)
		return (NULL);
	if (c == '\0')
		if (!(ft_strdup(s)))
			return (NULL);
	j = ft_numstrs(s, c);
	r = (char **)malloc(sizeof(char *) * (j + 1));
	if (!r)
		return (NULL);
	r[j] = NULL;
	k = ft_arrstrs(r, s, c);
	if (k == 0)
		return (r);
	j = 0;
	while (j < k)
		free(r[j++]);
	free(r);
	return (NULL);
}
