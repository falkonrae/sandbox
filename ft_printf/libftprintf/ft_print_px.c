/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_px.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacob <vjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:13:44 by vjacob            #+#    #+#             */
/*   Updated: 2021/01/30 19:33:51 by vjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		i_count(unsigned long i)
{
	int count;

	if (!i)
		return (0);
	count = 0;
	while (i)
	{
		i /= 16;
		count++;
	}
	return (count);
}

int		ft_hex(unsigned long p, char **s)
{
	int		count;
	int		i;
	char	hex;

	count = i_count(p);
	if (!(*s = malloc((count + 1) * sizeof(char))))
		return (-1);
	if (p == 0)
		count = 1;
	(*s)[count] = '\0';
	i = count - 1;
	while (i >= 0)
	{
		hex = p % 16;
		if (hex < 10)
			(*s)[i] = hex + 48;
		else
			(*s)[i] = hex + 87;
		p /= 16;
		i--;
	}
	return (count);
}

int		ft_hex_cap(unsigned long p, char **s)
{
	int		count;
	int		i;
	char	hex;

	count = i_count(p);
	if (!(*s = malloc((count + 1) * sizeof(char))))
		return (-1);
	if (p == 0)
		count = 1;
	(*s)[count] = '\0';
	i = count - 1;
	while (i >= 0)
	{
		hex = p % 16;
		if (hex < 10)
			(*s)[i] = hex + 48;
		else
			(*s)[i] = hex + 55;
		p /= 16;
		i--;
	}
	return (count);
}

int		proc_pointer(t_list *flags, unsigned long i)
{
	int		len;
	char	*str;
	int		count;
	int		dot;

	dot = 0;
	len = 0;
	count = ft_hex(i, &str);
	if (i == 0 && !flags->dot)
		return (len += ft_space_zero(flags->width - 2, 0) + ft_putstr("0x"));
	if (flags->dot > 0 && count < flags->dot)
		dot = flags->dot - count;
	if (flags->minus)
		len += ft_putstr("0x") + ft_space_zero(dot, 1) + ft_putstr(str)
			+ ft_space_zero(flags->width - dot - count - 2, 0);
	else if (flags->zero && flags->dot == -1)
		len += ft_putstr("0x") + ft_space_zero(flags->width - count, 1)
			+ ft_putstr(str);
	else
		len += ft_space_zero(flags->width - dot - count - 2, 0)
			+ ft_putstr("0x") + ft_space_zero(dot, 1) + ft_putstr(str);
	free(str);
	return (len);
}

int		proc_hex(t_list *flags, unsigned long i, int cap)
{
	int		len;
	char	*str;
	int		count;
	int		dot;

	dot = 0;
	len = 0;
	if (i == 0 && flags->dot == 0)
		return (ft_space_zero(flags->width, 0));
	if (!cap)
		count = ft_hex(i, &str);
	else
		count = ft_hex_cap(i, &str);
	if (flags->dot > 0 && count < flags->dot)
		dot = flags->dot - count;
	if (flags->minus)
		len += ft_space_zero(dot, 1) + ft_putstr(str)
			+ ft_space_zero(flags->width - dot - count, 0);
	else if (flags->zero && flags->dot == -1)
		len += ft_space_zero(flags->width - count, 1) + ft_putstr(str);
	else
		len += ft_space_zero(flags->width - dot - count, 0)
			+ ft_space_zero(dot, 1) + ft_putstr(str);
	free(str);
	return (len);
}
