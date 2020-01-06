/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:44:00 by dbennie           #+#    #+#             */
/*   Updated: 2019/10/18 17:44:01 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_error(int id)
{
	write (1, "ERROR", 5);
	exit(id);
}

void	ft_perror()
{
	perror("lem-in:");
	exit(1);
}
