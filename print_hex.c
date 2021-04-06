/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerlich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 16:31:08 by cerlich           #+#    #+#             */
/*   Updated: 2020/12/10 19:49:12 by cerlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int		hex_len(unsigned long long n)
{
	int i;

	i = 0;
	while (n >= 16)
	{
		n = n / 16;
		i++;
	}
	i++;
	return (i);
}

static char		*reverse(char *s)
{
	int i;
	int j;
	int c;

	i = 0;
	j = ft_strlen(s) - 1;
	while (i < j)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		i++;
		j--;
	}
	return (s);
}

char			*hex_convert(unsigned long long n, int x)
{
	int				i;
	int				j;
	long long		s;
	char			*p;

	j = 0;
	s = n;
	i = hex_len(n);
	if (!(p = (char *)ft_calloc(i + 1, 1)))
		return (0);
	while (i--)
	{
		if (n % 16 < 10)
			p[j++] = n % 16 + 48;
		if ((n % 16) > 9 && (n % 16) < 16)
			p[j++] = n % 16 + x;
		n = n / 16;
	}
	return (reverse(p));
}

void			print_hex(t_param *p)
{
	p->u = va_arg(p->ap, unsigned int);
	if (!(p->u == 0 && p->precision == 0 && p->dot == 1))
	{
		if (p->type == 'x')
			p->s = hex_convert(p->u, 'a' - 10);
		if (p->type == 'X')
			p->s = hex_convert(p->u, 'A' - 10);
	}
	else
		p->s = ft_calloc(1, 1);
	p->tmp = p->s;
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
