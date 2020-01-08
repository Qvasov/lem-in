/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 22:31:10 by dbennie           #+#    #+#             */
/*   Updated: 2019/12/18 17:38:30 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"
# include <stdio.h>
# include <fcntl.h>

# define ANTS		0
# define ROOMS		1
# define LINKS		2
# define START		3
# define END		4
# define DEF_SE		5

# define BUFF_SIZE	2048

typedef struct		s_buf
{
	char			str[BUFF_SIZE];
	int				i;
	int				space;
}					t_buf;

typedef struct		s_path
{
	struct s_room	*room;
	struct s_path	*next;
	struct s_path	*prev;
}					t_path;

typedef struct		s_way
{
	struct s_path	*path;
	size_t			path_number;
	size_t			path_cost;
	struct s_way	*next;
	struct s_way	*prev;
}					t_way;

typedef struct		s_link
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
	char			*name;
	size_t			x;
	size_t			y;
	t_link			*links;
	struct s_room	*room_out;
	struct s_room	*room_in;
	size_t			ant;
	long			cost;
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
	t_way			*old_ways;
	size_t			old_steps;
	long			ways_count;
	long			i_ants;//index where ants saved
	long			i_rooms_start;//index where rooms begin
	long			i_rooms_end;//index where roms end
	long			i_links_start;//index where links begin
	long			i_links_end;//index where links end
	long			i_start;//index of room start
	long			i_end;//index of room end
}					t_data;

typedef struct		s_flags
{
	char			*fd_path;
}					t_flags;

void				ft_flags_lemin(t_flags *flags, int ac, char **av);
int					ft_lemin_read(t_flags *flags, char ***data);
int					ft_valid(t_data *data, char **strings);
int					ft_valid_hash(char *str, int *flag);
int					ft_valid_ants(char *str, int *f, t_data *data, long j);
int					ft_valid_rooms(char *str, int *f, t_data *data, long j);
void				ft_valid_links(char *str, int *f, t_data *data, long j);
int					ft_valid_duplicates_rooms(t_data *data, char **strings);

//int				ft_valid_duplicates_links(t_data *data, char **strings);

int					ft_parse_data(t_data *data, char **str_split);
void				ft_rooms(t_data *data, char *str);
t_room				*ft_createroom(char *line);
void				ft_links(t_data *data, char *str);
t_link				*ft_createlink(t_room *room);
int					ft_findrooms(t_data *data, char *link, t_room **room1,
															t_room **room2);
void				ft_ways(t_data *data);
int					ft_suurballe(t_data *data);
int					ft_dijkstra(t_data *data);
void				ft_direction(t_path *path);
void				ft_turn(t_link **head, t_link **tail, t_link **end,
																t_room *e);
void				ft_turn_null(t_link *turn_tail);
t_way				*ft_paths_ascending(t_room *start, t_room *end);
t_way				*ft_ways_ascending(t_link *turn_head, t_link *turn_tail,
												t_room *start, t_room *end);
void				ft_lem_in(t_data *data);
void				ft_copy_char(char *str, int *i, char c);
void				ft_copy_num(char *str, int *i, size_t ant);
void				ft_free_str_split(char ***str_split);
void				ft_free_data(t_data *data);
void				ft_free_links(t_link *links);
void				ft_free_way(t_way *way);
void				*ft_free_path(t_path *path);
void				ft_error(int id);
void				ft_perror();

#endif
