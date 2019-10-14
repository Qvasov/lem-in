/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 22:31:10 by dbennie           #+#    #+#             */
/*   Updated: 2019/10/11 22:31:11 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"
# include <stdio.h>

# define BUFF_SIZE 1023

typedef struct 		s_link
{
	char 			*name;
	struct s_link	*next;
	struct s_link	*prev;
}					t_link;

typedef struct		s_room
{
	char 			*name;
	size_t			x;
	size_t			y;
	t_link			*links;
	struct s_room	*next;
}					t_room;

typedef struct		s_data
{
	size_t			ants;
//	t_room			**farm;
	t_room			*start;
	t_room			*end;
	int 			start_define;
	int 			end_define;
	int 			ants_define;
	int 			rooms_define;
	int 			links_define;
}					t_data;

int					ft_input(char **line);
int					ft_parse(t_data *data);
int					ft_valid(t_data *data, char *line);
void				ft_ants(t_data *data);
void				ft_farm(t_data *data);

#endif
