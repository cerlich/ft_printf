/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerlich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 19:24:08 by cerlich           #+#    #+#             */
/*   Updated: 2020/12/10 19:55:24 by cerlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void			print_char(t_param *p)
{
	p->c = (char)va_arg(p->ap, int);
	while (p->minus == 0 && p->width > 1 && p->width--)
	{
		write(1, " ", 1);
		p->len++;
	}
	write(1, &(p->c), 1);
	p->len++;
	while (p->minus == 1 && p->width > 1 && p->width--)
	{
		write(1, " ", 1);
		p->len++;
	}
}

static int		handl_len_str(t_param *p)
{
	int len;
	int len_s;

	if (p->dot == 1 && p->precision == 0)
		len = 0;
	len_s = ft_strlen(p->s);
	if (p->precision <= len_s && p->precision > 0)
		len = p->precision;
	if (p->precision > len_s ||
			(p->precision == 0 && p->dot == 0) || p->precision < 0)
		len = len_s;
	p->space = p->width - len;
	return (len);
}

void			print_str(t_param *p)
{
	int len;

	p->s = va_arg(p->ap, char *);
	if (p->s == NULL)
	{
		p->s = ft_strdup("(null)");
		p->tmp = p->s;
	}
	len = handl_len_str(p);
	while (p->minus == 0 && p->space > 0 && p->space--)
	{
		write(1, " ", 1);
		p->len++;
	}
	while (len--)
	{
		write(1, p->s, 1);
		p->s++;
		p->len++;
	}
	while (p->minus == 1 && p->space > 0 && p->space--)
	{
		write(1, " ", 1);
		p->len++;
	}
}
