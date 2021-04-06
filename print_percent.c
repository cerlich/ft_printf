/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerlich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 19:11:36 by cerlich           #+#    #+#             */
/*   Updated: 2020/12/10 19:49:59 by cerlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void		handl_percent(t_param *p)
{
	if (p->zero_flag == 0)
	{
		p->space = p->width - 1;
		p->zero_fill = p->precision - 1;
		if (p->precision > 1)
			p->space = p->width - p->precision;
	}
	if (p->zero_flag == 1)
		p->zero_fill = p->width - 1;
}

void			print_percent(t_param *p)
{
	handl_percent(p);
	while (p->minus == 0 && p->space > 0 && p->space--)
	{
		write(1, " ", 1);
		p->len++;
	}
	while (p->zero_fill > 0 && p->zero_fill--)
	{
		write(1, "0", 1);
		p->len++;
	}
	write(1, "%", 1);
	p->len++;
	while (p->minus == 1 && p->space > 0 && p->space--)
	{
		write(1, " ", 1);
		p->len++;
	}
}
