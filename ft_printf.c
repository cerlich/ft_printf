/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerlich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 20:20:57 by cerlich           #+#    #+#             */
/*   Updated: 2020/12/10 19:02:23 by cerlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void		initial(t_param *p)
{
	p->minus = 0;
	p->type = 0;
	p->width = 0;
	p->space = 0;
	p->dot = 0;
	p->zero_flag = 0;
	p->zero_fill = 0;
	p->precision = 0;
	p->percent = 0;
	p->d = 0;
	p->u = 0;
	p->s = NULL;
	p->tmp = NULL;
}

int			parse_format(const char *fmt, int i, t_param *p)
{
	initial(p);
	if (fmt[i] == '-' || fmt[i] == '0')
		i = handl_flags(fmt, i, p);
	if (ft_isdigit(fmt, i) || fmt[i] == '*')
		i = handl_width(fmt, i, p);
	if (fmt[i] == '.')
	{
		if ((ft_isdigit(fmt, i + 1) || fmt[i + 1] == '*'))
		{
			i = handl_precision(fmt, ++i, p);
			i++;
		}
		else
			i++;
		p->dot = 1;
	}
	if (ft_isalpha(fmt, i) || fmt[i] == '%')
	{
		p->type = fmt[i];
		handl_type(p);
	}
	return (i);
}

int			parse_str(const char *fmt, int i, t_param *p)
{
	p->len = 0;
	p->tmp = NULL;
	while (fmt[i] != '\0')
	{
		while (fmt[i] == '%')
		{
			i = parse_format(fmt, i + 1, p);
			if (fmt[i] == '\0')
				break ;
			if (p->tmp)
				free(p->tmp);
			i++;
		}
		if (fmt[i] == '\0')
			break ;
		write(1, &fmt[i], 1);
		i++;
		p->len += 1;
	}
	return (p->len);
}

int			ft_printf(const char *fmt, ...)
{
	int		i;
	t_param p;

	va_start(p.ap, fmt);
	i = parse_str(fmt, 0, &p);
	va_end(p.ap);
	return (i);
}
