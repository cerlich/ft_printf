/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerlich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 20:24:37 by cerlich           #+#    #+#             */
/*   Updated: 2020/12/10 18:57:03 by cerlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct			s_param
{
	va_list				ap;
	int					minus;
	int					zero_flag;
	int					zero_fill;
	int					dot;
	int					space;
	char				type;
	int					width;
	int					precision;
	int					percent;
	int					len;
	int					d;
	char				c;
	char				*s;
	char				*tmp;
	unsigned long long	u;
}						t_param;

int						ft_printf(const char *fmt, ...);
int						parse_str(const char *fmt, int i, t_param *p);
int						parse_format(const char *fmt, int i, t_param *p);
int						handl_flags(const char *fmt, int i, t_param *p);
int						handl_width(const char *fmt, int i, t_param *p);
int						handl_precision(const char *fmt, int i, t_param *p);
int						handl_type(t_param *p);
int						handl_flags2(t_param *p);
void					initial(t_param *p);
void					processing(t_param *p, char *str);
void					print_int(t_param *p);
void					print_char(t_param *p);
void					print_str(t_param *p);
void					print_unsigned_int(t_param *p);
void					print_hex(t_param *p);
char					*hex_convert(unsigned long long n, int x);
void					print_pointer(t_param *p);
void					print_percent(t_param *p);

#endif
