/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_du.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falkonrae <falkonrae@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:13:44 by vjacob            #+#    #+#             */
/*   Updated: 2021/01/30 00:31:09 by falkonrae        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	process_int_positive(t_list *flags, int count, int dot, char *s)
{
	if (flags->minus)
		return (ft_print_zero(dot) + ft_putstr(s) +
				ft_print_space(flags->width - dot - count));
	else if (flags->zero && flags->dot == -1)
		return (ft_print_zero(flags->width - count) + ft_putstr(s));
	else
		return (ft_print_space(flags->width - dot - count) +
				ft_print_zero(dot) + ft_putstr(s));zzzzzzz
}

int	process_int_negative(t_list *flags, int count, int dot, char *s)
{
	if (flags->minus)
		return (ft_putchar('-') + ft_print_zero(dot) +
				ft_putstr(s + 1) +
				ft_print_space(flags->width - dot - count));
	else if (flags->zero && flags->dot == -1)
		return (ft_putchar('-') + ft_print_zero(flags->width - count)
				+ ft_putstr(s + 1));
	else
		return (ft_print_space(flags->width - dot - count) +
				ft_putchar('-') + ft_print_zero(dot) +
				ft_putstr(s + 1));
}

int	proc_int(t_list *flags, int i)
{
	int		length;
	int		count;
	int		dot;
	char	*s;

	if (i == 0 && flags->dot == 0)
		return (ft_space_zero(flags->width, 0));
	s = ft_itoa(i);
	if (!s)
		return (0);
	count = ft_strlen(s);
	if (i >= 0)
		dot = flags->dot - count > 0 ? flags->dot - count : 0;
	else
		dot = flags->dot - count + 1 > 0 ? (flags->dot - count + 1) : 0;
	length = i >= 0 ? process_int_positive(flags, count, dot, s)
					: process_int_negative(flags, count, dot, s);
	free(s);
	return (length);
}

// int	ft_print_zeros(int count)
// {
// 	int i;

// 	if (count <= 0)
// 		return (0);
// 	i = 0;
// 	while (i < count)
// 	{
// 		ft_putchar('0');
// 		i++;
// 	}
// 	return (count);
// }

// int	process_uint2(t_list *flags, int count, int dot, char *s)
// {
// 	if (flags->minus)
// 		return (ft_print_zeros(dot) + ft_putstr(s) +
// 				ft_print_space(flags->width - dot - count));
// 	else if (flags->zero && flags->dot == -1)
// 		return (ft_print_zeros(flags->width - count) + ft_putstr(s));
// 	else
// 		return (ft_print_space(flags->width - dot - count) +
// 				ft_print_zeros(dot) + ft_putstr(s));
// }

// int	process_uint(t_list *flags, unsigned int u)
// {
// 	int		length;
// 	int		count;
// 	int		dot;
// 	char	*s;

// 	if (u == 0 && flags->dot == 0)
// 		return (ft_print_space(flags->width));
// 	s = ft_utoa(u);
// 	if (!s)
// 		return (0);
// 	count = ft_strlen(s);
// 	dot = flags->dot - count > 0 ? flags->dot - count : 0;
// 	length = process_uint2(flags, count, dot, s);
// 	free(s);
// 	return (length);
// }
