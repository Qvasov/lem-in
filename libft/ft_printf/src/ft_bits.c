/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 20:45:50 by dbennie           #+#    #+#             */
/*   Updated: 2019/08/22 20:45:51 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_bits(unsigned char octet, unsigned char *str)
{
	int oct;
	int div;
	int j;

	j = 0;
	div = 128;
	oct = octet;
	while (div != 0 && j < 8)
	{
		if (div <= oct)
		{
			str[j++] = '1';
			oct = oct % div;
		}
		else
			str[j++] = '0';
		div = div / 2;
	}
}
