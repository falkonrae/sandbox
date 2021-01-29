/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_px.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falkonrae <falkonrae@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:13:44 by vjacob            #+#    #+#             */
/*   Updated: 2021/01/29 23:57:31 by falkonrae        ###   ########.fr       */
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

	len = 0;
	count = ft_hex(i, &str);
	// printf("\ncount = %d\n", count);
	//printf("width = %d\n", flags->width);
	// if (flags->dot > 0)
	// 	len += ft_putstr("0x") + ft_space_zero(flags->dot - count, 1)
	// 		+ ft_putstr(str);
	// else if (flags->minus)
	// 	len += ft_putstr("0x") + ft_putstr(str)
	// 		+ ft_space_zero(flags->width - count - 2, 0);
	// else if (flags->zero)
	// 	len += ft_putstr("0x") + ft_space_zero(flags->width - count - 2, 1)
	// 		+ ft_putstr(str);
	// else
	// 	len += ft_space_zero(flags->width - count - 2, 0) + ft_putstr("0x")
	// 		+ ft_putstr(str);
	if (flags->zero && flags->width) // проверить на ноль перед 0х
		len += ft_space_zero(flags->width - count - 2, 1);
	else if (!flags->minus && flags->width)
		len += ft_space_zero(flags->width - count - 2, 0);
	len += ft_putstr("0x") + ft_putstr(str);
	if (flags->minus)
		len += ft_space_zero(flags->width - count - 2, 0);
	return (len);
	free(str);
	return (len);
}

int		proc_hex(t_list *flags, unsigned long i, int cap)
{
	int		len;
	char	*str;
	int		count;

	len = 0;
	if (!cap)
		count = ft_hex(i, &str);
	if (cap)
		count = ft_hex_cap(i, &str);
	if (flags->dot > 0)
		len += ft_space_zero(flags->dot - count, 1) + ft_putstr(str);
	else if (flags->minus)
		len += ft_putstr(str) + ft_space_zero(flags->width - count, 0);
	else if (flags->zero)
		len += ft_space_zero(flags->width - count, 1)
			+ ft_putstr(str);
	else
		len += ft_space_zero(flags->width - count, 0) + ft_putstr(str);
	free(str);
	return (len);
}


//	printf("\ni = %ld\n", i);
//   printf("\ncount = %d\n", count);
//   printf("width = %d\n", flags->width);
//  printf("dot = %d\n", flags->dot);
//   printf("zero = %d\n", flags->zero);
//     printf("minus = %d\n", flags->minus);
// printf("str = |%s|\n", str);