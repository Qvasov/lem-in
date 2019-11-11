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

# define ANTS	flag[0]
# define ROOMS	flag[1]
# define LINKS	flag[2]
# define START	flag[3]
# define END	flag[4]
# define SE		flag[5]

typedef struct 		s_way
{
	struct s_room	*room;
	struct s_way	*next;
}					t_way;

typedef struct 		s_link
{
	struct s_room	*room;
	struct s_link	*next;
	struct s_link	*prev;
	struct s_link	*turn_next;
	struct s_link	*parrent;
}					t_link;

typedef struct		s_room
{
	char 			*name;
	size_t			x;
	size_t			y;
	t_link			*links;
	struct s_room	*next;
	struct s_room	*prev;
	int				turn_is;
}					t_room;

typedef struct		s_data
{
	size_t			ants;
	t_room			*start;
	t_room			*end;
	t_room			*rooms;
	size_t			rooms_count;

	t_way			*ways;

	long			i_ants;
	long			i_rooms_start;
	long			i_rooms_end;
	long			i_links_start;
	long			i_links_end;
	long			i_start;
	long			i_end;
}					t_data;

int					ft_read(int fd, char ***data);
int					ft_valid(t_data *data, char **strings);
int					ft_parse(t_data *data, char **str_split);
int					ft_ants(t_data *data, char **strings);
int					ft_roomslist(t_data *data, char *str);
int					ft_links(t_data *data, char *str);
int					ft_findrooms(t_data *data, char *link, t_room **room1, t_room **room2);
t_way				*ft_bfs(t_data* data);

void				ft_free_str_split(char **str_split);
void				ft_free_data(t_data *data);
void				ft_free_links(t_link *links);
int					ft_error(t_data *data, char **str_split);

#endif
