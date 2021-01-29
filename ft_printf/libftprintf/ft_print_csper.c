/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_csper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falkonrae <falkonrae@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:13:44 by vjacob            #+#    #+#             */
/*   Updated: 2021/01/29 23:44:33 by falkonrae        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_space_zero(int count, int c)
{
	int i;

	i = 0;
	if (count <= 0)
		return (0);
	while (i < count)
	{
		if (c)
			ft_putchar('0');
		else
			ft_putchar(' ');
		i++;
	}
	return (count);
}

// int		ft_print_space(int count)
// {
// 	int i;

// 	i = 0;
// 	while (i < count)
// 	{
// 		ft_putchar(' ');
// 		i++;
// 	}
// 	return (count);
// }

int		proc_string(t_list *flags, char *s)
{
	int len;
	int kol;

	len = 0;
	kol = ft_strlen(s);
	if (flags->dot >= 0 && flags->dot < kol)
		kol = flags->dot;
	if (flags->zero && flags->width)
		len += ft_space_zero(flags->width - kol, 1);
	else if (!flags->minus && flags->width)
		len += ft_space_zero(flags->width - kol, 0);
	len += ft_putstr_count(s, kol);
	if (flags->minus)
		len += ft_space_zero(flags->width - kol, 0);
	return (len);
}

int		proc_percent(t_list *flags)
{
	int len;

	len = 0;
	// if (!flags->minus && flags->zero)
	// 	len += ft_space_zero(flags->width - 1, 1) + ft_putchar('%');
	// else if (flags->minus)
	// 	len += ft_putchar('%') + ft_space_zero(flags->width - 1, 0);
	// else if (!flags->width)
	// 	len += ft_putchar('%');
	// else
	// 	len += ft_space_zero(flags->width - 1, 0) + ft_putchar('%');
	// return (len);
		if (flags->zero && flags->width)
		len += ft_space_zero(flags->width - 1, 1);
	else if (!flags->minus && flags->width)
		len += ft_space_zero(flags->width - 1, 0);
	len += ft_putchar('%');
	if (flags->minus)
		len += ft_space_zero(flags->width - 1, 0);
	return (len);
}

int		proc_char(t_list *flags, char c)
{
	int len;

	len = 0;
	if (flags->minus)
		len += ft_putchar(c) + ft_space_zero(flags->width - 1, 0);
	if (!flags->minus)
		len += ft_space_zero(flags->width - 1, 0) + ft_putchar(c);
	return (len);
}
