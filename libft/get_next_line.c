/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 20:23:30 by dbennie           #+#    #+#             */
/*   Updated: 2019/05/20 14:25:10 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_line(char **r, const int fd, char **line)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (r[fd][i] != '\0' && r[fd][i] != '\n')
		i++;
	*line = ft_strsub(r[fd], 0, i);
	if (r[fd][i] == '\n')
	{
		if (!(tmp = ft_strdup(r[fd] + i + 1)))
			return (-1);
		free(r[fd]);
		r[fd] = tmp;
		if (r[fd][0] == '\0')
			ft_strdel(&r[fd]);
	}
	else if (r[fd][i] == '\0')
		ft_strdel(&r[fd]);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	int			ret;
	char		*buf;
	static char	*r[10241];
	char		*tmp;

	if (fd < 0 || line == NULL || BUFF_SIZE == 0 \
			|| !(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!r[fd])
			r[fd] = ft_strnew(0);
		tmp = ft_strjoin(r[fd], buf);
		free(r[fd]);
		r[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	if (ret == 0 && (!r[fd] || r[fd][0] == '\0'))
		return (0);
	free(buf);
	return (ft_line(r, fd, line));
}
