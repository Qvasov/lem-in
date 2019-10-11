/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fastdegree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 20:44:25 by dbennie           #+#    #+#             */
/*   Updated: 2019/08/22 20:44:27 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_negative(char *res, int degree)
{
	char	*tmp;
	int		i;
	int		j;

	if (!(tmp = ft_strnew(degree)))
		return (ft_freetmp1(tmp));
	i = degree;
	j = ft_strlen(res);
	while (--i >= j)
		tmp[degree - i - 1] = '0';
	while (i >= 0)
	{
		tmp[degree - i - 1] = res[i];
		i--;
	}
	free(res);
	return (tmp);
}

static char	*ft_create(const unsigned char *bin_deg, char *res, int degree,
																	int neg)
{
	int		i;
	char	*b;

	if (neg < 0)
		b = "5";
	else
		b = "2";
	i = 0;
	while (bin_deg[i] != '1')
		++i;
	while (i < 16)
	{
		if (bin_deg[i++] == '1')
			res = ft_multcolumn(ft_multcolumn(res, res), b);
		else
			res = ft_multcolumn(res, res);
		if (res == NULL)
			return (NULL);
	}
	if (neg < 0)
		res = ft_negative(res, degree);
	return (res);
}

char		*ft_fastdegree(int degree)
{
	union u_binary	deg;
	unsigned char	bin_deg[16];
	int				i;
	int				j;
	char			*res;

	if (!(res = ft_strnew(1)))
		return (NULL);
	res[0] = '1';
	res[1] = '\0';
	deg.i = degree;
	i = 2;
	j = -8;
	if (degree < 0)
		deg.i = (deg.i ^ 0xffffffff) + 1;
	while (--i > -1)
		ft_bits(deg.byte[i], &bin_deg[j += 8]);
	return (ft_create(bin_deg, res, deg.i, degree));
}
