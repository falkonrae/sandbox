/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacob <vjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 15:53:01 by wtahm             #+#    #+#             */
/*   Updated: 2021/01/22 13:48:54 by vjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
// #include <stdio.h>

#include "libft/libft.h"
//#include "ft_printf.h"

void	init_flags(t_flags *fs)
{
	fs->type = 0;
	fs->width = 0;
	fs->minus = 0;
	fs->zero = 0;
	fs->precision = -1;
	fs->star = 0;
}

int		flag_dot(t_flags *fs, const char *f, int i, va_list args)
{
	fs->precision = 0;
	i++;
	if (f[i] == '*') // именно * - она задает необязательные аргументы, которые считывает va_arg
	{
		fs->precision = va_arg(args, int);
		i++;
	}
	else
	{
		while (ft_isdigit(f[i]))
		{
			fs->precision = fs->precision * 10 + (f[i] - '0'); //точность берется благодаря конвертации из строки в число
			i++;
		}
	}
	return (i - 1);
}

void	flag_minus(t_flags *fs)
{
	fs->minus = 1;
	fs->zero = 0;
}

void	flag_width(t_flags *fs, va_list args)
{
	fs->star = 1;
	fs->width = va_arg(args, int);
	if (fs->width < 0)
	{
		fs->minus = 1;
		fs->width = fs->width * (-1);
		fs->zero = 0;
	}
}

void	flag_digit(t_flags *fs, char c)
{
	if (fs->star == 1)
		fs->width = 0;
	else
		fs->width = fs->width * 10 + (c - '0');
}

int		ft_istype(char c)
{
	return (c == '%' || c == 'd' || c == 'i' || c == 'u' || c == 'c'
	|| c == 's' || c == 'p' || c == 'x' || c == 'X');
}

int		ft_isflag(char c)
{
	return (c == '.' || c == '-' || c == '*');
}

int		process_char(t_flags *fs, char c)
{
	int length;

	length = 1;
	if (fs->minus)
		ft_putchar_fd(c, 0);
	while (length < fs->width)
	{
		ft_putchar_fd(' ', 0);
		length++;
	}
	if (!fs->minus)
		ft_putchar_fd(c, 0);
	return (length);
}

int		ft_print_spaces(int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		ft_putchar_fd(' ', 0);
		i++;
	}
	return (count);
}

int		ft_print_str(char *s, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		ft_putchar_fd(s[i], 0);
		i++;
	}
	return (count);
}

int		process_string(t_flags *fs, char *s)
{
	int length;
	int chars_to_print;

	length = 0;
	chars_to_print = ft_strlen(s);
	if (fs->precision >= 0 && fs->precision < chars_to_print)
		chars_to_print = fs->precision;
	if (!fs->minus)
		length += ft_print_spaces(fs->width - chars_to_print);
	length += ft_print_str(s, chars_to_print);
	if (fs->minus)
		length += ft_print_spaces(fs->width - chars_to_print);
	return (length);
}

// int		put_ox_str(char* string)
// {
// 	char*	zero_x;
// 	int i;

// 	i = 0;
// 	zero_x = "0x";
// 	if (string)
// 	{
// 		if (string[i] == '#')
// 			ft_putstr_fd(zero_x, 0);
// 		ft_putstr_fd(string + 1, 0);
// 		i++;
// 	}
// 	return (i);
// }

// int process_pointer(t_flags *fs, unsigned long p)
// {
//     char* str;
// 	int length;
// 	int i;
// 	unsigned long poi;
	
//     length = 0;
// 	i = 0;
// 	poi = 0;
// 	if (p == '0' && !fs->precision)
// 		if (!p)
// 		{
// 			while (p)
// 			{
// 				poi = p/16 + i;
// 				str = (char*)malloc((i + 1) * sizeof(char));
// 				str[i] = '\0';

// 				while (p != '\0')
// 				{
// 					if (poi < 10)
// 						str[i] = p % 16 + 48;
// 					else (str[i] = p % 16 + 87);
// 				}
// 				p = p / 16;
// 				i--;
// 			}
// 			put_ox_str(str);
// 		}
// 	ft_putstr_fd(str, 0);
//     return (length);
// }

// int		process_int(t_flags *fs, int i)
// {
// 	int		length;
// 	char	*str;
// 	int		digits_to_print;

// 	length = 0;
// 	digits_to_print = i;
// 	if (i != 0 && !fs->precision)
// 	{
// 		if (i < 0 && ((fs->precision < 0) || (fs->zero == 1)))
// 			ft_putstr_fd(str, 0);
// 		if (i == -2147483648)
// 			length = -1;
// 		i = 1 * (-1);
// 		fs->zero = 1;
// 		fs->width = fs->width - 1;
// 		length = length + 1;
// 		str = ft_itoa(*str);
// 		if (fs->minus == 1)
// 		{
// 			if (digits_to_print < 0 || fs->precision >= 0 || i > 2147483648)
// 				ft_putchar_fd('-', 0);
// 			if (fs->precision >= 0)
// 			{
// 				fs->precision = 1;
// 				length = -1;
// 				fs->zero = 0;
// 				ft_putstr_fd();
// 			}
// 		}
// 	}
// 	return (length);
// }

int		process_uint(t_flags *fs, unsigned int i)
{
	int length;

	length = 0;

	return (length);
}

int		process_hex(t_flags *fs, unsigned int i, int capital)
{
	int length;

	length = 0;
	// TODO
	return (length);
}

int		process_percent(t_flags *fs)
{
	int length;

	length = 0;
	// TODO
	return (length);
}

int		process_type(t_flags *fs, va_list args)
{
	int length;

	length = 0;
	if (fs->type == 'c')
		length += process_char(fs, va_arg(args, int));
	if (fs->type == 's')
		length += process_string(fs, va_arg(args, char *));
	// if (fs->type == 'p')
	//     length += process_pointer(fs, va_arg(args, unsigned long));
	// if (fs->type == 'd' || fs->type == 'i')
	//     length += process_int(fs, va_arg(args, int));
	if (fs->type == 'u')
		length += process_uint(fs, va_arg(args, unsigned int));
	if (fs->type == 'x')
		length += process_hex(fs, va_arg(args, unsigned int), 0);
	if (fs->type == 'X')
		length += process_hex(fs, va_arg(args, unsigned int), 1);
	if (fs->type == '%')
		length += process_percent(fs);
	return (length);
}

int		parse_flag(t_flags *fs, int i, const char *f, va_list args)
{
	while (f[i] && (ft_isdigit(f[i]) || ft_istype(f[i]) || ft_isflag(f[i])
	|| f[i] == ' '))
	{
		i++;
		if (f[i] == '0' && !fs->minus && !fs->precision && !fs->width)
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
		//	break ;
		}
		else 
			i++;
	}
	return (i);
}

int		process_input(const char *f, va_list args)
{
	t_flags fs;
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
			i = parse_flag(&fs, i, f, args);
		if (fs.type)
			length += process_type(&fs, args);
		else
		{
			ft_putchar_fd(f[i], 0);
			length++;
		}
		i++;
	}
}

int		ft_printf(const char *f, ...)
{
	int		length;
	va_list args;

	va_start(args, f);
	length = process_input(f, args);
	va_end(args);
	return (length);
}

int		main(void)
{
	ft_printf("ft_printf: \"|%      |\"\n", 'a');
	// printf("   printf: \"%-3.2c\"\n", 'a');
	ft_printf("ft_printf: \"%-5.3s\"\n", "abcde");
	// printf("   printf: \"%-5.3s\"\n", "abcde");
	return (0);
}
