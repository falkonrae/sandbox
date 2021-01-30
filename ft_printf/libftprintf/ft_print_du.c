/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_du.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacob <vjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:13:44 by vjacob            #+#    #+#             */
/*   Updated: 2021/01/30 19:33:02 by vjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		print_minus(int minus)
{
	if (minus)
		ft_putchar('-');
	else
		return (0);
	return (1);
}

int		process(int minus, int dot, char *s, t_list *flags)
{
	int len;
	int kol;

	len = 0;
	kol = ft_strlen(s);
	if (flags->minus)
		len += (print_minus(minus) + ft_space_zero(dot, 1)
		+ ft_putstr(s + minus) + ft_space_zero(flags->width - dot - kol, 0));
	else if (flags->zero && flags->dot == -1)
		len += (print_minus(minus) + ft_space_zero(flags->width - kol, 1)
			+ ft_putstr(s + minus));
	else
		len += (ft_space_zero(flags->width - dot - kol, 0) + print_minus(minus)
		+ ft_space_zero(dot, 1) + ft_putstr(s + minus));
	return (len);
}

int		proc_int(t_list *flags, int i)
{
	int		len;
	int		kol;
	int		dot;
	char	*s;
	int		minus;

	len = 0;
	minus = 0;
	if (i < 0)
		minus = 1;
	if (i == 0 && flags->dot == 0)
		return (ft_space_zero(flags->width, 0));
	if (!(s = ft_itoa(i)))
		return (0);
	kol = ft_strlen(s);
	if (i >= 0)
		dot = flags->dot - kol > 0 ? flags->dot - kol : 0;
	else
		dot = flags->dot - kol + 1 > 0 ? (flags->dot - kol + 1) : 0;
	len = process(minus, dot, s, flags);
	free(s);
	return (len);
}

int		proc_uint(t_list *flags, unsigned int u)
{
	int		len;
	int		kol;
	int		dot;
	char	*s;

	dot = 0;
	len = 0;
	if (u == 0 && flags->dot == 0)
		return (ft_space_zero(flags->width, 0));
	s = ft_utoa(u);
	if (!s)
		return (0);
	kol = ft_strlen(s);
	if (flags->dot - kol > 0)
		dot = flags->dot - kol;
	if (flags->minus)
		len += ft_space_zero(dot, 1) + ft_putstr(s)
			+ ft_space_zero(flags->width - dot - kol, 0);
	else if (flags->zero && flags->dot == -1)
		len += ft_space_zero(flags->width - kol, 1) + ft_putstr(s);
	else
		len += ft_space_zero(flags->width - dot - kol, 0) +
				ft_space_zero(dot, 1) + ft_putstr(s);
	free(s);
	return (len);
}
