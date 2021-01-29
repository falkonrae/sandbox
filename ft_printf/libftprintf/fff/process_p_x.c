/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_p_x_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtahm <wtahm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 09:20:12 by wtahm             #+#    #+#             */
/*   Updated: 2021/01/27 08:02:59 by wtahm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		pointer_digits_count(unsigned long p, int base)
{
	int count;

	if (p == 0)
		return (1);
	count = 0;
	while (p)
	{
		p /= base;
		count++;
	}
	return (count);
}

int		ft_to_hex_string(unsigned long p, char **s)
{
	int		count;
	int		i;
	char	h;

	count = pointer_digits_count(p, 16);
	*s = malloc((count + 1) * sizeof(char));
	if (!*s)
		return (-1);
	(*s)[count] = '\0';
	i = count - 1;
	while (i >= 0)
	{
		h = p % 16;
		if (h < 10)
			(*s)[i] = h + 48;
		else
			(*s)[i] = h + 87;
		p /= 16;
		i--;
	}
	return (count);
}

int		ft_to_capital_hex_string(unsigned long p, char **s)
{
	int		count;
	int		i;
	char	h;

	count = pointer_digits_count(p, 16);
	*s = malloc((count + 1) * sizeof(char));
	if (!*s)
		return (-1);
	(*s)[count] = '\0';
	i = count - 1;
	while (i >= 0)
	{
		h = p % 16;
		if (h < 10)
			(*s)[i] = h + 48;
		else
			(*s)[i] = h + 55;
		p /= 16;
		i--;
	}
	return (count);
}

int		process_pointer(t_flags *fs, unsigned long p)
{
	int		length;
	int		count;
	char	*s;

	length = 0;
	if ((count = ft_to_hex_string(p, &s)) == -1)
		return (0);
	if (!fs->precision)
		count = 0;
	if (fs->minus)
		length += ft_putstr_fd("0x", 1) + ft_print_str(s, count) +
					ft_print_spaces(fs->width - count - 2);
	else if (fs->zero)
		length += ft_putstr_fd("0x", 1) + ft_print_zeros(fs->width - count - 2)
					+ ft_print_str(s, count);
	else
		length += ft_print_spaces(fs->width - count - 2) +
					ft_putstr_fd("0x", 1) + ft_print_str(s, count);
	free(s);
	return (length);
}

int		process_hex(t_flags *fs, unsigned int u, int capital)
{
	int		length;
	int		count;
	int		precision;
	char	*s;

	if (u == 0 && fs->precision == 0)
		return (ft_print_spaces(fs->width));
	length = 0;
	count = capital ? ft_to_capital_hex_string(u, &s) : ft_to_hex_string(u, &s);
	if (count == -1)
		return (0);
	precision = fs->precision - count > 0 ? fs->precision - count : 0;
	if (fs->minus)
		length += ft_print_zeros(precision) + ft_print_str(s, count) +
					ft_print_spaces(fs->width - precision - count);
	else if (fs->zero && fs->precision == -1)
		length += ft_print_zeros(fs->width - count) + ft_print_str(s, count);
	else
		length += ft_print_spaces(fs->width - precision - count) +
					ft_print_zeros(precision) + ft_print_str(s, count);
	free(s);
	return (length);
}
