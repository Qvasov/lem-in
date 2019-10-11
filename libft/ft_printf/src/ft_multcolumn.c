/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multcolumn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 20:42:26 by dbennie           #+#    #+#             */
/*   Updated: 2019/08/22 20:42:27 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_correct(char *str, int i)
{
	while (str[--i] == '0')
		str[i] -= '0';
}

static void	ft_sumover9(char *res, int *k)
{
	int		l;

	l = 0;
	res[(*k) + 1] = res[(*k) + 1] + res[*k] / 10;
	while (res[(*k) + 1 + l] > 9)
	{
		++l;
		res[(*k) + 1 + l] = res[(*k) + 1 + l] + (res[(*k) + l] / 10);
		res[(*k) + l] = res[(*k) + l] % 10;
	}
	res[*k] = res[*k] % 10;
}

static void	ft_multover9(char *a, char *b, t_colum *st)
{
	st->buf[st->i][st->j + st->i] = st->buf[st->i][st->j + st->i] \
			+ ((a[st->j] - '0') * (b[st->i] - '0'));
	if (st->buf[st->i][st->j + st->i] > 9)
		st->buf[st->i][st->j + st->i + 1] = (st->buf[st->i][st->j + st->i + 1] \
				+ st->buf[st->i][st->j + st->i]) / 10;
	st->buf[st->i][st->j + st->i] = st->buf[st->i][st->j + st->i] % 10;
}

char		*ft_sumcolumn(char **buf, int strs, int len)
{
	int		i;
	int		j;
	int		k;
	char	*res;

	if (!(res = ft_strnew(len)))
		return (ft_frees(buf, strs));
	j = -1;
	k = 0;
	while (++j < len - 1)
	{
		i = -1;
		while (++i < strs)
		{
			res[k] = res[k] + buf[i][j];
			if (res[k] > 9)
				ft_sumover9(res, &k);
		}
		res[k] = res[k] + '0';
		++k;
	}
	ft_correct(res, len - 1);
	ft_frees(buf, strs);
	return (res);
}

char		*ft_multcolumn(char *a, char *b)
{
	t_colum	st;
	int		sa;
	int		sb;

	st.i = -1;
	sa = ft_strlen(a) + 1;
	sb = ft_strlen(b) + 1;
	if (!(st.buf = (char **)malloc(sizeof(char *) * sb)))
		return (NULL);
	st.buf[sb - 1] = NULL;
	while (++st.i < sb - 1)
	{
		if (!(st.buf[st.i] = ft_strnew(sa + sb - 1)))
			return (ft_frees(st.buf, st.i));
		st.j = -1;
		while (++st.j < sa - 1)
			ft_multover9(a, b, &st);
	}
	free(a);
	return (ft_sumcolumn(st.buf, sb - 1, sa + sb));
}
