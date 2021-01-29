/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_d_i_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtahm <wtahm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 09:20:12 by wtahm             #+#    #+#             */
/*   Updated: 2021/01/26 11:42:06 by wtahm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_zeros(int count)
{
	int i;

	if (count <= 0)
		return (0);
	i = 0;
	while (i < count)
	{
		ft_putchar_fd('0', 1);
		i++;
	}
	return (count);
}

int	process_uint2(t_flags *fs, int count, int precision, char *s)
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

int	process_uint(t_flags *fs, unsigned int u)
{
	int		length;
	int		count;
	int		precision;
	char	*s;

	if (u == 0 && fs->precision == 0)
		return (ft_print_spaces(fs->width));
	s = ft_utoa(u);
	if (!s)
		return (0);
	count = ft_strlen(s);
	precision = fs->precision - count > 0 ? fs->precision - count : 0;
	length = process_uint2(fs, count, precision, s);
	free(s);
	return (length);
}
