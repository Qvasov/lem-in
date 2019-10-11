/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 20:43:58 by dbennie           #+#    #+#             */
/*   Updated: 2019/08/22 20:43:59 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_find(char **s, int i)
{
	while (!s[i] && i < 64)
		++i;
	return (i);
}

static char		*ft_less0(t_format *form, char **s)
{
	int		i;
	int		len;
	char	*tmp1;
	char	*tmp2;

	i = ft_find(s, 0);
	len = ft_strlen(s[i]);
	tmp2 = NULL;
	if (!(tmp1 = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	tmp1[0] = '0';
	tmp1[1] = '\0';
	form->len = 1;
	while (++i < 64)
		if (s[i])
			len += 2;
	if (len)
	{
		if (!(tmp2 = ft_sumdegree(s, 64, len, 1)))
			return (ft_frees(s, 65));
		ft_correctp(form, tmp1, tmp2, len);
	}
	return (ft_createres(form, tmp1, tmp2));
}

static char		*ft_more63(t_format *form, char **s)
{
	int		i;
	char	*tmp1;
	char	*tmp2;

	i = ft_find(s, 0);
	if (!(tmp1 = ft_sumdegree(s, 64, ft_strlen(s[i]) + 1, 0)))
		return (ft_frees(s, 65));
	i = 0;
	tmp2 = NULL;
	form->len = ft_strlen(tmp1);
	if (form->p)
	{
		if (!(tmp2 = (char *)malloc(sizeof(char) * (form->p + 1))))
			return (ft_freetmp1(tmp1));
		tmp2[form->p] = '\0';
		while (i < form->p)
			tmp2[i++] = '0';
	}
	while (tmp1[form->len - 1] == '0')
		tmp1[--form->len] = '\0';
	ft_strrev(tmp1);
	if (form->p)
		return (ft_createres(form, tmp1, tmp2));
	return (tmp1);
}

static char		*ft_0to63(t_format *form, char **s, int exp)
{
	int		i;
	int		len;
	char	*tmp1;
	char	*tmp2;

	if (!(tmp1 = ft_sumdegree(s, exp + 1, ft_strlen(s[ft_find(s, 0)]) + 1, 0)))
		return (NULL);
	form->len = ft_strlen(tmp1);
	i = ft_find(s, exp + 1);
	len = ft_strlen(s[i]);
	tmp2 = NULL;
	while (++i < 64)
		if (s[i])
			len += 2;
	if (len)
	{
		if (!(tmp2 = ft_sumdegree(&s[exp + 1], 64 - (exp + 1), len, 1)))
			return (ft_freetmp1(tmp1));
		ft_correctp(form, tmp1, tmp2, len);
	}
	while (tmp1[form->len - 1] == '0')
		tmp1[--form->len] = '\0';
	ft_strrev(tmp1);
	return (ft_createres(form, tmp1, tmp2));
}

char			*ft_formcount(t_format *form, int exp, const unsigned char *man)
{
	int		i;
	char	**s;
	char	*res;

	i = -1;
	res = NULL;
	if (!(s = (char **)malloc(sizeof(char *) * 65)))
		return (NULL);
	while (++i < 65)
		s[i] = NULL;
	while (--i >= 0)
		if (man[i] == '1')
			if (!(s[i] = ft_fastdegree(exp - i)))
				return (ft_frees(s, 65));
	if (exp >= 0 && exp <= 63)
		res = ft_0to63(form, s, exp);
	else if (exp > 63)
		res = ft_more63(form, s);
	else if (exp < 0)
		res = ft_less0(form, s);
	ft_frees(s, 65);
	return (res);
}
