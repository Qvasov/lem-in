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

static void	set_err_status(char *err)
{
	ft_strcpy(err, "no links");
	ft_strcpy(err + 20, "no links");
	return ;
}

void	ft_error(int id)
{
	char err_status[5][20];

	set_err_status(&err_status[0][0]);
	//
	write (1, "ERROR", 5);
	exit(1);
}

void ft_perror()
{
	perror("lem-in: ");
	exit (1);
}
