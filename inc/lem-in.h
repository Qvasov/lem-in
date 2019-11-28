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

typedef struct 		s_path
{
	struct s_room	*room;
	struct s_path	*next;
	struct s_path	*prev;
}					t_path;

typedef struct 		s_way
{
	struct s_path	*path;
	size_t			path_number;
	size_t			path_cost;
	struct s_way	*next;
	struct s_way	*prev;
}					t_way;

typedef struct 		s_link
{
	long			cost;
	struct s_room	*room_src;
	struct s_room	*room;
	struct s_link	*next;
	struct s_link	*prev;
	struct s_link	*turn_next;
	struct s_link	*turn_prev;
	struct s_link	*parrent;
	int				turn_in;
}					t_link;

typedef struct		s_room
{
	char 			*name;
	size_t			x;
	size_t			y;
	t_link			*links;
	struct s_room	*room_out;
	struct s_room	*room_in;
	size_t			ant;
	long 			cost;
	struct s_room	*next;
}					t_room;

typedef struct		s_data
{
	size_t			ants;
	t_room			*start;
	t_room			*end;
	t_room			*rooms;
	size_t			rooms_count;
	t_way			*ways;
	t_way			*mod_ways;
	size_t			steps;
	long			ways_count;
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
int					ft_rooms(t_data *data, char *str);
t_room				*ft_createroom(char *line);
int					ft_links(t_data *data, char *str);
t_link				*ft_createlink(t_room *room);
int					ft_findrooms(t_data *data, char *link, t_room **room1, t_room **room2);
int					ft_ways(t_data *data);
int					ft_suurballe(t_data *data);
int					ft_dijkstra(t_data* data);
void				ft_turn(t_link **head, t_link **tail, t_link **end, t_room *e);
void				ft_turn_null(t_link *turn_tail);
t_way				*ft_paths_ascending(t_room *start, t_room *end);

void				ft_lem_in(t_way *ways, size_t steps, t_room *start, t_room *end);

void				ft_free_str_split(char **str_split);
void				ft_free_data(t_data *data);
void				ft_free_links(t_link *links);
void				ft_free_way(t_way *way);
int					ft_free_path(t_path *path);
int					ft_error(t_data *data, char **str_split);

#endif
