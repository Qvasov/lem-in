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
	size_t 			i;
	int				space;
}					t_buf;

typedef struct		s_flags
{
	char			*fd_path;
	char			ways;
}					t_flags;

typedef struct		s_path
{
	struct s_room	*room;
	struct s_path	*next;
	struct s_path	*prev;
}					t_path; //список комнат

typedef struct		s_way
{
	struct s_path	*path;
	int				path_number;
	int				path_cost;
	int				ants;
	struct s_way	*next;
	struct s_way	*prev;
}					t_way; 	//список путей (из комнат)

typedef struct		s_var
{
	t_way 			*ways;
	int				steps;
	struct s_var 	*next;
}					t_var;

typedef struct		s_link
{
	int				cost;
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
	int				x;
	int				y;
	t_link			*links;
	struct s_room	*room_out;
	struct s_room	*room_in;
	struct s_room	*room_parrent; //
	int				ant;
	int				cost;
	struct s_room	*next;
}					t_room;

typedef struct		s_data
{
	int				ants;
	t_room			*start;
	t_room			*end;
	t_room			*rooms;
	int				rooms_count;
	t_var			*vars;
	t_var			*best_var;
	t_way			*ways_dij; //все пути которые находил алгоритм дейкстры
	int				ways_count;
	int				i_ants;//index where ants saved
	int				i_rooms_start;//index where rooms begin
	int				i_rooms_end;//index where roms end
	int				i_links_start;//index where links begin
	int				i_links_end;//index where links end
	int				i_start;//index of room start
	int				i_end;//index of room end
	t_flags			flags;
}					t_data;

void				ft_flags_lemin(t_flags *flags, int ac, char **av);
char				*ft_lemin_read(t_flags *flags, char ***str_split);
int					ft_valid(t_data *data, char **strings);
int					ft_valid_hash(char *str, int *flag);
int					ft_valid_ants(char *str, int *f, t_data *data, int j);
int					ft_valid_rooms(char *str, int *f, t_data *data, int j);
void				ft_valid_links(char *str, int *f, t_data *data, int j);
int					ft_valid_duplicates_rooms(t_data *data, char **strings);
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
int	ft_ford(t_data *data);
void				ft_direction(t_path *path);
void				ft_turn(t_link **head, t_link **tail, t_link **end,
																t_data *data);
void				ft_turn_null(t_link *turn_tail);
t_way				*ft_paths_ascending(t_room *start, t_room *end);
t_way				*ft_ways_ascending(t_link *turn_head, t_link *turn_tail,
												t_room *start, t_room *end);
void				ft_lemin(t_data *data);
void				ft_free_str_split(char ***str_split);
void				ft_free_data(t_data *data);
void				ft_error(int id);
void				ft_perror();

#endif
