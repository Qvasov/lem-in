/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:30:08 by dbennie           #+#    #+#             */
/*   Updated: 2019/11/01 18:30:10 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	init_str(char **str)
{
	*str = (char *)malloc(1);
	**str = 0;
}

static char	**str_data_match(char *str, char c)
{
	int i;
	char **ptr;

	i = ft_strchr_count(str, c);
	i < 5 ? ft_error(1) : 1;//or 6?
	if (!(ptr = (char **)malloc(sizeof(char *) * (i + 1))))
		ft_perror();
	i = 0;
	while (*str)
	{
		ptr[i] = str;
		i++;
		while (*str != c && *str)
			str++;
		if (*str == c)
		{
			*str = 0;
			str++;
		}
		else
			*(str - 1) == 0 ? 1 : ft_error(1);

	}
	ptr[i] = NULL;
	return (ptr);
}

int	ft_lemin_read(t_flags *flags, char ***str_split)
{
	int		ret;
	char	buf[16385];
	char	*str;
	char	*trash;
	int		fd;

	fd = (flags->fd_path) ? open(flags->fd_path, O_RDONLY) : 0;
	(fd < 0) ? ft_perror() : 1;
	init_str(&str);
	while ((ret = read(fd, buf, 16384)) > 0)
	{
		buf[ret] = '\0';
		trash = str;
		if (!(str = ft_strjoin(str, buf)))
			ft_perror();
		free(trash);
	}
	(ret < 0) ? ft_perror() : 1;
	if (fd > 2)
		((close(fd)) < 0) ? ft_perror() : 1;
	*str_split = str_data_match(str, '\n');
	return (0);
}
