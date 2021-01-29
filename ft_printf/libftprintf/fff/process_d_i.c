/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_d_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtahm <wtahm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 09:20:12 by wtahm             #+#    #+#             */
/*   Updated: 2021/01/26 11:50:18 by wtahm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	process_int_positive(t_flags *fs, int count, int precision, char *s)
{
	if (fs->minus)
		return (ft_print_zeros(precision) + ft_putstr_fd(s, 1) +
				ft_print_spaces(fs->width - precision - count));
	else if (fs->zero && fs->precision == -1)
		return (ft_print_zeros(fs->width - count) + ft_putstr_fd(s, 1));
	else
		return (ft_print_spaces(fs->width - precision - count) +
				ft_print_zeros(precision) + ft_putstr_fd(s, 1));
}

int	process_int_negative(t_flags *fs, int count, int precision, char *s)
{
	if (fs->minus)
		return (ft_putchar_fd('-', 1) + ft_print_zeros(precision) +
				ft_putstr_fd(s + 1, 1) +
				ft_print_spaces(fs->width - precision - count));
	else if (fs->zero && fs->precision == -1)
		return (ft_putchar_fd('-', 1) + ft_print_zeros(fs->width - count)
				+ ft_putstr_fd(s + 1, 1));
	else
		return (ft_print_spaces(fs->width - precision - count) +
				ft_putchar_fd('-', 1) + ft_print_zeros(precision) +
				ft_putstr_fd(s + 1, 1));
}

int	process_int(t_flags *fs, int i)
{
	int		length;
	int		count;
	int		precision;
	char	*s;

	if (i == 0 && fs->precision == 0)
		return (ft_print_spaces(fs->width));
	s = ft_itoa(i);
	if (!s)
		return (0);
	count = ft_strlen(s);
	if (i >= 0)
		precision = fs->precision - count > 0 ? fs->precision - count : 0;
	else
		precision = fs->precision - count + 1 > 0
						? fs->precision - count + 1
						: 0;
	length = i >= 0 ? process_int_positive(fs, count, precision, s)
					: process_int_negative(fs, count, precision, s);
	free(s);
	return (length);
}
