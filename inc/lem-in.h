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

typedef struct 		s_link
{
	struct s_room	*room;
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
	struct s_room	*prev;
}					t_room;

typedef struct		s_line
{
	char			*name1;
	char			*name2;
	t_room			*room1;
	t_room			*room2;
	size_t			len;
	size_t			dash;
}					t_line;

typedef struct		s_data
{
	size_t			ants;
	t_room			**farm;
	size_t			rooms_count;
	t_room			*rooms;
	t_room			*start;
	t_room			*end;
	int 			start_define;
	int 			end_define;
	int 			ants_define;
	int 			rooms_define;
	int 			links_define;
	size_t			dash;
}					t_data;

int					ft_input(char **line);
int					ft_parse(t_data *data);
int					ft_read(int fd, char **line);
int					ft_valid(t_data *data, char *line);
void				ft_ants(t_data *data, char *line);
void				ft_roomslist(t_data *data, char *line);
void				ft_links(t_data *data, char *line);
int					ft_names(t_line *names, char *line);
int					ft_findrooms(t_data *data, t_line *names);
void				ft_farm(t_data *data, char *line);
void				ft_free_data(t_data *data);
void				ft_free_names(t_line *names);
void				ft_free_links(t_link *links);
int					ft_error(t_data *data, char *line);

#endif
