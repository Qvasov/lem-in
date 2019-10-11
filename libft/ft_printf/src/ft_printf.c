/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 21:52:28 by dbennie           #+#    #+#             */
/*   Updated: 2019/08/26 19:07:45 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_write(t_format *form, t_buf *buf)
{
	t_list	*tmp;

	if (form->list)
		while (form->list)
		{
			write(1, form->list->content, form->list->content_size);
			tmp = form->list;
			form->list = form->list->next;
			ft_delelem(tmp);
		}
	write(1, buf->str, buf->len);
}

static void	ft_readformat(const char *format, t_format *form, va_list *ap,
																	t_buf *buf)
{
	long long j;

	j = 0;
	while (format[j] != '\0')
	{
		if (format[j] == '{' && format[j + 1])
			ft_color(buf, &format[j], &j);
		if (format[j] == '%')
		{
			++j;
			j += ft_formandout(form, &format[j], ap, buf);
		}
		else
		{
			ft_addbuf(buf, form);
			buf->str[buf->len++] = format[j++];
		}
	}
}

void		ft_zeroform(t_format *form)
{
	int i;

	i = -1;
	while (++i < 5)
		form->f[i] = '\0';
	form->w = 0;
	form->p = -1;
	form->mod[0] = '\0';
	form->mod[1] = '\0';
	form->type = '\0';
	form->neg = '\0';
	form->str = NULL;
	form->len = 0;
	form->list = NULL;
}

int			ft_printf(const char *format, ...)
{
	t_format	form;
	va_list		ap;
	t_buf		buf;

	ft_zeroform(&form);
	va_start(ap, format);
	if (!(buf.str = (char *)malloc(sizeof(char) * BUFF_SIZE)))
		exit(0);
	buf.str[BUFF_SIZE - 1] = '\0';
	buf.len = 0;
	ft_readformat(format, &form, &ap, &buf);
	va_end(ap);
	ft_write(&form, &buf);
	ft_strdel(&buf.str);
	return (buf.len);
}
