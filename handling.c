/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerlich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 20:20:20 by cerlich           #+#    #+#             */
/*   Updated: 2020/12/10 19:05:59 by cerlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		handl_flags(const char *fmt, int i, t_param *p)
{
	while (fmt[i] == '-' || fmt[i] == '0')
	{
		if (fmt[i] == '-')
			p->minus = 1;
		if (fmt[i] == '0')
			p->zero_flag = 1;
		i++;
	}
	return (i);
}

int		handl_width(const char *fmt, int i, t_param *p)
{
	int w;

	if (fmt[i] == '*')
	{
		w = va_arg(p->ap, int);
		p->width = w;
	}
	if (ft_isdigit(fmt, i))
		p->width = ft_atoi(&fmt[i]);
	while (ft_isdigit(fmt, i) || fmt[i] == '*')
		i++;
	return (i);
}

int		handl_precision(const char *fmt, int i, t_param *p)
{
	int pr;

	if (fmt[i] == '*')
	{
		pr = va_arg(p->ap, int);
		p->precision = pr;
	}
	if (ft_isdigit(fmt, i))
		p->precision = ft_atoi(&fmt[i]);
	while (ft_isdigit(fmt, i + 1))
		i++;
	return (i);
}

int		handl_flags2(t_param *p)
{
	if (p->width < 0)
	{
		p->minus = 1;
		p->width *= -1;
	}
	if (p->minus == 1)
		p->zero_flag = 0;
	if (p->precision > 0 && (p->type == 'd' || p->type == 'i' ||
	p->type == 'u' || p->type == 'x' || p->type == 'X'))
		p->zero_flag = 0;
	return (0);
}

int		handl_type(t_param *p)
{
	handl_flags2(p);
	if (p->type == 'd' || p->type == 'i')
		print_int(p);
	if (p->type == 'c')
		print_char(p);
	if (p->type == 's')
		print_str(p);
	if (p->type == 'u')
		print_unsigned_int(p);
	if (p->type == 'x' || p->type == 'X')
		print_hex(p);
	if (p->type == 'p')
		print_pointer(p);
	if (p->type == '%')
		print_percent(p);
	return (0);
}
