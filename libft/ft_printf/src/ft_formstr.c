/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 20:43:48 by dbennie           #+#    #+#             */
/*   Updated: 2019/08/22 20:43:50 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_float(t_format *form, va_list **ap)
{
	int		mod;

	mod = ft_correctmod(form);
	if (mod == 8)
		ft_formstr_f(form, va_arg(**ap, long double));
	else
		ft_formstr_f(form, va_arg(**ap, double));
}

void		ft_formstr(t_format *form, va_list *ap)
{
	if (form->type == '\0')
		return ;
	else if (form->type == 'c')
		ft_formstr_c(form, va_arg(*ap, int));
	else if (form->type == 's')
		ft_formstr_s(form, va_arg(*ap, char *));
	else if (form->type == 'p')
		ft_formstr_p(form, va_arg(*ap, void *));
	else if (form->type == 'd' || form->type == 'i')
		ft_formstr_di(form, va_arg(*ap, unsigned long long int));
	else if (form->type == 'o')
		ft_formstr_o(form, va_arg(*ap, unsigned long long int));
	else if (form->type == 'u' || form->type == 'U')
		ft_formstr_u(form, va_arg(*ap, unsigned long long int));
	else if (form->type == 'x' || form->type == 'X')
		ft_formstr_x(form, va_arg(*ap, unsigned long long int));
	else if (form->type == 'b')
		ft_formstr_b(form, va_arg(*ap, unsigned long long int));
	else if (form->type == 'f')
		ft_float(form, &ap);
	else if (form->type == '%')
		ft_formstr_perc(form);
	else
		ft_formstr_notype(form);
}
