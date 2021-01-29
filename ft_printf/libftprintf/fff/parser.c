/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtahm <wtahm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 15:53:01 by wtahm             #+#    #+#             */
/*   Updated: 2021/01/27 08:01:27 by wtahm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	init_flags(t_flags *fs)
{
	fs->type = 0;
	fs->width = 0;
	fs->minus = 0;
	fs->zero = 0;
	fs->precision = -1;
	fs->star = 0;
}

int		ft_istype(char c)
{
	return (c == '%' || c == 'd' || c == 'i' || c == 'u' || c == 'c' ||
			c == 's' || c == 'p' || c == 'x' || c == 'X');
}

int		process_type(t_flags *fs, va_list args)
{
	if (fs->type == 'c')
		return (process_char(fs, va_arg(args, int)));
	else if (fs->type == 's')
		return (process_string(fs, va_arg(args, const char *)));
	else if (fs->type == 'p')
		return (process_pointer(fs, va_arg(args, unsigned long)));
	else if (fs->type == 'd' || fs->type == 'i')
		return (process_int(fs, va_arg(args, int)));
	else if (fs->type == 'u')
		return (process_uint(fs, va_arg(args, unsigned int)));
	else if (fs->type == 'x')
		return (process_hex(fs, va_arg(args, unsigned int), 0));
	else if (fs->type == 'X')
		return (process_hex(fs, va_arg(args, unsigned int), 1));
	else if (fs->type == '%')
		return (process_percent(fs));
	return (0);
}

int		parse_flag(t_flags *fs, int i, const char *f, va_list args)
{
	while (f[++i])
	{
		if (!(ft_isdigit(f[i]) || ft_istype(f[i]) || ft_isflag(f[i])))
			return (-1);
		if (f[i] == '0' && fs->precision == -1 && !fs->width)
			fs->zero = 1;
		else if (f[i] == '.')
			i = flag_dot(fs, f, i, args);
		else if (f[i] == '-')
			flag_minus(fs);
		else if (f[i] == '*')
			flag_width(fs, args);
		else if (ft_isdigit(f[i]))
			flag_digit(fs, f[i]);
		else if (ft_istype(f[i]))
		{
			fs->type = f[i];
			break ;
		}
	}
	return (i);
}

int		process_input(const char *f, va_list args)
{
	t_flags	fs;
	int		length;
	int		i;

	length = 0;
	i = 0;
	while (1)
	{
		if (!f[i])
			return (length);
		init_flags(&fs);
		if (f[i] == '%')
		{
			i = parse_flag(&fs, i, f, args);
			if (!f[i] && !fs.type)
				return (-1);
		}
		if (fs.type)
			length += process_type(&fs, args);
		else
			length += ft_putchar_fd(f[i], 1);
		i++;
	}
}
