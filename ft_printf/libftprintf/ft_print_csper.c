/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_csper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacob <vjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:13:44 by vjacob            #+#    #+#             */
/*   Updated: 2021/01/29 18:21:15 by vjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_print_zero(int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		ft_putchar('0');
		i++;
	}
	return (count);
}

int		ft_print_space(int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		ft_putchar(' ');
		i++;
	}
	return (count);
}

int		proc_string(t_list *flags, char *s)
{
	int len;
	int kol;

	len = 0;
	kol = ft_strlen(s);
	if (flags->dot >= 0 && flags->dot < kol)
		kol = flags->dot;
	if (flags->zero && flags->width)
		len += ft_print_zero(flags->width - kol) + ft_putstr_count(s, kol);
	else if (!flags->minus && flags->width)
		len += ft_print_space(flags->width - kol);
	printf("kol = %d\n", kol);
	printf("flags->width = %d\n", flags->width);
	len += ft_putstr_count(s, kol);
	if (flags->minus)
		len += ft_print_space(flags->width - kol);
	return (len);
}

int		proc_percent(t_list *flags)
{
	int len;

	len = 0;
	if (!flags->minus && flags->zero)
		len += ft_print_zero(flags->width - 1) + ft_putchar('%');
	else if (flags->minus)
		len += ft_putchar('%') + ft_print_space(flags->width - 1);
	else if (!flags->width)
		len += ft_putchar('%');
	else
		len += ft_print_space(flags->width - 1) + ft_putchar('%');
	return (len);
}

int		proc_char(t_list *flags, char c)
{
	int len;

	len = 0;
	if (flags->minus)
		len += ft_putchar(c) + ft_print_space(flags->width - 1);
	if (!flags->minus)
		len += ft_print_space(flags->width - 1) + ft_putchar(c);
	return (len);
}
