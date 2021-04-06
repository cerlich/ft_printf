/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerlich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 19:23:07 by cerlich           #+#    #+#             */
/*   Updated: 2020/12/10 22:42:01 by cerlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void		len_format(t_param *p, int len)
{
	if ((p->type == 'd' || p->type == 'i' || p->type == 'x' ||
	p->type == 'X' || p->type == 'u') && p->precision == 0 && p->dot == 1)
	{
		p->space = p->width - len;
		p->zero_fill = 0;
	}
	if (p->zero_fill < 0)
		p->zero_fill = 0;
	if (p->space < 0)
		p->space = 0;
	p->len = p->len + p->zero_fill + p->space + len;
}

void			processing(t_param *p, char *str)
{
	int len;

	len = ft_strlen(str);
	if (p->type == 'p')
		len += 2;
	if (p->zero_flag == 0)
	{
		p->space = p->width - len;
		p->zero_fill = p->precision - len;
		if (p->precision > len)
			p->space = p->width - p->precision;
		if (p->d < 0)
		{
			p->zero_fill = p->precision - len + 1;
			if (p->zero_fill < 0)
				p->zero_fill = 0;
			p->space = p->width - p->zero_fill - len;
		}
	}
	if (p->zero_flag == 1)
		p->zero_fill = p->width - len;
	len_format(p, len);
}

void			print_int(t_param *p)
{
	p->d = va_arg(p->ap, int);
	if (!(p->d == 0 && p->precision == 0 && p->dot == 1))
		p->s = ft_itoa(p->d);
	else
		p->s = ft_calloc(1, 1);
	processing(p, p->s);
	p->tmp = p->s;
	while (p->minus == 0 && p->space > 0 && p->space--)
		write(1, " ", 1);
	if (p->zero_fill > 0 && p->d < 0)
	{
		write(1, "-", 1);
		p->s++;
	}
	while (p->zero_fill > 0 && p->zero_fill--)
		write(1, "0", 1);
	ft_putstr_fd(p->s, 1);
	while (p->minus == 1 && p->space > 0 && p->space--)
		write(1, " ", 1);
}

void			print_unsigned_int(t_param *p)
{
	p->u = va_arg(p->ap, unsigned int);
	if (!(p->u == 0 && p->precision == 0 && p->dot == 1))
		p->s = ft_itoa(p->u);
	else
		p->s = ft_calloc(1, 1);
	processing(p, p->s);
	p->tmp = p->s;
	while (p->minus == 0 && p->space > 0 && p->space--)
		write(1, " ", 1);
	while (p->zero_fill > 0 && p->zero_fill--)
		write(1, "0", 1);
	ft_putstr_fd(p->s, 1);
	while (p->minus == 1 && p->space > 0 && p->space--)
		write(1, " ", 1);
}
