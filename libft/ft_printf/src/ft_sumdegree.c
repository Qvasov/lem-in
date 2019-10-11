/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sumdegree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 20:42:15 by dbennie           #+#    #+#             */
/*   Updated: 2019/08/22 20:42:17 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_negative(struct s_temp *s)
{
	int		l;

	l = 0;
	s->t[(s->k) - 1] = s->t[(s->k) - 1] + s->t[s->k] / 10;
	while (s->t[(s->k) - 1 - l] > '9')
	{
		++l;
		s->t[(s->k) - 1 - l] = s->t[(s->k) - 1 - l] \
				+ ((s->t[(s->k) - l] - '0') / 10);
		s->t[(s->k) - l] = (s->t[(s->k) - l] - '0') % 10 + '0';
	}
	s->t[s->k] = s->t[s->k] % 10;
}

static void	ft_positive(struct s_temp *s)
{
	int		l;

	l = 0;
	s->t[(s->k) + 1] = s->t[(s->k) + 1] + s->t[s->k] / 10;
	while (s->t[(s->k) + 1 + l] > 9)
	{
		++l;
		s->t[(s->k) + 1 + l] = s->t[(s->k) + 1 + l] + (s->t[(s->k) + l] / 10);
		s->t[(s->k) + l] = s->t[(s->k) + l] % 10;
	}
	s->t[s->k] = s->t[s->k] % 10;
}

static void	ft_sumneg(char **buf, struct s_temp *s, int len, int strs)
{
	int		i;
	int		j;

	j = -1;
	while (++j < len)
	{
		i = -1;
		while (++i < strs)
			if (buf[i])
			{
				if (buf[i][j] == '\0')
				{
					free(buf[i]);
					buf[i] = NULL;
				}
				else
				{
					s->t[s->k] = s->t[s->k] + buf[i][j] - '0';
					if (s->t[s->k] > 9)
						ft_negative(s);
				}
			}
		s->t[s->k] = s->t[s->k] + '0';
		++s->k;
	}
}

static void	ft_sumpos(char **buf, struct s_temp *s, int len, int strs)
{
	int		i;
	int		j;

	j = -1;
	while (++j < len)
	{
		i = -1;
		while (++i < strs)
			if (buf[i])
			{
				if (buf[i][j] == '\0')
				{
					free(buf[i]);
					buf[i] = NULL;
				}
				else
				{
					s->t[s->k] = s->t[s->k] + buf[i][j] - '0';
					if (s->t[s->k] > 9)
						ft_positive(s);
				}
			}
		s->t[s->k] = s->t[s->k] + '0';
		++s->k;
	}
}

char		*ft_sumdegree(char **buf, int strs, size_t len, int neg)
{
	struct s_temp	s;

	if (!(s.t = ft_strnew(len)))
		return (NULL);
	s.k = 0;
	if (neg)
		ft_sumneg(buf, &s, len, strs);
	else
		ft_sumpos(buf, &s, len, strs);
	if (neg)
		while (s.t[--s.k] == '0')
			s.t[s.k] = '\0';
	return (s.t);
}
