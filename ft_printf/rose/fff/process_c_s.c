/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_c_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtahm <wtahm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 09:20:12 by wtahm             #+#    #+#             */
/*   Updated: 2021/01/27 08:03:17 by wtahm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_spaces(int count)
{
	int i;

	i = 0;
	if (count <= 0)
		return (0);
	while (i < count)
	{
		ft_putchar_fd(' ', 1);
		i++;
	}
	return (count);
}

int	process_char(t_flags *fs, char c)
{
	if (fs->minus)
		return (ft_putchar_fd(c, 1) + ft_print_spaces(fs->width - 1));
	return (ft_print_spaces(fs->width - 1) + ft_putchar_fd(c, 1));
}

int	process_percent(t_flags *fs)
{
	int length;

	length = 0;
	if (!fs->minus)
	{
		if (fs->zero)
			length += ft_print_zeros(fs->width - 1);
		else
			length += ft_print_spaces(fs->width - 1);
	}
	length += ft_putchar_fd('%', 1);
	if (fs->minus)
		length += ft_print_spaces(fs->width - 1);
	return (length);
}

int	ft_print_str(const char *s, int count)
{
	int i;

	if (count <= 0)
		return (0);
	i = 0;
	while (i < count)
	{
		ft_putchar_fd(s[i], 1);
		i++;
	}
	return (count);
}

int	process_string(t_flags *fs, const char *s)
{
	int length;
	int chars_to_print;

	length = 0;
	if (!s)
		s = "(null)";
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
