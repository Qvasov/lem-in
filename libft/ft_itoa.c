/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 16:38:52 by dbennie           #+#    #+#             */
/*   Updated: 2019/04/15 16:42:21 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*r;
	int		i;

	i = ft_count(n);
	if (!(r = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	r[i--] = '\0';
	if (n == 0)
		r[i] = 48;
	if (n == -2147483648)
	{
		r[i--] = n % 10 + 64;
		n = n / 10;
	}
	if (n < 0)
	{
		r[0] = '-';
		n *= -1;
	}
	while (n)
	{
		r[i--] = n % 10 + 48;
		n = n / 10;
	}
	return (r);
}
