/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerlich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 17:49:06 by cerlich           #+#    #+#             */
/*   Updated: 2020/12/10 19:52:25 by cerlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	print_pointer(t_param *p)
{
	p->u = va_arg(p->ap, unsigned long long);
	if (p->u == 0 && p->precision == 0 && p->dot == 1)
		p->s = ft_calloc(1, 1);
	else
		p->s = hex_convert(p->u, 'a' - 10);
	processing(p, p->s);
	p->tmp = p->s;
	while (p->minus == 0 && p->space > 0 && p->space--)
		write(1, " ", 1);
	write(1, "0x", 2);
	if (p->precision > p->width)
	{
		p->zero_fill += 2;
		p->len += 2;
	}
	while (p->zero_fill > 0 && p->zero_fill--)
		write(1, "0", 1);
	ft_putstr_fd(p->s, 1);
	while (p->minus == 1 && p->space > 0 && p->space--)
		write(1, " ", 1);
}
